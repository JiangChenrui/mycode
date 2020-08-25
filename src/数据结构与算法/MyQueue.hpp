#ifndef MYQUEUE_HPP
#define MYQUEUE_HPP
#include <iostream>
using namespace std;

template <typename T>
struct QueueNode {
    T data;
    QueueNode *next;
    QueueNode () {
        this->next = NULL;
    }
};

template <class T>
class MyQueue {
public:
    MyQueue() {
        this->count = 0;
        this->head = new QueueNode <T>();
        this->tail = new QueueNode <T>();
        this->tail = this->head;
    }
    ~MyQueue() {
        if (this->head != NULL) {
            cout << "释放head" << endl;
            delete[] this->head;
            this->head = NULL;
        }
        if (this->tail != NULL) {
            cout << "释放tail" << endl;
            delete[] this->tail;
            this->tail = NULL;
        }
    }
    int size() {
        return this->count;
    }
    bool IsEmpty() {
        if (size() == 0) {
            return true;
        } else {
            return false;
        }
    }
    void InQueue(T val) {
        QueueNode <T> *temp = new QueueNode<T>();
        temp->data = val;
        this->tail->next = temp;
        this->tail = temp;
        this->count++;
    }
    QueueNode<T>* OutQueue() {
        if (this->count == 0) {
            cout << "队列为空" << endl;
            return NULL;
        }
        QueueNode <T> *temp = this->head->next;
        if (temp) {
            this->head->next = temp->next;
            temp->next = NULL;
            this->count--;
        }
        return temp;
    }
    void QueueTraverse() {
        if (this->count == 0) {
            cout << "队列为空" << endl;
            return;
        }
        QueueNode <T> *temp = head->next;
        while (temp) {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;
    }
    void Remove() {
        this->head->next = NULL;
        this->tail = this->head;
        this->count = 0;
    }

private:
    int count;
    QueueNode <T> *head;
    QueueNode <T> *tail;
};

#endif