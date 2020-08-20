#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
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
    // bool operator==(const Person &p) {
    //     // if (this->m_name == p.m_name && this->m_age == p.m_age)
    //     //     return true;
    //     // else 
    //     //     return false;
    //     return this->m_name == p.m_name && this->m_age == p.m_age;
    // }
    bool operator== (const Person &p) {
        return this->m_age == p.m_age;
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
    bool operator() (int val) {
        return val > 20;
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

// adjacent_find 查找相邻重复元素
void test07() {
    vector<int> v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(3);

    vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
    if (pos == v.end()) {
        cout << "未找到" << endl;
    } else {
        cout << "已找到" << endl;
        cout << *pos << "\t" << pos - v.begin() << endl;
    }
}

// binary_search查找指定元素是否存在（二分查找）
// 返回布尔类型，在无序序列中不可用
void test08() {
    vector<int> v;
    for (int i = 0; i < 1000000; ++i) {
        v.push_back(i);
    }
    if (binary_search(v.begin(), v.end(), 2222)) {
        cout << "找到了" << endl;
    } else {
        cout << "未找到" << endl;
    }
}

// count
void test09() {
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(40);

    int num = count(v.begin(), v.end(), 40);
    cout << num << endl;
}

void test10() {
    vector<Person> v;
    Person p1("刘备", 35);
    Person p2("关羽", 35);
    Person p3("张飞", 35);
    Person p4("赵云", 30);
    Person p5("曹操", 40);

    Person p("诸葛亮", 35);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    int num = count(v.begin(), v.end(), p);
    cout << num << endl;
}

// count_if
void test11() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(40);
    v.push_back(22);

    int num = count_if(v.begin(), v.end(), Greater20());
    cout << num << endl;
}

void test12() {
    vector<Person> v;
    Person p1("刘备", 35);
    Person p2("关羽", 35);
    Person p3("张飞", 35);
    Person p4("赵云", 30);
    Person p5("曹操", 20);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    
    int num = count_if(v.begin(), v.end(), Greater20());
    cout << num << endl;
}

void printVector(const vector<int> &v) {
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}

void printVector(const vector<int> &v, vector<int>::const_iterator pos) {
    for (vector<int>::const_iterator it = v.begin(); it != pos; ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}

// 排序
void test13() {
    vector<int> v;
    srand(time(NULL));
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    v.push_back(40);
    sort(v.begin(), v.end());
    printVector(v);
    // 打乱排序
    random_shuffle(v.begin(), v.end());
    printVector(v);
}

// merge合并容器，必须是有序的
void test14() {
    vector<int> v1;
    vector<int> v2;
    vector<int> v;

    for (int i = 0; i < 10; ++i) {
        v1.push_back(2 * i);
        v2.push_back(2 * i + 1);
    }
    // 开辟空间
    v.resize(v1.size() + v2.size());

    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
    printVector(v1);
    printVector(v2);
    printVector(v);
}

// 容器反转reverse
void test15() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    printVector(v);
    reverse(v.begin(), v.end());
    printVector(v);
}

// 常用的拷贝和替换
// copy
// replace
// replace_if
// swap
void test16() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    v.push_back(40);
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    v.push_back(40);
    printVector(v);

    vector<int> vTarget;
    // 使用reserve开辟空间不能copy
    vTarget.resize(v.size());
    copy(v.begin(), v.end(), vTarget.begin());
    printVector(vTarget);

    replace(v.begin(), v.end(), 10, 20);
    printVector(v);

    replace_if(v.begin(), v.end(), Greater20(), 10);
    printVector(v);

    cout << "替换前" << endl;
    printVector(v);
    printVector(vTarget);
    swap(v, vTarget);
    cout << "替换后" << endl;
    printVector(v);
    printVector(vTarget);
}

// 算术生成算法
void test17() {
    vector<int> v;
    for (int i = 0; i <= 100; ++i) {
        v.push_back(i);
    }
    // 参数3，起始累加值
    int total = accumulate(v.begin(), v.end(), 0);
    cout << "total = " << total << endl;
}

// fill填充元素
void test18() {
    vector<int> v;
    v.resize(100, 2);
    printVector(v);
    fill(v.begin(), v.end(), 100);
    printVector(v);
}

// 常用集合算法
// set_intersection 交集
// set_union 并集
// set_defference 差集
void test19() {
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i+5);
    }
    vector<int> vTarget;
    vTarget.resize(min(v1.size(), v2.size()));
    vector<int>::iterator pos;
    cout << vTarget.capacity() << endl;
    cout << vTarget.size() << endl;
    pos = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    printVector(vTarget, pos);

    vTarget.clear();
    vTarget.resize(v1.size() + v2.size());
    cout << vTarget.capacity() << endl;
    cout << vTarget.size() << endl;
    pos = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    printVector(vTarget, pos);

    vTarget.clear();
    vTarget.resize(max(v1.size(), v2.size()));
    cout << vTarget.capacity() << endl;
    cout << vTarget.size() << endl;
    pos = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    printVector(vTarget, pos);
}

int main() {
    test19();
    return 0;
}