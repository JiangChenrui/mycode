# 数据结构和算法学习

## 1 数据结构

&emsp;&emsp;数据结构是计算机内部数据的组织形式和存储方法，常用的数据结构有线性结构、数结构、图结构。

### 1.1 线性结构

&emsp;&emsp;线性结构主要包括：顺序表、链表、栈、队列等基本形式。其中顺序表和链表是从存储形式上（或物理结构上）区分的，而栈和队列是从逻辑功能上区分的。也就是说，顺序表和链表是线性数据结构的基础，队列和栈是基于顺序表和链表的，它们由顺序表或链表构成。

* 栈的实现

```c++
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
```

* 队列的实现

```c++
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
```

### 1.2 树结构

&emsp;&emsp;数据之间存在“一对多”的关系构成了树结构。

```c++
#ifndef MYTREE_HPP
#define MYTREE_HPP
#include <iostream>
using namespace std;

#define TYPE char

//树的节点
struct TreeNode{
    TYPE element;           //该节点的元素
    TreeNode *firstChild;   //指向该节点的第一个孩子
    TreeNode *nextSibling;  //指向该节点的兄弟节点

};

class Tree {
    public:
        Tree(TreeNode * r = NULL):root(r){}
        Tree(int node_num);
        ~Tree();

        void addNode(int i, int j); 
        void preOrder();//前序遍历
        void print();//打印
    private:
        void print(TreeNode* node, int num);
        void addBrotherNode(TreeNode* bro, TreeNode* node);
        void preOrder(TreeNode* parent);//前序遍历
        TreeNode * root;//该树的根
};

//打印树的形状
void Tree::print()
{
    print(root, 0);
}

void printSpace(int num)
{
    int i = 0;
    for(i = 0; i < num-3; i++)
        cout << " ";

    for(; i < num-2; ++i)
        cout << "|";
    for(; i < num; ++i)
        cout << "_";
}


void Tree::print(TreeNode* node, int num)
{
    if(node != NULL){
        printSpace(num); 
        cout << node->element << endl;  
        print(node->firstChild, num+4);
        print(node->nextSibling, num);
    }
}

//前序遍历
void Tree::preOrder()
{
    cout << "前序遍历: ";
    preOrder(root);
    cout << endl;
}

void Tree::preOrder(TreeNode* parent)
{
    if(parent != NULL){
        cout << parent->element << " ";
        preOrder(parent->firstChild);
        preOrder(parent->nextSibling);
    }
}

//分配并初始化所有的树结点
Tree::Tree(int node_num)
{
    root = new TreeNode[node_num];

    char ch = 'A';

    for(int i = 0; i < node_num; ++i){
        root[i].element = ch + i;
        root[i].firstChild = NULL;
        root[i].nextSibling = NULL;
    }

}

//释放所有节点的内存空间
Tree::~Tree()
{
    if(root != NULL)
        delete [] root;
}

//addNode将父子结点组对
//如果父节点的firstChild==NULL, 则firstChild = node;
//如果父节点的firstChild != NULL, 则
void Tree::addNode(int i, int j)
{
    TreeNode* parent = &root[i];
    TreeNode* node = &root[j];

    if(parent->firstChild == NULL)
        parent->firstChild = node;
    else
        addBrotherNode(parent->firstChild, node);
}

//将节点插入到兄弟节点
void Tree::addBrotherNode(TreeNode* bro, TreeNode* node)
{
    if(bro->nextSibling == NULL)
        bro->nextSibling = node;
    else
        addBrotherNode(bro->nextSibling, node);
}

#endif
```


### 1.3 图结构

&emsp;&emsp;图结构中数据元素之间存在着“多对多”的关系。


## 2 算法