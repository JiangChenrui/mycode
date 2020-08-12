/**
 * c++STL库学习
 * 六大组件：容器、算法、迭代器、仿函数、适配器、空间配置器
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void myPrint(int val) {
    cout << val << endl;
}

void test01() {
    vector <int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    // 通过迭代器访问容器数据
    // vector <int>::iterator itBegin = v.begin();
    // vector <int>::iterator itEnd = v.end(); // 容器中最后一个元素的下一个位置

    // // 第一种遍历
    // while (itBegin != itEnd)
    // {
    //     cout << *itBegin << endl;
    //     itBegin++;
    // }
    
    // 第二种遍历
    // for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    //     cout << *it << endl;
    // }
    // 第三种遍历
    for_each(v.begin(), v.end(), myPrint);
}

// vector容器中存放自定义数据类型
class Person {
public:
    Person(string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};

void test02() {
    vector <Person> arr;

    Person p1("孙悟空", 888);
    Person p2("韩信", 30);
    Person p3("妲己", 20);
    Person p4("猪八戒", 1111);
    Person p5("刘备", 40);

    // 向容器添加数据
    arr.push_back(p1);
    arr.push_back(p2);
    arr.push_back(p3);
    arr.push_back(p4);
    arr.push_back(p5);

    // 遍历容器中的数据
    for (vector <Person>::iterator it = arr.begin(); it != arr.end(); ++it) {
        cout << "姓名：" << (*it).m_name << "\t年龄：" << (*it).m_age << endl;
    }
}

void test03() {
    vector <Person*> arr;

    Person p1("孙悟空", 888);
    Person p2("韩信", 30);
    Person p3("妲己", 20);
    Person p4("猪八戒", 1111);
    Person p5("刘备", 40);

    // 向容器添加数据
    arr.push_back(&p1);
    arr.push_back(&p2);
    arr.push_back(&p3);
    arr.push_back(&p4);
    arr.push_back(&p5);

    // 遍历容器
    for (vector <Person*>::iterator it = arr.begin(); it != arr.end(); ++it) {
        cout << "姓名：" << (*it)->m_name << "\t年龄：" << (*it)->m_age << endl;
    }
}

// 容器嵌套容器
void test04() {
    vector< vector <int>> v;
    // 创建小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for (int i = 0; i < 4; ++i) {
        v1.push_back(i);
        v2.push_back(i + 10);
        v3.push_back(i + 20);
        v4.push_back(i + 30);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    // 遍历数据
    for (vector< vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
        for (vector <int>::iterator vit = (*it).begin(); vit != (*it).end(); ++vit) {
            cout << *vit << "\t";
        }
        cout << endl;
    }
}

int main() {
    test04();
    return 0;
}