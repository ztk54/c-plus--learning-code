#include "string.h"

namespace ztk
{
	const size_t string::npos = -1;
	string::string()
		//初始化列表要使用括号初始化
		:_str(new char[1])
		, _size(0)
		, _capacity(0)
	{
		_str[0] = '\0';
	}

	string::string(const char* str)
		:_size(strlen(str))
	{
		_capacity = _size;
		_str = new char[_size + 1];
		memcpy(_str, str, _size + 1);
	}

	string::~string()
	{
		delete[] _str;
		_str = nullptr;
		_capacity = 0;
		_size = 0;
	}

	size_t string::size()
	{
		return _size;
	}

	size_t string::capacity()
	{
		return _capacity;
	}

	const char* string::c_str()
	{
		return _str;
	}

	//深拷贝
	string::string(const string& other)
	{
		_size = other._size;
		_capacity = other._capacity;
		_str = new char[_capacity + 1];
		memcpy(_str, other._str, _size + 1);
	}

	char& string::operator[](size_t pos)
	{
		return _str[pos];
	}

	const char& string::operator[](size_t pos) const
	{
		return _str[pos];
	}

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* str = new char[n + 1];
			memcpy(str, _str, _size + 1);
			delete[] _str;
			_str = str;
			str = nullptr;
			_capacity = n;
		}
	}

	void string::push_back(char c)
	{
		if (_size >= _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
			reserve(newcapacity);
		}
		_str[_size++] = c;
		_str[_size] = '\0';
	}

	//void string::append(const char* s)
	//{
	//	size_t len = strlen(s);
	//	if (len + _size > _capacity)
	//	{
	//		size_t newcapacity = len + _size < 2 * _capacity ? 2 * _capacity : len + _size;
	//		reserve(newcapacity);
	//	}
	//	memcpy(_str + _size, s, len + 1);
	//	_size += len;
	//}

	//先保存独立的一份，再复用对象版追加，这样扩容就不会让追加来源失效
	void string::append(const char* s)
	{
		string source(s);
		append(source);
	}

	void string::append(const string& s)
	{
		size_t len = s._size;
		if (len + _size > _capacity)
		{
			size_t newcapacity = len + _size < 2 * _capacity ? 2 * _capacity : len + _size;
			reserve(newcapacity);
		}
		//这里使用memcpy无法处理自追加的问题
		//memcpy(_str + _size, s._str, len + 1);
		memmove(_str + _size, s._str, len + 1);
		_size += len;
	}

	string& string::operator+=(char c)
	{
		push_back(c);
		return *this;
	}

	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}

	string& string::operator+=(const string& str)
	{
		append(str);
		return *this;
	}

	string::iterator string::begin()
	{
		return _str;
	}

	string::iterator string::end()
	{
		return _str + _size;
	}

	string::const_iterator string::begin() const
	{
		return _str;
	}

	string::const_iterator string::end() const
	{
		return _str + _size;
	}

	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		if (_size >= _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
			reserve(newcapacity);
		}

		//强转防止end为-1发生整形提升变为最大值
		//int end = _size;
		//while (end >= (int)pos)
		//{
		//	_str[end + 1] = _str[end];
		//	end--;
		//}

		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			end--;
		}

		_str[pos] = ch;
		_size++;
	}

	void string::erase(size_t pos, size_t len)
	{
		assert(pos <= _size);
		if (len == npos || len > (_size - pos))
		{
			_size = pos;
			_str[pos] = '\0';
		}
		else
		{
			size_t i = pos + len;
			memmove(_str + pos, _str + i, _size - i + 1);
			_size -= len;
		}
	}

	void string::clear()
	{
		_size = 0;
		_str[0] = '\0';
	}

	size_t string::find(char ch, size_t pos) const
	{
		if (pos > _size)
		{
			return npos;
		}
		size_t p = pos;
		while (p < _size)
		{
			if (_str[p] == ch)
			{
				return p;
			}
			p++;
		}
			return npos;
	}

	size_t string::find(const char* text, size_t pos) const
	{
		if (pos > _size)
		{
			return npos;
		}
		if (strlen(text)==0)
		{
			return pos;
		}
		size_t p1 = pos, p2 = 0, p3 = 0;
		while (p1 < _size)
		{
			p3 = 0;
			p2 = p1;
			while (p3 < strlen(text))
			{
				if (text[p3] == _str[p2])
				{
					p2++;
					p3++;
				}
				else
				{
					break;
				}
			}
			if (p3 == strlen(text))
			{
				return p1;
			}
			p1++;
		}
		return npos;
	}

	//这里会使用深拷贝
	string string::substr(size_t pos, size_t len) const
	{
		if (len == npos || len >= _size)
		{
			len = _size - pos;
		}
		string ret;
		ret.reserve(len);
		for (size_t i = 0;i < len;i++)
		{
			ret += _str[pos + i];
		}
		return ret;
	}

	string& string::operator=(const string& other)
	{
		if (this == &other)
		{
			return *this;
		}
		char* tmp = new char[other._capacity + 1];
		memmove(tmp, other._str, other._size + 1);
		delete[] _str;
		_str = tmp;
		_size = other._size;
		_capacity = other._capacity;
		return *this;
	}

	ostream& operator<<(ostream& out, const string& str)
	{
		for (size_t i = 0;i < str._size;i++)
		{
			out << str[i];
		}
		return out;
	}
	istream& operator>>(istream& in, string& str)
	{
		str.clear();
		char ch = in.get();
		while (ch != ' ' || ch != '\n')
		{
			str += ch;
			ch = in.get();
		}
		return in;
	}
	void test1()
	{
		//string Date = "hello";
		//string s = "nihao";
		//cout << Date.capacity() << Date.size() << Date.c_str() << endl;
		//cout << s.capacity() << s.size() << s.c_str() << endl;

		//cout << "empty: [" << Date << "] size=" << Date.size()
		//	<< " capacity=" << Date.capacity() << '\n';
		//cout << "text: [" << s << "] size=" << s.size()
		//	<< " capacity=" << s.capacity() << '\n';

		//s.append(" world");
		//cout << "text: [" << s << "] size=" << s.size()
		//	<< " capacity=" << s.capacity() << '\n';

		//string tmp(s);
		//tmp = Date;
		//tmp += "123456";
		//cout << "text: [" << s << "] size=" << s.size()
		//	<< " capacity=" << s.capacity() << '\n';

		//tmp += "111111";
		//cout << "text: [" << tmp << "] size=" << tmp.size()
		//	<< " capacity=" << tmp.capacity() << '\n';

		//for (string::iterator it = tmp.begin();it != tmp.end();it++)
		//{
		//	cout << *it << ' ';
		//}

		string s = "Date";
		const char* text = "";
		if (s.find(text,5) == string::npos)
		{
			cout << "未找到" << endl;
		}
		else
		{
			cout << s.find(text,5) << endl;
		}
	}
}