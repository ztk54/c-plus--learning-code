#include <iostream>
#include <string>
#include <vector>
using namespace std;

//void menu()
//{
//	string div(30, '-');
//	cout << div << endl;
//	cout << "输入0退出" << endl;
//	cout << "输入1进行预览全部" << endl;
//	cout << "输入2进行查看某一条" << endl;
//	cout << "输入3进行查看首尾两条" << endl;
//	cout << "输入4进行替换" << endl;
//	cout << "输入5进行全部添加前缀" << endl;
//	cout << "输入6进行追加一条记录" << endl;
//	cout << "输入7在指定位置追加一条记录" << endl;
//	cout << "输入8按编号删除一条" << endl;
//	cout << "输入9删除连续一段" << endl;
//	cout << "输入10删除最后一条" << endl;
//	cout << "输入11清空列表" << endl;
//	cout << div << endl;
//}

#include <iostream>
#include <iomanip>
#include <string>

void menu()
{
	const string line(52, '=');
	cout << line << '\n';
	cout << "                  记录管理菜单\n";
	cout << line << '\n';

	cout << "  [查询与显示]\n";
	cout << "  " << setw(2) << 1 << ". 预览全部\n";
	cout << "  " << setw(2) << 2 << ". 查看某一条\n";
	cout << "  " << setw(2) << 3 << ". 查看首尾两条\n";

	cout << "  [修改与添加]\n";
	cout << "  " << setw(2) << 4 << ". 替换\n";
	cout << "  " << setw(2) << 5 << ". 全部添加前缀\n";
	cout << "  " << setw(2) << 6 << ". 追加一条记录\n";
	cout << "  " << setw(2) << 7 << ". 在指定位置追加一条记录\n";

	cout << "  [删除操作]\n";
	cout << "  " << setw(2) << 8 << ". 按编号删除一条\n";
	cout << "  " << setw(2) << 9 << ". 删除连续一段\n";
	cout << "  " << setw(2) << 10 << ". 删除最后一条\n";
	cout << "  " << setw(2) << 11 << ". 清空列表\n";

	cout << "  " << setw(2) << 0 << ". 退出程序\n";
	cout << line << '\n';
	cout << "请选择操作（0-11）> ";
}

int Input_records(vector <string>& Input)
{
	string text;
	while (getline(cin, text))
	{
		if (text.empty())
		{
			break;
		}
		Input.push_back(text);
	}
	if (Input.empty())
	{
		cout << "没有输入学习记录" << endl;
		return 0;
	}
	return -1;
}

void preview(const vector<string>& records)
{
	size_t i = 0;
	cout << "共有" << records.size() << "条记录" << endl;
	for (auto it : records)
	{
		++i;
		cout << i << '.' << it << endl;
	}
}

void view_the_selected(const vector<string>& records)
{
	int i = 0;
	cout << "请输入你想查看第几条记录" << endl;
	cin >> i;
	--i;
	if (i < (int)records.size() && i >= 0)
	{
		cout << records[i] << endl;
	}
	else
	{
		cout << "无效输入" << endl;
	}
}

void view_front_and_rear(const vector<string>& records)
{
	if (records.empty())
	{
		cout << "没有可访问元素" << endl;
	}
	else
	{
		cout << "第一条为：" << records.front() << endl;
		cout << "最后一条为：" << records.back() << endl;
	}
}

void replace_selected(vector <string>& records)
{
	int i = 0;
	cout << "请输入你想要替换第几条记录" << endl;
	cin >> i;
	--i;
	if (i < (int)records.size() && i >= 0)
	{
		string tmp;
		getline(cin, tmp);
		cout << "请输入替换内容" << endl;
		string selected_record;
		getline(cin, selected_record);
		records[i] = selected_record;
	}
	else
	{
		cout << "无效输入" << endl;
	}
}

void add_prefix(vector <string>& records)
{
	cout << "请输入添加的前缀" << endl;
	string prefix;
	getline(cin, prefix);
	for (auto& it : records)
	{
		it.insert(0, prefix);
	}
}

void append_record(vector <string>& records)
{
	cout << "请输入追加内容" << endl;
	string record;
	getline(cin, record);
	records.push_back(record);
}

void insert_selected(vector <string>& records)
{
	int pos = 0;
	cout << "请输入追加位置" << endl;
	cin >> pos;
	--pos;
	string tmp;
	getline(cin, tmp);
	if (pos <= (int)records.size() && pos >= 0)
	{
		cout << "请输入插入内容" << endl;
		string record;
		getline(cin, record);
		//insert第一个位置要求是迭代器
		records.insert(records.begin() + pos, record);
	}
	else
	{
		cout << "插入位置无效" << endl;
	}
}

void erase_selected_pos(vector <string>& records)
{
	int pos = 0;
	cout << "请输入删除位置" << endl;
	cin >> pos;
	--pos;
	if (pos < (int)records.size() && pos >= 0)
	{
		records.erase(records.begin() + pos);
	}
	else
	{
		cout << "删除位置无效" << endl;
	}
}

void erase_selected_section(vector <string>& records)
{
	int begin = 0, end = 0;
	vector<string>::iterator it = records.begin();
	cout << "请输入删除起始和结束位置" << endl;
	cout << "范围内全部元素均被删除" << endl;
	cin >> begin >> end;
	if (begin <= end && end <= records.size() && begin > 0)
	{
		--begin;
		records.erase(it + begin, it + end);
	}
	else
	{
		cout << "输入无效" << endl;
	}
}

void erase_last_pos(vector <string>& records)
{
	if (records.empty())
	{
		cout << "记录已经为空" << endl;
	}
	else
	{
		records.erase(records.end() - 1);
	}
}

void clear_vector(vector <string>& records)
{
	records.clear();
}

int main()
{
	cout << "请进行输入" << endl;
	vector <string> records;
	int choice = -1;
	choice = Input_records(records);
	while (choice != 0)
	{
		menu();
		cin >> choice;
		string tmp;
		getline(cin, tmp);
		switch (choice)
		{
		case 1:
			preview(records);
			break;
		case 2:
			view_the_selected(records);
			break;
		case 3:
			view_front_and_rear(records);
			break;
		case 4:
			replace_selected(records);
			break;
		case 5:
			add_prefix(records);
			break;
		case 6:
			append_record(records);
			break;
		case 7:
			insert_selected(records);
			break;
		case 8:
			erase_selected_pos(records);
			break;
		case 9:
			erase_selected_section(records);
			break;
		case 10:
			erase_last_pos(records);
			break;
		case 11:
			clear_vector(records);
			break;
		case 0:
			cout << "退出程序" << endl;
			break;
		default:
			cout << "无效选项，请重新选择。" << endl;
			break;
		}
	}
}