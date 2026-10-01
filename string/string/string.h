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
		string(const string& other);

		char& operator[](size_t pos);
		const char& operator[](size_t pos)const;
		void reserve(size_t n);
		void push_back(char c);
		void append(const char* s);
		void append(const string& s);
		string& operator+=(char c);
		string& operator+=(const char* str);
		string& operator+=(const string& str);
		string& operator=(const string& other);

		using iterator = char*;
		using const_iterator = const char*;
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;

		void insert(size_t pos, char ch);
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
	void test1();
	ostream& operator<<(ostream& out, const string& str);
}