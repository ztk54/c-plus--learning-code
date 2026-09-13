#include <iostream>
using namespace std;

//class A 
//{ public: 
//    A() { cout << "A()" << endl; } 
//    ~A() { cout << "~A()" << endl; } 
//};
//
//A g;                     // 程序开始
//int main()
//{
//    A a1;
//    {
//        A a2;
//    }                    // a2 出作用域就析构
//    static A s;
//    return 0;            // a1 析构，然后 s 析构，最后 g 析构
//}

//class Date
//{
//public:
//	Date(int year = 2026, int month = 9, int day = 13)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

class Date
{
public:
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};