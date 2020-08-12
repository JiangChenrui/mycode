// 通用数组类
#ifndef MYARRAY_HPP
#define MYARRAY_HPP
#include <iostream>
using namespace std;

template <class T>

class MyArray {
public:
    // 有参构造
    MyArray(int capacity) {
        this->m_capacity = capacity;
        this->m_size = 0;
        this->p_address = new T[this->m_capacity];
        // cout << "MyArray有参构造" << endl;
    }
    // 拷贝构造函数
    MyArray(const MyArray &array) {
        this->m_capacity = array.m_capacity;
        this->m_size = array.m_size;
        // 深拷贝
        this->p_address = new T[array.m_capacity];
        // 数据拷贝
        for (int i = 0; i < this->m_size; ++i) {
            this->p_address[i] = array.p_address[i];
        }
        // cout << "MyArray拷贝构造" << endl;
    }
    // 符号重载
    MyArray& operator=(const MyArray& array) {
        // 先判断原来堆区是否有数据,如果有先是否
        if (this->p_address != NULL) {
            delete [] this->p_address;
            this->p_address = NULL;
            this->m_capacity = 0;
            this->m_size = 0;
        }

        // 深拷贝
        this->m_capacity = array.m_capacity;
        this->m_size = array.m_size;
        // 深拷贝
        this->p_address = new T[array.m_capacity];
        // 数据拷贝
        for (int i = 0; i < this->m_size; ++i) {
            this->p_address[i] = array.p_address[i];
        }
        // cout << "MyArray符号构造" << endl;
        return *this;
    }
    // 析构函数
    ~MyArray() {
        if (this->p_address != NULL) {
            delete[] this->p_address;
            this->p_address;
        }
        // cout << "MyArray析构函数" << endl;
    }
    // 尾插法
    void push_back(const T& val) {
        // 判断容量大小
        if (this->m_capacity == this->m_size) {
            cout << "数组容量到达上限" << endl;
            return;
        }
        this->p_address[this->m_size] = val;
        this->m_size++;
    }
    // 尾删法
    void pop_back() {
        // 删除最后一个元素
        if (this->m_size == 0) {
            cout << "数组为空" << endl;
            return;
        }
        this->m_size--;
    }
    // 通过下标访问数组元素
    T& operator[] (int index) {
        return this->p_address[index];
    }
    // 返回数组大小
    int getArraySize() {
        return this->m_size;
    }
    // 返回数组容量
    int getCapacity() {
        return this->m_capacity;
    }

private:
    T *p_address;   // 指针指向堆区开辟的真实数组
    int m_size;     // 数组大小
    int m_capacity; // 数组容量
};

#endif