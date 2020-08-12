#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 遍历算法
// for_each
void print01(int v) {
    cout << v << ' ';
}
class Print02 {
public:
    void operator()(int v) {
        cout << v << ' ';
    }
};
void test01() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), print01);
    cout << endl;

    for_each(v.begin(), v.end(), Print02());
    cout << endl;
}

// transform
void test02() {

}

// 查找
// find 内置数据类型
void test03() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    vector<int>::iterator pos = find(v.begin(), v.end(), 5);
    if (pos == v.end()) {
        cout << "未找到" << endl;
    } else {
        cout << "找到了" << endl;
    }
}

// 自定义数据类型
class Person {
public:
    Person(string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }

    // 重载==号，底层find知道如何对比person类型
    bool operator==(const Person &p) {
        // if (this->m_name == p.m_name && this->m_age == p.m_age)
        //     return true;
        // else 
        //     return false;
        return this->m_name == p.m_name && this->m_age == p.m_age;
    }
    string m_name;
    int m_age;
};
void test04() {
    vector <Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    vector<Person>::iterator pos = find(v.begin(), v.end(), Person("bbb", 20));
    if (pos == v.end()) {
        cout << "未找到" << endl;
    } else {
        cout << "找到了" << endl;
        cout << "name is : " << pos->m_name << "\t age is : " << pos->m_age << endl;
    }
}

// find_if
class GreaterFive {
public:
    bool operator() (int v){
        return v > 5;
    }
};
void test05() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterFive());
    if (pos == v.end()) {
        cout << "未找到" << endl;
    } else {
        cout << "找到了" << endl;
    }
}
class Greater20 {
public:
    bool operator() (Person &p) {
        return p.m_age > 20;
    }
};

void test06() {
    vector <Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    vector<Person>::iterator pos = find_if(v.begin(), v.end(), Greater20());
    if (pos == v.end()) {
        cout << "未找到" << endl;
    } else {
        cout << "找到了" << endl;
        cout << "name is : " << pos->m_name << "\t age is : " << pos->m_age << endl;
    }
}

int main() {
    test06();
    return 0;
}