#include <assert.h>
#include <iostream>
namespace ztk
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}
		const_iterator begin()const
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}
		const_iterator end()const
		{
			return _finish;
		}

		size_t size()const
		{
			return _finish - _start;
		}

		size_t capacity()const
		{
			return _endofstorage - _start;
		}

		bool empty()
		{
			return _start == _finish;
		}
		bool empty()const
		{
			return _start == _finish;
		}

		vector() = default;
		//v2(v1)
		vector(const vector& other)
		{
			reserve(other.capacity());
			for (auto& e : other)
			{
				push_back(e);
			}
		}
		//例如v1=v2，v2创建并且传递了一份副本过来，然后我们就让自己的三个指针指向这个位置
		vector& operator=(vector<T> other)
		{
			swap(other);
			return *this;
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		~vector()
		{
			delete[] _start;
			_start = nullptr;
			_finish = nullptr;
			_endofstorage = nullptr;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				T* tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0;i < old_size;++i)
					{
						tmp[i] = _start[i];
					}
					delete[]_start;
				}
				_start = tmp;
				_finish = _start + old_size;
				_endofstorage = _start + n;
			}
		}

		//这里给x一个缺省值，使用T val=T()
		void resize(size_t n, T val=T())
		{
			if (n > size())
			{
				reserve(n);
				while (_finish!=_start+n)
				{
					*_finish = val;
					++_finish;
				}
			}
			else
			{
				_finish = _start + n;
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}
			*_finish = x;
			++_finish;
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			assert(pos >= _start);
			if (_finish == _endofstorage)
			{
				//pos会因为reserve原因发生迭代器失效，所以必须更新使用
				size_t len = pos - _start;
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);
				pos = _start + len;
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *(end);
				--end;
			}
			*(pos) = x;
			++_finish;
			return pos;
		}

		iterator find(const T& x)
		{
			auto it = _start;
			while (it != _finish)
			{
				if (*it == x)
				{
					return it;
				}
				++it;
			}
			return nullptr;
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}
		const T& operator[](size_t i)const
		{
			assert(i < size());
			return _start[i];
		}

		void pop_back()
		{
			assert(!empty());
			--_finish;
		}
		void clear()
		{
			_finish = _start;
		}

		iterator erase(iterator pos)
		{
			assert(pos < _finish);
			assert(pos >= _start);

			iterator p = pos+1;
			while (p != _finish)
			{
				*(p-1) = *p;
				++p;
			}
			--_finish;
			return pos;
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _endofstorage = nullptr;
	};
}
