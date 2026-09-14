#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
public:
    // 友元：让全局的 << >> 能访问私有成员
    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& in, Date& d);


	Date(int year = 2026, int month = 9, int day = 13);
	void Print();
    int  GetMonthDay(int year, int month);
    bool CheckDate();                    

    Date& operator+=(int day);
    Date  operator+ (int day);
    Date& operator-=(int day);
    Date  operator- (int day);
    int   operator- (const Date& d);

    bool operator==(const Date& d);
    bool operator!=(const Date& d);
    bool operator< (const Date& d);
    bool operator<=(const Date& d);
    bool operator> (const Date& d);
    bool operator>=(const Date& d);

    Date& operator++();                    // 前置++
    Date  operator++(int);                 // 后置++
    Date& operator--();                    // 前置--
    Date  operator--(int);                 // 后置--

private:
	int _year;
	int _month;
	int _day;
    static int monthDayArray[13];
};

ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);