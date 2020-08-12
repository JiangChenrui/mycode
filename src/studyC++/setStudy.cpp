// set容器
#include <iostream>
#include <string>
#include <set>
using namespace std;

void printSet(const set<int> &s) {
    for (set<int>::const_iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}

// set自动队插入数据进行排序，没有重复元素，multiset有重复元素
void test01() {
    set<int> s1;

    // 插入数据只有insert
    s1.insert(40);
    s1.insert(20);
    s1.insert(10);
    s1.insert(30);
    s1.insert(10);
    printSet(s1);

    set<int> s2(s1);
    printSet(s2);

    set<int> s3 = s1;
    printSet(s3);
}

// set大小和变换
void test02() {
    set<int> s;
    s.insert(40);
    s.insert(20);
    s.insert(10);
    s.insert(30);

    if (s.empty()) {
        cout << "s为空" << endl;
    } else {
        cout << "s不为空" << endl;
        cout << "s的大小为：" << s.size() << endl;
    }

    set<int> temp;
    for (int i = 0; i < 10; ++i) {
        temp.insert(i * 100);
    }
    printSet(s);
    printSet(temp);
    s.swap(temp);
    printSet(s);
    printSet(temp);
}

// 插入删除
void test03() {
    set<int> s1;
    s1.insert(40);
    s1.insert(20);
    s1.insert(10);
    s1.insert(30);
    s1.insert(10);
    printSet(s1);

    s1.erase(s1.begin());
    printSet(s1);
    s1.erase(30);
    printSet(s1);

    // s1.erase(s1.begin(), s1.end());
    s1.clear();
    printSet(s1);
}

// 查找和统计
void test04() {
    set<int> s1;
    s1.insert(40);
    s1.insert(20);
    s1.insert(10);
    s1.insert(30);
    s1.insert(10);

    set<int>::iterator pos = s1.find(300);
    if (pos != s1.end()) {
        cout << "找到元素：" << *pos << endl;
    } else {
        cout << "未找到元素" << endl;
    }

    // 统计
    int num = s1.count(300);
    cout <<  "num = " << num << endl;
}

// set和multiset区别
void test05() {
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);
    ret = s.insert(10);
    if (ret.second) {
        cout << "数据插入成功" << endl;
    } else {
        cout << "数据插入失败" << endl;
    }

    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);

    for (multiset<int>::iterator it = ms.begin(); it != ms.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}

class MyCompare {
public:
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};

// set容器排序
void test07() {
    set<int>s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    s1.insert(50);
    printSet(s1);

    // 指定排序规则
    set<int, MyCompare> s2;
    s2.insert(10);
    s2.insert(20);
    s2.insert(30);
    s2.insert(40);
    s2.insert(50);
    for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); ++it)
        cout << *it << ' ';
    cout << endl;
}
class Person {
public:
    Person(string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};

class comparePerson {
public:
    bool operator() (const Person &p1, const Person &p2) {
        return p1.m_age > p2.m_age;
    }
};

void test08() {
    // 自定义数据类型都会指定排序规则
    set<Person, comparePerson> s;

    Person p1("刘备", 24);
    Person p2("关羽", 28);
    Person p3("张飞", 25);
    Person p4("赵云", 21);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); ++it)
        cout << "姓名：" << it->m_name << "\t年龄：" << it->m_age << endl;
}

// pair对组创建
void test06() {
    pair<string, int> p("Tom", 20);
    cout << "姓名：" << p.first << "\t年龄：" << p.second << endl;

    pair<string, int> p2 = make_pair("Jerry", 30);
    cout << "姓名：" << p2.first << "\t年龄：" << p2.second << endl;
}

int main() {
    test08();
    return 0;
}