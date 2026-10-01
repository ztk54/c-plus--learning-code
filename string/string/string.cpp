#include "string.h"

namespace ztk
{
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

	void string::append(const char* s)
	{
		size_t len = max(_size + strlen(s) + 1, 2 * _capacity);
		if (len > _capacity)
		{
			reserve(len);
		}
		memcpy(_str + _size, s, strlen(s) + 1);
		_size += strlen(s);
	}

	void string::append(const string& s)
	{
		size_t len = max(_size + s._size + 1, 2 * _capacity);
		if (len > _capacity)
		{
			reserve(len);
		}
		memcpy(_str + _size,s._str , s._size + 1);
		_size += s._size;
	}

	ostream& operator<<(ostream& out, const string& str)
	{
		for (size_t i = 0;i < str._size;i++)
		{
			out << str[i];
		}
		return out;
	}
	void test1()
	{
		string Date="!!!";
		string s = "nihao";
		cout << Date.capacity() << Date.size() << Date.c_str() << endl;
		cout << s.capacity() << s.size() << s.c_str() << endl;

		cout << "empty: [" << Date << "] size=" << Date.size()
			<< " capacity=" << Date.capacity() << '\n';
		cout << "text: [" << s << "] size=" << s.size()
			<< " capacity=" << s.capacity() << '\n';

		s.append(" world");
		cout << "text: [" << s << "] size=" << s.size()
			<< " capacity=" << s.capacity() << '\n';

		s.append(Date);		
		cout << "text: [" << s << "] size=" << s.size()
			<< " capacity=" << s.capacity() << '\n';
	}
}