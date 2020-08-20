#ifndef LINKLIST_HPP
#define LINKLIST_HPP
#include<iostream>
using namespace std;
 
typedef int DataType;
#define Node ElemType
#define ERROR NULL
 
//构建一个节点类
class Node                          
{
public:
    int data;     //数据域
    Node * next;  //指针域
};
 
//构建一个单链表类
class LinkList                      
{
public:
    LinkList();                   //构建一个单链表;
    ~LinkList();                  //销毁一个单链表;
    void CreateLinkList(int n);   //创建一个单链表
    void TravalLinkList();        //遍历线性表
    int GetLength();              //获取线性表长度
    bool IsEmpty();               //判断单链表是否为空
    ElemType * Find(DataType data); //查找节点
    void InsertElemAtEnd(DataType data);            //在尾部插入指定的元素
    void InsertElemAtIndex(DataType data,int n);    //在指定位置插入指定元素
    void InsertElemAtHead(DataType data);           //在头部插入指定元素
    void DeleteElemAtEnd();       //在尾部删除元素
    void DeleteAll();             //删除所有数据
    void DeleteElemAtPoint(DataType data);     //删除指定的数据
    void DeleteElemAtHead();      //在头部删除节点
private:
    ElemType * head;              //头结点
};

// 构造函数
LinkList::LinkList() {
    this->head = new ElemType;
    this->head->data = 0;
    this->head->next = NULL;
}

// 析构函数
LinkList::~LinkList() {
    delete this->head;
}

// 创建单链表
void LinkList::CreateLinkList(int n) {
    ElemType *ptemp, *qnew;
    ptemp = head;
    if (n < 0) {
        cout << "输入的链表长度有误" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; ++i) {
        qnew = new ElemType;
        cout << "请输入第" << i + 1 << "个值: ";
        cin >> qnew->data;
        qnew->next = NULL;

        ptemp->next = qnew;
        ptemp = qnew;
    }
}

// 遍历链表
void LinkList::TravalLinkList() {
    if (this->head == NULL || this->head->next == NULL) {
        cout << "链表为空" << endl;
        return;
    }
    ElemType *p = head->next;
    while (p != NULL) {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

// 获取链表长度
int LinkList::GetLength() {
    if (this->head == NULL || this->head->next == NULL) {
        cout << "链表为空" << endl;
        return -1;
    }
    ElemType *p = head->next;
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

// 判断链表是否为空
bool LinkList::IsEmpty() {
    if (this->head == NULL || this->head->next == NULL)
        return true;
    else 
        return false;
}

// 查找节点
ElemType *LinkList::Find(DataType data) {
    ElemType *p = this->head;
    if (IsEmpty()) {
        return ERROR;
    }
    while (p->next != NULL) {
        if (p->data == data) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// 在尾部插入指定元素
void LinkList::InsertElemAtEnd(DataType data) {
    ElemType *p = this->head;
    ElemType *qnew = new ElemType;
    qnew->data = data;
    qnew->next = NULL;
    if (IsEmpty()) {
        this->head = qnew;
    } else {
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = qnew;
    }
}

// 在指定位置插入指定元素
void LinkList::InsertElemAtIndex(DataType data, int n) {
    int count = 0;
    if (n < 1 || n > this->GetLength()) {
        cout << "输入的位置有误" << endl;
    } else {
        ElemType *ptemp = new ElemType;
        ptemp->data = data;
        ElemType *p = this->head;
        while (n != count) {
            p = p->next;
            count++;
        }
        ptemp->next = p->next;
        p->next = ptemp;
    }
}

// 在头部插入指定元素
void LinkList::InsertElemAtHead(DataType data) {
    ElemType *pnew = new ElemType;
    pnew->data = data;
    pnew->next = this->head->next;
    this->head->next = pnew;
}

// 在尾部删除元素
void LinkList::DeleteElemAtEnd() {
    ElemType *p = this->head;
    ElemType *ptemp = NULL;
    if (p->next == NULL) {
        cout << "单链表为空" << endl;
    } else {
        while (p->next != NULL) {
            ptemp = p;
            p = p->next;
        }
        delete p;
        p = NULL;
        ptemp->next = NULL;
    }
}

// 删除所有数据
void LinkList::DeleteAll() {
    ElemType *p = this->head->next;
    ElemType *ptemp = NULL;
    while( p != NULL) {
        ptemp = p;
        p = p->next;
        ptemp->next = NULL;
        delete ptemp;
    }
    this->head->next = NULL;
}

// 删除指定数据
void LinkList::DeleteElemAtPoint(DataType data) {
    ElemType *ptemp = Find(data);
    if (ptemp == this->head->next) {
        DeleteElemAtHead();
    } else {
        ElemType *p = this->head;
        while (p->next != ptemp) {
            p = p->next;
        }
        p->next = ptemp->next;
        delete ptemp;
        ptemp = NULL;
    }
}

// 在头部删除节点
void LinkList::DeleteElemAtHead() {
    ElemType *p = this->head;
    if (IsEmpty()) {
        cout << "链表为空" << endl;
        return;
    }
    ElemType *ptemp = NULL;
    ptemp = p->next;
    p->next = ptemp->next;
    delete ptemp;
    ptemp = NULL;
}

#endif