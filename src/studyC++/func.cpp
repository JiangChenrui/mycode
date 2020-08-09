#include <iostream>

using std::cout;
using std::endl;

//函数重载的满足条件
//1.同一个作用域
//2.函数名称相同
//3.函数的参数类型不同，或者个数不同，或者顺序不同

//注意事项
//函数的返回值不可以做为函数重载的条件

void func() {
    cout << "func 的调用" << endl;
}

void func(int a) {
    cout << "func (int a) 的调用" << endl;
}

void func(double a) {
    cout << "func (double a) 的调用" << endl;
}

void func(int a, double b) {
    cout << "func (int a, double b) 的调用" << endl;
}

void func(double a, int b) {
    cout << "func (double a, int b) 的调用" << endl;
}

int main() {
    func();
    func(10);
    func(3.14);
    func(10, 3.14);
    func(3.14, 10);
    return 0;
}