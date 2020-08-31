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

### 查找和排序

#### 顺序查找

```c++
int search(Student *stu, int n, int  key) {
    for (int i = 0; i < n; ++i) {
        if (stu[i].id == key)
            return i;
    }
    return -1;
}
```

#### 折半查找

```c++
/**
 * 折半查找
 * @param key 关键字顺序表
 * @param n 记录个数
 * @param k 要查找的关键字
 * @return
 */
int bin_search(int *key, int n, int k) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key[mid] == k)
            return mid;
        if (k > key[mid])
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return -1;
}
```

#### 直接插入排序

```c++
/**
 * 直接插入排序
 * @param arr 数组
 * @param n 数组元素个数
 */
void insertSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int temp = arr[i];
        int j = i - 1;
        // for (j; j >= 0; --j) {
        //     if (temp < arr[j]) {
        //         arr[j + 1] = arr[j];
        //     } else {
        //         break;
        //     }
        // }
        // arr[j + 1] = temp;

        while (j >= 0 && temp < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
```

#### 选择排序

```c++
/**
 * 选择排序
 * @param arr 数组
 * @param n 数组元素个数
 */
void selectSort(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int min = i, temp;
        for (int j = i; j < n; ++j) {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i) {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}
```

#### 冒泡排序

```c++
/**
 * 冒泡排序
 * 添加标志变量flag，进行交换flag为真，可以进入下一循环，为进行交换flag为假（数据已有序，无须再进行交换）循环终止。
 * @param arr 数组
 * @param n 数组元素个数
 */
void BubbleSort(int arr[], int n) {
    bool flag = true;
    for (int i = 0; i < n && flag; ++i) {
        flag = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                flag = true;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

#### 希尔排序

```c++
/**
 * 希尔排序
 * 使用do-while是因为flag为2时已经有序，但是flag为1时不是有序的。
 * @param arr 数组
 * @param n 数组元素个数
 */
void shellSort(int arr[], int n) {
    int i, j, gap = n;
    bool flag = true;
    int temp;
    while(gap > 1) {
        gap = gap / 2;
        do {
            flag = false;
            for (i = 0; i < n - gap; ++i) {
                j = i + gap;
                if (arr[i] > arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    flag = true;
                }
            }
        } while(flag);
    }
}
```

#### 快速排序

```c++
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void quick(int arr[], int start, int end) {
    if (start >= end)
        return;
    int left = start, right = end, key = arr[start];
    // 进行循环，将小于基准元素的元素放到左边，大于基准元素的元素放到右边
    while (left < right) {
        while(left < right && arr[right] >= key)
            right--;
        while(left < right && arr[left] <= key)
            left++;
        swap(arr[left], arr[right]);
        // for (int i = 0; i < 10; ++i) {
        //     cout << arr[i] << ' ';
        // }
        // cout << endl;
    }
    // 交换基准元素与left的位置，循环中先从右开始，因此left和right相等的位置为小于基准元素的值
    swap(arr[start], arr[left]);
    quick(arr, start, left - 1);
    quick(arr, left + 1, end);
}
/**
 * 快速排序
 * @param arr 数组
 * @param n 数组元素个数
 */
void quickSort(int arr[], int n) {
    quick(arr, 0, n - 1);
}
```

#### [堆排序](https://www.cnblogs.com/chengxiao/p/6129630.html)

```c++
/**
 * 调整大顶堆
 * @param arr
 * @param i
 * @param len
 */
void adjust(int arr[], int i, int len) {
    int temp = arr[i];
    // 从i结点的左子结点开始，也就是2i+1
    for (int k = 2 * i + 1; k < len; k = k * 2 + 1) {
        // 如果左子结点小于右子结点，k指向右子结点
        if (k + 1 < len && arr[k] < arr[k + 1])
            k++;
        // 如果子结点大于父节点，将子结点的值赋给父节点
        if (arr[k] > temp) {
            arr[i] = arr[k];
            i = k;
        } else {
            break;
        }
    }
    arr[i] = temp;
}

/**
 * 堆排序
 * @param arr 数组
 * @param n 数组元素个数
 */
void headSort(int arr[], int n) {
    int i, temp;
    // 1.构建大顶堆
    for (i = n / 2; i >= 0; --i) {
        // 从第一个非叶子结点从下至上，从右至左调整结构
        adjust(arr, i, n);
    }
    // 2.调整堆结构并交换堆顶元素与末尾元素
    for (int j = n - 1; j > 0; --j) {
        swap(arr[0], arr[j]);
        adjust(arr, 0, j);
    }
}
```