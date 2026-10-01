#include <iostream>
#include <string>
#include <cstring>
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


//int main()
//{
//	string note;
//	string original_topic = "Date class";
//	string current_topic(original_topic);
//
//	string before_revision = current_topic;
//	current_topic = "first";
//
//	before_revision = current_topic;
//	current_topic = "two";
//
//	before_revision = current_topic;
//	current_topic = "vector";
//	string div(20, '-');
//
//	cout << "请填写备注" << endl;
//	getline(cin, note);
//	if (!note.empty())
//	{
//		string edited_note(note);
//		edited_note.push_back('!');
//		string append_text = "|tomorrow";
//		edited_note.append(append_text);
//		edited_note.insert(0, "[todo]");
//		cout << "原备注：" << note << endl << "第一次编辑后备注: " << edited_note << endl;
//
//		edited_note.replace(0, 6, "[done]");
//		edited_note.erase(edited_note.size() - append_text.size(), append_text.size());
//		string final = edited_note;
//		edited_note.clear();
//		cout << edited_note.empty() << endl;
//
//		size_t pos1 = final.find('[');
//		size_t pos2 = final.find(']');
//		string status = final.substr(pos1 + 1, pos2 - pos1 - 1);
//		string main_text = final.substr(pos2 + 1);
//		cout << "状态：" << status << ' ' << "正文：" << main_text << endl;
//
//		size_t pos3 = main_text.find("Date");
//		if (pos3 == string::npos)
//		{
//			cout << "没有找到" << endl;
//		}
//		else
//		{
//			cout << "起始位置" << pos3 << endl;
//		}
//
//		cout << "最终结果：" << final << endl;
//	}
//	else
//	{
//		cout << "还没有填写备注" << endl;
//	}
//
//	before_revision = current_topic;
//	cout << "请输入当前主题" << endl;
//	getline(cin, current_topic);
//	string preview(current_topic);
//	if (!preview.empty())
//	{
//		cout << "首字符:" << preview.front() << endl;
//		cout << "尾字符:" << preview.back() << endl;
//		preview[0] = '*';
//	}
//	else
//	{
//		cout << "没有可预览的主题" << endl;
//	}
//
//	int count = 0;
//	//下标＋[]
//	for (size_t i = 0;i < preview.size();i++)
//	{
//		if (preview[i] == ' ')
//		{
//			++count;
//			preview[i] = '_';
//		}
//	}
//	//auto范围for
//	for (char& ch : preview)
//	{
//		if (ch == ' ')
//		{
//			++count;
//			ch = '_';
//		}
//	}
//	//迭代器
//	for (auto it = preview.begin();it != preview.end();++it)
//	{
//		if (*it == ' ')
//		{
//			++count;
//			*it = '_';
//		}
//	}
//	string prexic = "[主题]";
//	string display = prexic + current_topic;
//	display += "|预览";
//	display += preview;
//	cout << display << endl;
//	if (current_topic == original_topic)
//	{
//		cout << "与原始主题相同" << endl;
//	}
//	else
//	{
//		cout << "不相同" << endl;
//	}
//	cout << preview << endl;
//
//	cout << current_topic.size() << endl;
//	string sub1(original_topic, 0, 4);
//	string sub2(original_topic, 5);
//
//	cout << div << endl;
//	cout << original_topic << ' ' << before_revision << ' ' << current_topic << ' ' << endl;
//	cout << div << endl;
//	cout << sub1 << ' ' << sub2 << endl;
//
//	//int day;
//	//cin >> day;
//	//int c;
//	//while (( c = getchar()) != '\n'&&c!=EOF)
//	//{
//	//}
//	//getline(cin, note);
//
//	//int day;
//	//cin >> day;
//	//string tmp;
//	//getline(cin, tmp);
//	//getline(cin, note);
//
//}

//int main()
//{
	//string keyboard = "Date";
	//string status1 = "[done]";
	//string status2 = "[todo]";
	//string topic;
	//cout << "请输入对应主题" << endl;
	//getline(cin, topic);
	//string remark;
	//cout << "请输入对应备注" << endl;
	//getline(cin, remark);

	//string final(status1);
	//final += topic;
	//final.push_back('|');
	//final += remark;

	//size_t pos_status1 = final.find('[');
	//size_t pos_status2 = final.find(']');
	//size_t pos_remark = final.rfind('|');
	//if (pos_remark == string::npos)
	//{
	//	cout << "格式输入有误" << endl;
	//}
	//string real_status = final.substr(pos_status1 + 1, pos_status2 - pos_status1 - 1);
	//string real_topic = final.substr(pos_status2 + 1, pos_remark - pos_status2 - 1);
	//string real_remark = final.substr(pos_remark + 1);
	//cout << "状态：" << real_status << endl;
	//cout << "主题：" << real_topic << endl;
	//cout << "备注" << real_remark << endl;

	//size_t next_pos_keyboard = 0;
	//int count = 0;
	//while (1)
	//{
	//	size_t current_pos = real_remark.find(keyboard, next_pos_keyboard);
	//	if (current_pos == string::npos)
	//	{
	//		break;
	//	}
	//	else
	//	{
	//		cout << "Date class at" << current_pos << endl;
	//		next_pos_keyboard = current_pos + keyboard.size();
	//		count++;
	//	}
	//}
	//if (count == 0)
	//{
	//	cout << "未找到keyboard" << endl;
	//}

	//string preview_remark(real_remark);
	//cout << "preview_remark.size():" << preview_remark.size() << endl;
	//cout << "preview_remark.capacity():" << preview_remark.capacity() << endl;
	//preview_remark.reserve(40);
	//cout << "preview_remark.size():" << preview_remark.size() << endl;
	//cout << "preview_remark.capacity():" << preview_remark.capacity() << endl;
	//size_t original_preview_size = preview_remark.size();
	//preview_remark.append("|next");
	//preview_remark.resize(original_preview_size);
	//preview_remark.resize(original_preview_size + 3, '.');
	//cout << preview_remark << endl;

	//string s("Date\0todo", 9);
	//s.append(" class");
	//cout << s.size() << endl;
	//cout << strlen(s.c_str()) << endl;
	//cout << s.substr(5) << endl;

	//const char* p = s.c_str();
	//s.reserve(s.capacity() + 1);
	//p = s.c_str();
	//cout << strlen(p) << endl;

	//string s;
	//cout << "请以主题|次数的格式输入" << endl;
	//getline(cin, s);
	//size_t pos = s.find('|');
	//if (pos == string::npos)
	//{
	//	cout << "输入不符合要求" << endl;
	//}
	//else
	//{
	//	size_t used = 0;
	//	string count = s.substr(pos + 1);
	//	s.erase(pos + 1);
	//	int tmp1 = stoi(count,&used);
	//	if (used != count.size())
	//	{
	//		cout << "次数只能为整数" << endl;
	//	}
	//	else
	//	{
	//		tmp1++;
	//		string tmp2 = to_string(tmp1);
	//		s += tmp2;
	//		cout << s << endl;
	//	}
	//}
//}


int main()
{
	int flag = 1;
	string s;
	cout << "请以[状态]|主题|备注|次数的形式输入" << endl;
	getline(cin, s);
	size_t left_frame_pos1 = s.find('[');
	size_t right_frame_pos2 = s.find(']');
	y7size_t first_line_pos1 = s.find('|',right_frame_pos2+1);
	size_t two_line_pos2 = s.find('|',first_line_pos1+1);
	size_t three_line_pos3 = s.rfind('|');

	if (left_frame_pos1 == string::npos || right_frame_pos2 == string::npos || first_line_pos1 == string::npos || two_line_pos2 == string::npos || three_line_pos3 == string::npos||!(two_line_pos2 < three_line_pos3))
	{
		cout << "您的输入有误" << endl;
	}
	else
	{
		string status = s.substr(left_frame_pos1 + 1, right_frame_pos2 - left_frame_pos1 - 1);
		string topic = s.substr(first_line_pos1 + 1, two_line_pos2 - first_line_pos1 - 1);
		string remark = s.substr(two_line_pos2 + 1, three_line_pos3 - two_line_pos2 - 1);
		string count = s.substr(three_line_pos3 + 1);
		//cout << status << endl << topic << endl << remark << endl << count << endl;
		cout <<"状态：" << status << endl;
		cout << "主题：" << topic << endl;
		cout << "备注：" << remark << endl;
		s.erase(three_line_pos3 + 1);
		size_t used = 0;
		int tmp = stoi(count, &used);
		if (used != count.size())
		{
			cout << "次数只能为整数" << endl;
			flag = 0;
		}
		else
		{
			tmp++;
			string tmp2 = to_string(tmp);
			s += tmp2;
		}

		string keyboard;
		cout << "请输入关键词" << endl;
		getline(cin, keyboard);
		size_t next = 0;
		int record = 0;
		while (true)
		{
			if (keyboard.empty())
			{
				cout << "关键词为空" << endl;
				record = 1;
				break;
			}
			size_t pos=remark.find(keyboard, next);
			if (pos == string::npos)
			{
				break;
			}
			record++;
			if (record == 1)
			{
				cout << "关键词在备注中的位置: " << endl;
			}
			cout << pos << ' ';
			next = pos + keyboard.size();
		}
		if (record == 0)
		{
			cout << "未找到关键词" << endl;
		}
		if(flag==1)cout << "更新后的记录：" << s << endl;
	}
}