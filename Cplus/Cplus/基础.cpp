#include <iostream>
#include <string>
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

//class Date
//{
//public:
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};


int main()
{
	string note;
	string original_topic = "Date class";
	string current_topic(original_topic);

	string before_revision = current_topic;
	current_topic = "first";

	before_revision = current_topic;
	current_topic = "two";

	before_revision = current_topic;
	current_topic = "vector";
	string div(20, '-');

	cout << "请填写备注" << endl;
	getline(cin, note);
	if (note.empty())
	{
		cout << "还没有填写备注" << endl;
	}
	else
	{
		cout << "备注：" << note << endl;
	}

	before_revision = current_topic;
	cout << "请输入当前主题" << endl;
	getline(cin, current_topic);

	
	cout << current_topic.size() << endl;
	string sub1(original_topic, 0, 4);
	string sub2(original_topic, 5);

	cout << div << endl;
	cout << original_topic << ' ' << before_revision << ' ' << current_topic << ' ' << endl;
	cout << div << endl;
	cout << sub1 <<' ' << sub2 << endl;
}