// list容器
#include <iostream>
#include <string>
#include <list>
using namespace std;

void printList(const list<int> &L) {
    for (list<int>::const_iterator it = L.begin(); it != L.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}

void test01() {
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);

    list<int>L2(L1.begin(), L1.end());
    printList(L2);

    list<int> L3(L2);
    printList(L3);

    list<int> L4(10, 1000);
    printList(L4);
}

// 赋值和交换
void test02() {
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);

    list<int> L2;
    L2 = L1;
    printList(L2);

    list<int> L3;
    L3.assign(L1.begin(), L1.end());
    printList(L3);

    list<int> L4;
    L4.assign(10, 100);
    printList(L4);
}

// 交换
void test03() {
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    list<int> L2;
    L2.assign(10, 100);
    cout << "交换前：" << endl;
    printList(L1);
    printList(L2);

    L1.swap(L2);
    cout << "交换后：" << endl;
    printList(L1);
    printList(L2);

}

// list容器大小操作
void test04() {
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);

    if (L1.empty()) {
        cout << "L1为空" << endl;
    } else {
        cout << "L1不为空" << endl;
        cout << "L1大小为" << L1.size() << endl;
    }

    // 重新指定大小
    L1.resize(10, 1);
    printList(L1);

    L1.resize(2);
    printList(L1);
}

// list插入和删除
void test05() {
    list<int> L;
    
    // 尾插
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    L.push_back(40);

    // 头插
    L.push_front(100);
    L.push_front(200);
    L.push_front(300);

    printList(L);

    // 尾删
    L.pop_back();
    printList(L);

    // 头部删除
    L.pop_front();
    printList(L);

    // insert插入
    L.insert(L.begin(), 1000);
    printList(L);
    L.insert(L.begin(), 10, 1000);
    printList(L);

    // 删除
    list<int>::iterator it = L.begin();
    L.erase(++it);
    printList(L);

    // 移除
    L.push_back(10000);
    printList(L);
    L.remove(1000);
    printList(L);

    // L.erase(L.begin(), L.end());
    L.clear();
    printList(L);
}

void test06() {
    list<int> L;
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    L.push_back(40);
    printList(L);

    // list迭代器不支持随机访问
    cout << "第一个元素为：" << L.front() << endl;
    cout << "最后一个元素为：" << L.back() << endl;

    // 验证迭代器是不支持随机访问的
    list<int>::iterator it = L.begin();

    // it += 3 error
    it++;
    it--;
    // it += 1; 不支持随机访问

}

bool myCompare(int a, int b) {
    // 降序，第一个数大于第二个数
    return a > b ? true : false;
}

// list反转和排序
void test07() {
    list<int> L;
    L.push_back(20);
    L.push_back(10);
    L.push_back(50);
    L.push_back(40);
    L.push_back(30);
    printList(L);

    // 反转
    L.reverse();
    printList(L);

    L.sort();
    printList(L);

    L.sort(myCompare);
    printList(L);
}

// 自定义数据类型排序
class Person {
public:
    Person(string name, int age, int height) {
        this->m_name = name;
        this->m_age = age;
        this->m_height = height;
    }
    string m_name;
    int m_age;
    int m_height;
};

bool personCompare(Person &a, Person &b) {
    // if (a.m_age < b.m_age) {
    //     return true;
    // } else if (a.m_age == b.m_age) {
    //     if (a.m_height < b.m_height)
    //         return false;
    //     else 
    //         return true;
    // } else {
    //     return false;
    // }

    if (a.m_age == b.m_age) {
        return a.m_height > b.m_height;
    } else {
        return a.m_age < b.m_age;
    }
}

void test08() {
    list<Person> L;

    Person p1("刘备", 35, 175);
    Person p2("曹操", 45, 180);
    Person p3("孙权", 40, 170);
    Person p4("赵云", 25, 190);
    Person p5("张飞", 35, 160);
    Person p6("关羽", 35, 200);

    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);

    for (list<Person>::iterator it = L.begin(); it != L.end(); ++it) {
        cout << "姓名：" << (*it).m_name << "\t年龄：" << (*it).m_age
             << "\t身高：" << (*it).m_height << endl;
    }
    cout << "排序后：" << endl;
    L.sort(personCompare);
    for (list<Person>::iterator it = L.begin(); it != L.end(); ++it) {
        cout << "姓名：" << (*it).m_name << "\t年龄：" << (*it).m_age
             << "\t身高：" << (*it).m_height << endl;
    }
}

int main() {
    test08();
    return 0;
}