#include <iostream>
using namespace std;
class A 
{ public: 
    A() { cout << "A()" << endl; } 
    ~A() { cout << "~A()" << endl; } 
};

A g;                     // 程序开始
int main()
{
    A a1;
    {
        A a2;
    }                    // a2 出作用域就析构
    static A s;
    return 0;            // a1 析构，然后 s 析构，最后 g 析构
}