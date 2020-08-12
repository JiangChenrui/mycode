// stack和queue学习
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void test01() {
    // 特点：先进后出
    stack<int> s;

    // 入栈
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while( !s.empty()) {
        cout << "栈顶元素为：" << s.top() << endl;
        s.pop();
    }

    cout << "栈的大小：" << s.size() << endl;
}

void test02() {
    // 特点：先进先出
    queue<int> q;

    // 入队
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    while( !q.empty() ) {
        cout << "队头元素为：" << q.front() << endl;
        cout << "队尾元素为：" << q.back() << endl;
        q.pop();
    }
    cout << "队列大小为：" << q.size() << endl;
}

int main() {
    test02();
    return 0;
}