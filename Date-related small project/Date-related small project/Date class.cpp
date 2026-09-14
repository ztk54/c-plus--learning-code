#include "Date class.h"

// static 成员变量必须在类外定义（且不能再写 static）
int Date::monthDayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(int year,int month,int day)
{
	_year = year;
	_month = month;
	_day = day;
}

void Date::Print()
{
	cout << _year << "/" << _month << "/" << _day<<endl;
}

int  Date::GetMonthDay(int year, int month)
{
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
	{
		return 29;
	}
	else
	{
		return monthDayArray[month];
	}
}

bool Date::CheckDate()
{
	if (_year > 0 && _month > 0 && _month <= 12)
	{
		if (_day > 0 && _day <= GetMonthDay(_year, _month))
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

//a+=1类似于这种的，因此a自身会直接发生变化
Date& Date::operator+=(int day)
{
	if(day<0)
	{
		return *this -= -day;
	}
	_day += day;
	while (_day > GetMonthDay(_year,_month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date tem(*this);
	tem += day;
	return tem;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	_day -= day;
	while (day <= 0)
	{
		--_month;//这里必须先对month进行--，因为我们是解位，所以要使用的是上个月的天数
		if (_month == 0)
		{
			_month = 12;
			--_year;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator-(int day)
{
	Date tem(*this);
	tem -= day;
	return tem;
}

int Date::operator-(const Date& d)
{
	Date Max = *this;
	Date Min = d;
	int flag = 1;

	if (Max<Min)
	{
		Max = d;
		Min = *this;
		flag = -1;
	}

	int n = 0;
	while(Max != Min)
	{
		++Min;
		++n;
	}
	return n * flag;
}

bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator!=(const Date& d)
{
	return !(*this==d);
}

bool Date::operator<(const Date& d)
{
	//冗杂版本
	//if (_year < d._year)
	//{
	//	return true;
	//}
	//else if (_year == d._year && _month < d._month)
	//{
	//	return true;
	//}
	//else if (_year == d._year && _month == d._month && _day < d._day)
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}

	if (_year != d._year)  return _year < d._year;
	if (_month != d._month)   return _month < d._month;
	return _day < d._day;
}

bool Date::operator<=(const Date& d)
{
	return *this<d||*this==d;
}

bool Date::operator>(const Date& d)
{
	return !(*this<d);
}

bool Date::operator>=(const Date& d)
{
	return *this>d||*this==d;
}

//前置++返回增加后的自己
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tem(*this);
	*this += 1;
	return tem;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tem(*this);
	*this -= 1;
	return tem;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	cout << "请分别输入年月日" << endl;
	in >> d._year >> d._month >> d._day;
	return in;
}
