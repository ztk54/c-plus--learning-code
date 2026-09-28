#include "string.h"

namespace ztk
{
	string::string()
		:_str(nullptr)
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
	
	ostream& operator<<(ostream& out, const string& str)
	{
		for (size_t i = 0;i < str._size())
		{

		}
	}
	void test1()
	{
		string Date;
		string s = "nihao";
		cout << Date.capacity() << Date.size() << Date.c_str() << endl;
		cout << s.capacity() << s.size() << s.c_str() << endl;
	}
}