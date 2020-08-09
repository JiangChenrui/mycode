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

int *func() {
    // 函数的局部变量和形参存放在栈区，函数执行完成删除
    // 使用new会将分配内存到堆区，返回堆区地址。
    int *a = new int(10);
    return a;
}

void quote() {
    // 引用必须初始化，初始化后不可以改变
    int a = 10;
    int &b = a;
    int  c = 20;
    b = c; // 赋值
}

// int main() {
//     int *p = func();
//     cout << *p << endl;
//     cout << *p << endl;
//     // 指针的指针
//     int *a = new int (10);
//     int **b = &a;
//     cout << **b << endl;
//     delete p;
//     return 0;
// }