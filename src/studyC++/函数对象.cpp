#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>   // STL内置仿函数
using namespace std;

/**
 * 函数对象（仿函数）
 * - 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
 * - 函数对象超出普通函数的概念，函数对象可以有自己的状态
 * - 函数对象可以做为参数传递
 */

class MyAdd {
public:
    int operator() (int v1, int v2) {
        return v1 + v2;
    }
};

void test01() {
    MyAdd myAdd;
    cout << myAdd(10, 10) << endl;
}

class MyPrint {
public:
    MyPrint() {
        count = 0;
    }

    void operator() (string test) {
        cout << test << endl;
        this->count++;
    }
    
    int count;
};

void test02() {
    MyPrint myPrint;
    myPrint("Hello World");
    myPrint("Hello World");
    myPrint("Hello World");
    myPrint("Hello World");
    myPrint("Hello World");
    cout << "myPrint调用次数为：" << myPrint.count << endl;
}

void doPrint(MyPrint &mp, string test) {
    mp(test);
}

void test03() {
    MyPrint myPrint;
    doPrint(myPrint, "Hello c++");
}

// 仿函数返回类型为bool时称为一元谓词
// 谓词
class GreaterFive {
public:
    bool operator() (int v) {
        return v > 5;
    }
};
void test04() {
    vector<int> v;
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        v.push_back(rand() % 11);
    }
    vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterFive());
    if (pos != v.end()) {
        cout << "找到第一个大于5的数为：" << *pos << endl;
    } else {
        cout << "没找到" << endl;
    }
}

// 二元谓词
class MyCompare {
public:
    bool operator() (int v1, int v2) {
        return v1 > v2;
    }
};
void test05() {
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(40);
    v.push_back(20);
    sort(v.begin(), v.end());
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
    cout << "------------------------------" << endl;

    sort(v.begin(), v.end(), MyCompare());
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}

// STL内置仿函数
// negate 一元仿函数 取反
void test06() {
    negate<int> n;
    cout << n(50) << endl;
}
// plus 二元仿函数 加法
void test07() {
    plus<int> add;
    cout << add(20, 30) << endl;
}

int main() {
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    test06();
    test07();
    return 0;
}