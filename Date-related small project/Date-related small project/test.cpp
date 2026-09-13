#include "Date class.h"

int main()
{
	Date d1(2006, 12, 18);
	Date d2 = d1 + 30000;
	d1.Print();
	d2.Print();
	cout << d2 - d1 << endl;
}