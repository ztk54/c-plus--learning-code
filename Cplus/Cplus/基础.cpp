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
	if (!note.empty())
	{
		size_t tem = note.size();
		string edited_note(note);
		edited_note.push_back('!');
		edited_note.append("|tomorrow");
		edited_note.insert(0, "[todo]");
		cout << "原备注：" << note << endl << "第一次编辑后备注: " << edited_note << endl;

		edited_note.replace(0, 6, "[done]");
		edited_note.erase(6, tem);
		string final = edited_note;
		edited_note.clear();
		cout << "最终结果：" << final << endl;
	}
	else
	{
		cout << "还没有填写备注" << endl;
	}

	before_revision = current_topic;
	cout << "请输入当前主题" << endl;
	getline(cin, current_topic);
	string preview(current_topic);
	if (!preview.empty())
	{
		cout << "首字符:" << preview.front() << endl;
		cout << "尾字符:" << preview.back() << endl;
		preview[0] = '*';
	}
	else
	{
		cout << "没有可预览的主题" << endl;
	}

	int count = 0;
	//下标＋[]
	for (size_t i = 0;i < preview.size();i++)
	{
		if (preview[i] == ' ')
		{
			++count;
			preview[i] = '_';
		}
	}
	//auto范围for
	for (char& ch : preview)
	{
		if (ch == ' ')
		{
			++count;
			ch = '_';
		}
	}
	//迭代器
	for (auto it = preview.begin();it != preview.end();++it)
	{
		if (*it == ' ')
		{
			++count;
			*it = '_';
		}
	}
	string prexic = "[主题]";
	string display = prexic + current_topic;
	display += "|预览";
	display += preview;
	cout << display << endl;
	if (current_topic == original_topic)
	{
		cout << "与原始主题相同" << endl;
	}
	else
	{
		cout << "不相同" << endl;
	}
	cout << preview << endl;
	
	cout << current_topic.size() << endl;
	string sub1(original_topic, 0, 4);
	string sub2(original_topic, 5);

	cout << div << endl;
	cout << original_topic << ' ' << before_revision << ' ' << current_topic << ' ' << endl;
	cout << div << endl;
	cout << sub1 <<' ' << sub2 << endl;

	//int day;
	//cin >> day;
	//int c;
	//while (( c = getchar()) != '\n'&&c!=EOF)
	//{
	//}
	//getline(cin, note);

	//int day;
	//cin >> day;
	//string tmp;
	//getline(cin, tmp);
	//getline(cin, note);

}