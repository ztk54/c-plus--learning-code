#pragma once
#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;
namespace ztk
{
	class string
	{
	friend ostream& operator<<(ostream& out, const string& str);
	public:
		string();
		string(const char* str);
		~string();
		size_t size();
		size_t capacity();
		const char* c_str();

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
	void test1();
	ostream& operator<<(ostream& out, const string& str);
}