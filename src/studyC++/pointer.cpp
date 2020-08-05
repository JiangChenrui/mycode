#include <iostream>
using namespace std;

void definition() {
    int a = 10;
    int *p = NULL;
    p = &a;
    cout << "a的地址为： " << &a << endl;
    cout << "指针p为: " << p << endl;
    cout << "指针p指向的值为：" << *p << endl;
    cout << "&p为: " << &p << endl;
    cout << "*&p为：" << *&p << endl;
}

void const_pointer() {
    int a = 10;
    int b = 20;
    /*
    常量指针：
    指针指向的内容不可以修改，指针的指向可以修改
    */
    const int* p = &a;
    // *p = 20 error
    p = &b;
    cout << "p is " << *p << endl;
    /*
    指针常量
    指针的指向不可以修改，指针指向的值可以修改
    */
    int* const p2 = &a;
    *p2 = 20;
    cout << "p2 is " << *p2 << endl;
}