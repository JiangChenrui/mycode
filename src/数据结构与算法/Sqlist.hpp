#ifndef SQLIST_H
#define SQLIST_H
#include <stdio.h>
#include <iostream>

class Sqlist {
public:
    /**
     * 构造函数
     * @param size
     */
    Sqlist(int size);
    /**
     * 析构函数
     */
    ~Sqlist();
    /**
     * 在指定位置插入元素
     * @param position 位置
     * @param num 数字大小
     * @return
     */
    int Insert(int position, int num);
    /**
     * 删除指定位置元素
     * @param position 位置
     * @return
     */
    int Delete(int position);
    /**
     * 输出顺序表
     */
    void PrintSqlist();
    /**
     * 清空顺序表
     */
    int Remove();
private:
    int *data;      // 数组
    int len;        // 数组元素个数
    int size;       // 数组大小
};


/**
 * 构造函数
 * @param size
 */
Sqlist::Sqlist(int size) {
    this->data = new int[size];
    this->len = 0;
    this->size = size;
}
/**
 * 析构函数
 */
Sqlist::~Sqlist() {
    if (this->data != NULL) {
        delete [] this->data;
        this->data = NULL;
    }
    this->len = 0;
}
/**
 * 在指定位置插入元素
 * @param position 位置
 * @param num 数字大小
 * @return
 */
int Sqlist::Insert(int position, int num) {
    if (position > this->len + 1) {
        return -1;
    }
    if (position == this->len + 1) {
        this->data[len] = num;
        this->len++;
        return 0;
    }
    for (int i = len; i >= position; --i) {
        this->data[i] = this->data[i-1];
    }
    this->len++;
    this->data[position-1] = num;
    return 0;
}
/**
 * 删除指定位置元素
 * @param position 位置
 * @return
 */
int Sqlist::Delete(int position) {
    if (position > this->len) {
        return -1;
    }
    if (position == this->len) {
        this->len--;
        return 0;
    }
    for (int i = position - 1; i < this->len - 1; ++i) {
        this->data[i] = this->data[i+1];
    }
    this->len--;
    return 0;
}
/**
 * 输出顺序表
 */
void Sqlist::PrintSqlist() {
    if (this->len == 0) {
        std::cout << "顺序表为空" << std::endl;
        return;
    }
    for (int i = 0; i < this->len; ++i) {
        std::cout << this->data[i] << ' ';
    }
    std::cout << std::endl;
}
/**
 * 清空顺序表
 */
int Sqlist::Remove() {
    this->len = 0;
    return 0;
}
#endif