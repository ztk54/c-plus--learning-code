#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
public:
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
