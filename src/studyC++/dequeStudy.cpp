// deque容器学习
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void printDeuque(const deque<int> &d) {
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}

// 构造函数
void test01() {
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }
    printDeuque(d1);

    deque<int> d2(d1.begin(), d1.end());
    printDeuque(d2);

    deque<int> d3(10, 100);
    printDeuque(d3);

    deque<int> d4(d3);
    printDeuque(d4);
}

// 赋值
void test02() {
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }
    printDeuque(d1);

    // =
    deque<int> d2;
    d2 = d1;
    printDeuque(d2);

    // assign赋值
    deque<int> d3;
    d3.assign(d1.begin(), d1.end());
    printDeuque(d3);

    deque<int> d4;
    d4.assign(10, 100);
    printDeuque(d4);
}

// 大小操作
void test03() {
    deque<int> d;
    for (int i = 0; i < 10; ++i) {
        d.push_back(i);
    }
    printDeuque(d);
    
    if (d.empty()) {
        cout << "d为空" << endl;
    } else {
        cout << "d不为空" << endl;
        cout << "d的大小为" << d.size() << endl;
    }

    // 重新指定大小
    d.resize(15, 1);
    printDeuque(d);

    d.resize(5);
    printDeuque(d);
}

// 插入删除
void test04() {
    deque<int> d;

    // 尾插
    d.push_back(10);
    d.push_back(20);

    // 头插
    d.push_front(100);
    d.push_front(200);
    printDeuque(d);

    // 尾删
    d.pop_back();
    printDeuque(d);

    // 头删
    d.pop_front();
    printDeuque(d);
}

void test05() {
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);
    printDeuque(d);

    // insert插入
    d.insert(d.begin(), 1000);
    printDeuque(d);

    d.insert(d.begin(), 2, 10000);
    printDeuque(d);

    // 按照区间进行插入
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d.insert(d.begin(), d2.begin(), d2.end());
    printDeuque(d);
}

void test06() {
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);
    printDeuque(d);

    // 删除
    deque<int>::iterator it = d.begin();
    it++;
    d.erase(it);
    printDeuque(d);

    // 按照区间方式删除
    // d.erase(d.begin(), d.end());
    d.clear();
    printDeuque(d);
}

// 数据存取
void test07() {
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);

    // []
    for (int i = 0; i < d.size(); ++i) {
        cout << d[i] << ' ';
    }
    cout << endl;

    for (int i = 0; i < d.size(); ++i) {
        cout << d.at(i) << ' ';

    }
    cout << endl;

    cout << "第一个元素为：" << d.front() << endl;
    cout << "最后一个元素为：" << d.back() << endl;
}

// 排序
void test08() {
    deque<int> d;
    srand(time(NULL));
    for (int i = 0; i < 100; ++i) {
        d.push_back(rand() % 100);
    }
    printDeuque(d);
    // 支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
    sort(d.begin(), d.end());
    printDeuque(d);
}

int main() {
    test08();
    return 0;
}