#include <iostream>
using namespace std;

// c++模板实现
template <typename T> 
// 声明一个模板，告诉编译器后面代码紧跟的T不要报错，T是一个通用数据类型
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

void test01() {
    int a = 10;
    int b = 20;

    // 两种方式使用函数模板
    // 1.编译器自动推导
    mySwap(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // 2.显示制定类型
    double c = 1.2;
    double d = 3.3;
    mySwap<double>(c, d);
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
}

// 函数模板注意事项
// 1.自动类型推导，必须推导出一致的数据类型T才可以使用
// 2.模板必须要确定出T的数据类型才可以使用

template <class T> // typename可以替代成class
void func() {
    cout << "func调用" << endl;
}

// 通用数组排序函数
// 排序算法
template<class T>
void mySort(T arr[], int len) {
    for (int i = 0; i < len; ++i) {
        int max = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[max] < arr[j]) {
                max = j;
            }
        }
        if (max != i) {
            // 交换max和i元素
            mySwap(arr[i], arr[max]);
        }
    }
}

// 打印数组模板
template <typename T>
void myPrint(T arr[], int len) {
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void test02() {
    char charArr[] = "badfexqqewr";
    int len = sizeof(charArr) / sizeof(char);
    mySort(charArr, len);
    myPrint(charArr, len);

    int intArr[] = {6, 4, 1, 2, 9, 7, 3};
    int num = sizeof(intArr) / sizeof(int);
    mySort(intArr, num);
    myPrint(intArr, num);
}

// 普通函数和函数模板调用规则
// 1.如果函数模板和普通函数都可以调用，优先调用普通函数
// 2.可以通过空模板参数列表强制调用函数模板
// 3.函数模板可以发生重载
// 4.如果函数模板可以产生更好的匹配，优先调用函数模板

void myPrint(int a, int b) {
    cout << "调用的普通函数" << endl;
}

template <typename T>
void myPrint(T a, T b) {
    cout << "调用模板" << endl;
}

template <typename T>
void myPrint(T a, T b, T c) {
    cout << "调用重载的模板" << endl;
}

void test03() {
    int a = 10;
    int b = 20;
    myPrint(a, b);

    // 通过空模板参数列表，强制调用函数模板
    myPrint<>(a, b);

    myPrint(a, b, 10);
    
    char c1 = 'a';
    char c2 = 'b';
    myPrint(c1, c2);
}

// 类模板
// 类模板和函数模板区别
// 1.类模板没有自动推导的方式
// 2.类模板在模板参数列表中可以有默认参数
template <class NameType, class AgeType = int>
class Person {
public:
    Person(NameType name, AgeType age);

    void showPerson() {
        cout << "name: " << m_name << endl;
        cout << "age: " << m_age << endl;
        cout << "name name " << typeid(m_name).name() << endl;
        cout << "age name " << typeid(m_age).name() << endl;
    }

    NameType m_name;
    AgeType m_age;
};

// 构造函数类外实现
template <class T1, class T2>
Person <T1, T2>::Person(T1 name, T2 age) {
    this->m_name = name;
    this->m_age = age;
}

void test04() {
    Person <string, int> p1("猪八戒", 888);
    p1.showPerson();
}

void test05() {
    Person <string> p2("孙悟空", 999);
    p2.showPerson();
}

// 类模板与继承
template <class T>
class Base {
    T m;
};

template <class T1, class T2>
class Son : public Base <T2>{
public:
    Son() {
        cout << "T1的类型为：" << typeid(T1).name() << endl;
        cout << "T2的类型为：" << typeid(T2).name() << endl;
    }
    T1 obj;
};

void test06() {
    Son <int, char> S2;
}

int main() {
    test06();
    return 0;
}
