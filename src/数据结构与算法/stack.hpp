#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
using namespace std;

template <class T>
class Stack {
public:
    Stack();
    Stack(int capacity);
    ~Stack();
    bool IsEmpty();                 // 判断是否为空
    bool IsFull();                  // 判断栈是否已满
    void ClearStack();              // 清空栈
    int Length();                   // 获取栈的长度
    bool Push(const T &element);    // 获取元素
    bool Pop(T &ele);               // 弹出栈顶元素
    void StackTraverse();           // 遍历栈

private:
    T *m_stack;     // 容器
    int m_top;      // 栈顶
    int m_capacity; // 容器容量
};

template <typename T>
Stack<T>::Stack() {
    cout << "构造函数" << endl;
}

template <typename T>
Stack<T>::Stack(int capacity) {
    this->m_capacity = capacity;
    this->m_top = 0;
    this->m_stack = new T[this->m_capacity];
}

template <typename T>
Stack<T>::~Stack() {
    if (this->m_stack != NULL) {
        delete[] this->m_stack;
        this->m_stack = NULL;
    }
}

template <typename T>
bool Stack<T>::IsEmpty() {
    return this->m_top == 0 ? true : false;
}

template <typename T>
bool Stack<T>::IsFull() {
    return this->m_top == this->m_capacity ? true : false;
}

template <typename T>
void Stack<T>::ClearStack() {
    this->m_top = 0;
}

template <typename T>
int Stack<T>::Length() {
    return this->m_top;
}

template <typename T>
bool Stack<T>::Push(const T &element) {
    if (IsFull()) {
        return false;
    } else {
        this->m_stack[this->m_top++] = element;
        return true;
    }
}

template <typename T>
bool Stack<T>::Pop(T &ele) {
    if (!IsEmpty()) {
        this->m_top--;
        ele = this->m_stack[this->m_top];
        return true;
    } else {
        return false;
    }
}

template <typename T>
void Stack<T>::StackTraverse() {
    if (!IsEmpty()) {
        for (int i = m_top - 1; i >= 0; --i) {
            cout << this->m_stack[i] << ' ';
        }
        cout << endl;
    } else {
        cout << "栈为空" << endl;
    }
}
#endif