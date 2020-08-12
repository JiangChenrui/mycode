// map学习
#include <map>
#include <iostream>
using namespace std;

void printMap(map<int, int> m) {
    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
        cout << "key = " << (*it).first << "\tvalue = " << it->second << endl;
    cout << endl;
}

void test01() {
    map<int, int> mp;
    mp.insert(pair<int, int>(3, 10));
    mp.insert(pair<int, int>(2, 20));
    mp.insert(pair<int, int>(1, 30));
    mp.insert(pair<int, int>(4, 40));
    printMap(mp);

    map<int, int> mp2(mp);
    printMap(mp2);

    map<int, int> mp3;
    mp3 = mp;
    printMap(mp3);
}

// map大小和交换
void test02() {
    map<int, int> m;
    m.insert(pair<int, int>(3, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(1, 30));
    m.insert(pair<int, int>(4, 40));
    cout << "m的大小为：" << m.size() << endl;

    map<int, int> m2;

    m2.insert(pair<int, int>(1, 22));
    cout << "交换前" << endl;
    printMap(m);
    printMap(m2);
    m.swap(m2);  
    cout << "交换后" << endl;
    printMap(m);
    printMap(m2);  
}

// 插入删除
void test03() {
    map<int, int> m;
    m.insert(pair<int, int>(3, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(1, 30));
    m.insert(pair<int, int>(4, 40));

    m.insert(make_pair(5, 50));

    m.insert(map<int, int>::value_type(6, 60));
    // []可以使用key访问到value
    m[7] = 70;
    printMap(m);

    m.erase(m.begin());
    printMap(m);
    m.erase(3);
    printMap(m);

    // m.erase(m.begin(), m.end());
    m.clear();
    printMap(m);
}

// 查找和统计
void test04() {
    map<int, int> m;
    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));

    map<int, int>::iterator pos = m.find(3);

    if (pos != m.end()) {
        cout << "find key = " << pos->first << "\tvalue = " << (*pos).second << endl;
    } else {
        cout << "not find" << endl;
    }

    int num = m.count(3);
    cout << "num = " << num << endl;
}

class MyCompare {
public:
    bool operator()(const int v1, const int v2) {
        return v1 > v2;
    }
};

// map排序
void test05() {
    map<int, int, MyCompare> m;
    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));    
    for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); ++it)
        cout << "key = " << it->first << "\tvalue = " << it->second << endl;
    cout << endl;

}

int main() {
    test05();
    return 0;
}