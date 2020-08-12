// vector容器学习
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <time.h>
#include <algorithm>
#include <unistd.h>
using namespace std;

void printVector(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << ' ';
    cout << endl;
}

// vector容器构造
void test01() {
    vector <int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    // 通过区间方式进行构造
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    // n个elem方式构造
    vector<int> v3(10, 100);
    printVector(v3);

    // 拷贝构造
    vector<int> v4(v3);
    printVector(v4);
}

// vector赋值
void test02() {
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    // operator=
    vector<int> v2;
    v2 = v1;
    printVector(v2);

    // assign
    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    printVector(v3);

    // n个elem方式赋值
    vector<int> v4;
    v4.assign(10, 100);
    printVector(v4);
}

// vector容量和大小
void test03() {
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    // 判断是否为空
    if (v1.empty()) {
        cout << "v1为空" << endl;
    } else {
        cout << "v1不为空" << endl;
        cout << "v1的容量为" << v1.capacity() << endl;
        cout << "v1的大小为" << v1.size() << endl;
    }

    // 重新指定大小
    v1.resize(15); // 使用第二个参数可以指定默认填充值
    printVector(v1); // 如果重新指定的闭原来长，使用0填充新的位置

    v1.resize(5);
    printVector(v1);
}

// vector插入删除
void test04() {
    vector<int> v1;
    // 尾插
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    printVector(v1);

    // 尾删
    v1.pop_back();
    printVector(v1);

    // 插入 第一个参数是迭代器
    v1.insert(v1.begin(), 100);
    printVector(v1);

    v1.insert(v1.begin(), 2, 1000);
    printVector(v1);

    // 删除 参数也是迭代器
    v1.erase(v1.begin());
    printVector(v1);
    
    // 清空
    // v1.erase(v1.begin(), v1.end());
    v1.clear();
    printVector(v1);
}

// vector数据存取
void test05() {
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }

    for (int i = 0; i < v1.size(); ++i) {
        cout << v1[i] << ' ';
    }
    cout << endl;

    for (int i = 0; i < v1.size(); ++i) {
        cout << v1.at(i) << ' ';
    }
    cout << endl;

    // 获取第一个元素
    cout << "第一个元素为" << v1.front() << endl;

    // 获取最后一个元素
    cout << "最后一个元素为" << v1.back() << endl;
}

// vector容器互换
void test06() {
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    cout << "交换前" << endl;
    printVector(v1);

    vector<int> v2;
    for (int i = 10; i > 0; --i) {
        v2.push_back(i);
    }
    printVector(v2);

    cout << "交换后" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}

// swap实际用途
void test06_a() {
    vector<int> v;
    for (int i = 0; i < 100000; ++i) {
        v.push_back(i);
    }
    cout << "v的容量为: " << v.capacity() << endl;
    cout << "v的大小为: " << v.size() << endl;

    v.resize(3);
    cout << "v的容量为: " << v.capacity() << endl;
    cout << "v的大小为: " << v.size() << endl;

    // 使用swap收缩内存
    // vector<int>(v) 匿名对象
    vector<int>(v).swap(v);
    cout << "v的容量为: " << v.capacity() << endl;
    cout << "v的大小为: " << v.size() << endl;
}

// vector预留空间
void test07() {
    vector<int> v;
    int num = 0;
    int *p = NULL;
    time_t start, end;
    start = clock();
    for (int i = 0; i < 100000; ++i) {
        v.push_back(i);
        if (p != &v[0]) {
            p = &v[0];
            ++num;
        }
    }
    end = clock();
    cout << "time is " << end - start << endl;  

    vector<int> v1;
    v1.reserve(100000);
        start = clock();
    for (int i = 0; i < 100000; ++i) {
        v1.push_back(i);
        if (p != &v[0]) {
            p = &v[0];
            ++num;
        }
    }
    end = clock();
    cout << "time is " << end - start << endl; 
}

// 评委打分
class Person {
public:
    Person(string name, int score) {
        this->m_name = name;
        this->m_score = score;
    }
    string m_name;
    int m_score;
};

void createPerson(vector<Person> &v) {
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; ++i) {
        string name = "选手";
        name += nameSeed[i];
        int score = 0;

        Person p(name, score);
        v.push_back(p);
    }
}

void setScore(vector<Person> &v) {
    for (vector<Person>::iterator it=v.begin(); it != v.end(); ++it) {
        // 将评委分数 放入deque容器
        deque<int> d;
        srand((unsigned int)time(NULL));
        for (int i = 0; i < 10; ++i) {
            int score = rand() % 41 + 60;
            d.push_back(score);
        }

        // 排序
        sort(d.begin(), d.end());
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); ++dit) {
            cout << *dit << ' ';
        }
        cout << endl;

        // 去掉最高和最低
        d.pop_back();
        d.pop_front();

        // 取平均分
        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); ++dit) {
            sum += (*dit);
        }
        (*it).m_score = sum / d.size();
        sleep(1);
    }
}

int main() {
    // 1.创建5名选手
    vector<Person> v;
    createPerson(v);

    // 测试
    // for (vector<Person>::iterator it = v.begin(); it != v.end(); ++it) {
    //     cout << "姓名：" << (*it).m_name << "\t分数：" << (*it).m_score << endl;
    // }

    // 打分
    setScore(v);
    for (vector<Person>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << "姓名：" << (*it).m_name << "\t分数：" << (*it).m_score << endl;
    }
    return 0;
}