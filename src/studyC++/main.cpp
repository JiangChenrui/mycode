#include <iostream>
#include <sstream>
#include "main.h"
#include "MyArray.hpp"
#include <string>

void printIntArray(MyArray <int> &arr) {
    for (int i = 0; i < arr.getArraySize(); ++i) {
        cout << arr[i]<< endl;
    }
}

void test01() {
    MyArray <int> arr1(5);
    for (int i = 0; i < 5; ++i) {
        arr1.push_back(i);
    }
    cout << "arr1的打印输出为:" << endl;
    printIntArray(arr1);
    cout << "arr1的大小为" << arr1.getArraySize() << endl;
    arr1.pop_back();
    cout << "arr1的大小为" << arr1.getArraySize() << endl;
}

// 测试自定义数组类型
class Person {
public:
    Person() {};
    Person(string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};

void printPersonArray(MyArray<Person>& arr) {
    for (int i = 0; i < arr.getArraySize(); ++i) {
        cout << "姓名: " << arr[i].m_name << "\t年龄: " << arr[i].m_age << endl;
    }
}

void test02() {
    MyArray <Person> arr(10);

    Person p1("孙悟空", 888);
    Person p2("韩信", 30);
    Person p3("妲己", 20);
    Person p4("猪八戒", 1111);
    Person p5("刘备", 40);

    // 将数组插入到数组
    arr.push_back(p1);
    arr.push_back(p2);
    arr.push_back(p3);
    arr.push_back(p4);
    arr.push_back(p5);
    printPersonArray(arr);

}

int main() {
    // sizeof_print();
    // char_study();
    // str_study();
    // add_compare();
    // rand_number(100);
    // num_of_daffodils();
    // knock_table();
    // out_multiplication();
    // arr_out();
    // int arr[] = {3, 1, 8, 2, 6, 9, 4, 5, 7};
    // bubble_sort(arr, sizeof(arr)/sizeof(arr[0]));
    // two_array();
    // definition();
    // const_pointer();
    // pointer_struct();
    // Teacher teachers[3];
    // allocateSpace(teachers, 3);
    // printInfo(teachers, 3);
    test02();
    return 0;
}