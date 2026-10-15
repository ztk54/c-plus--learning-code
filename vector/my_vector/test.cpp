#include "my_vector.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ztk::vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	auto it = v.find(5);
	v.insert(it, 9999);
	for (auto it : v)
	{
		cout << it << endl;
	}
}

//struct Item {
//    int value;
//
//    Item(int n = 0) : value(n) {
//        std::cout << "construct " << value << '\n';
//    }
//    Item(const Item& other) : value(other.value) {
//        std::cout << "copy " << value << '\n';
//    }
//    Item& operator=(const Item& other) {
//        value = other.value;
//        std::cout << "assign " << value << '\n';
//        return *this;
//    }
//    ~Item() {
//        std::cout << "destroy " << value << '\n';
//    }
//};
//
//int main() {
//    const Item source(7);
//
//    {
//        std::cout << "your: reserve\n";
//        ztk::vector<Item> v;
//        v.reserve(3);
//        std::cout << "your: size=" << v.size()
//            << " capacity=" << v.capacity() << '\n';
//        std::cout << "your: push\n";
//        v.push_back(source);
//        std::cout << "your: size=" << v.size()
//            << " capacity=" << v.capacity() << '\n';
//        std::cout << "your: leave scope\n";
//    }
//
//    {
//        std::cout << "std: reserve\n";
//        std::vector<Item> v;
//        v.reserve(3);
//        std::cout << "std: size=" << v.size()
//            << " capacity=" << v.capacity() << '\n';
//        std::cout << "std: push\n";
//        v.push_back(source);
//        std::cout << "std: size=" << v.size()
//            << " capacity=" << v.capacity() << '\n';
//        std::cout << "std: pop\n";
//        v.pop_back();
//        std::cout << "std: size=" << v.size()
//            << " capacity=" << v.capacity() << '\n';
//        std::cout << "std: leave scope\n";
//    }
//
//    std::cout << "source: leave main\n";
//}
