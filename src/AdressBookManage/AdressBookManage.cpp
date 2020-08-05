#include <iostream>
#include <string>
#include <sstream>
#include "AdressBookManage.h"

using std::cout;
using std::cin;
using std::endl;

void showMenu() {
    std::cout << "********************************" << std::endl;
    std::cout << "********  1.添加联系人  ********" << std::endl;
    std::cout << "********  2.显示联系人  ********" << std::endl;
    std::cout << "********  3.删除联系人  ********" << std::endl;
    std::cout << "********  4.查找联系人  ********" << std::endl;
    std::cout << "********  5.修改联系人  ********" << std::endl;
    std::cout << "********  6.清空联系人  ********" << std::endl;
    std::cout << "********  0.退出通讯录  ********" << std::endl;
    std::cout << "********************************" << std::endl;
}

/**
 * 初始化通讯录
 */
void initAddressBooks(AddressBooks &abs) {
    abs.size = 0;
}

/**
 * 添加联系人
 */
void addPerson(AddressBooks *abs) {
    if (abs->size > MAX) {
        std::cout << "通讯录已满，无法添加！" << std::endl;
        waitForAnyKey();
        return;
    }
    std::string name;
    std::cout << "请输入姓名： " << std::endl;
    std::cin >> name;
    abs->personArray[abs->size].name = name;

    int sex = 0;
    while(sex != 1 && sex != 2) {
        std::cout << "请输入性别：" << std::endl;
        std::cout << "1 --- 男" << std::endl;
        std::cout << "2 --- 女" << std::endl;
        std::cin >> sex;
        abs->personArray[abs->size].sex = sex;
    }

    std::cout << "请输入电话：" << std::endl;
    std::string phone;
    std::cin >> phone;
    abs->personArray[abs->size].phone = phone;

    std::cout << "请输入地址：" << std::endl;
    std::string addr;
    std::cin >> addr;
    abs->personArray[abs->size].addr = addr;

    abs->size++;
    std::cout << "用户添加成功" << std::endl;
    waitForAnyKey();
}

/**
 * 显示联系人
 */
void printPerson(AddressBooks &abs) {
    if (abs.size == 0) {
        std::cout << "通讯录为空" << std::endl;
        waitForAnyKey();
        return;
    }
    for (int i = 0; i < abs.size; ++i) {
        std::cout << abs.personArray[i].name<< "\t"
                  << ((abs.personArray[i].sex == 1) ? "男" : "女") << "\t"
                  << abs.personArray[i].phone<< "\t"
                  << abs.personArray[i].addr << std::endl;
    }
    waitForAnyKey();
}

/**
 * 删除联系人
 */
void delPerson(AddressBooks &abs) {
    if (abs.size == 0) {
        std::cout << "通讯录为空" << std::endl;
        system("clear");
        return;
    }
    std::string name;
    std::cout << "请输入要删除的用户名" << std::endl;
    std::cin >> name;
    int ret = isExist(abs, name);
    if (ret == -1) {
        cout << "查无此人" << endl;
        waitForAnyKey();
        return;
    }
    for (int i = ret; i < abs.size - 1; ++i) {
        abs.personArray[i] = abs.personArray[i+1];
    }
    abs.size--;
    waitForAnyKey();
}

/**
 * 查找联系人
 */
void selectPerson(AddressBooks &abs) {
    if (abs.size == 0) {
        std::cout << "通讯录为空" << std::endl;
        system("clear");
        return;
    }
    std::string name;
    std::cout << "请输入用户名" << std::endl;
    std::cin >> name;
    int ret = isExist(abs, name);
    if (ret == -1) {
        cout << "查无此人" << endl;
        waitForAnyKey();
        return;
    }
    std::cout << abs.personArray[ret].name<< "\t"
                << ((abs.personArray[ret].sex == 1) ? "男" : "女") << "\t"
                << abs.personArray[ret].phone<< "\t"
                << abs.personArray[ret].addr << std::endl;
    waitForAnyKey();
}

/**
 * 修改通讯录
 */
void modifyPerson(AddressBooks &abs) {
    if (abs.size == 0) {
        std::cout << "通讯录为空" << std::endl;
        system("clear");
        return;
    }
    std::string name;
    std::cout << "请输入用户名" << std::endl;
    std::cin >> name;
    int ret = isExist(abs, name);
    if (ret == -1) {
        cout << "查无此人" << endl;
        waitForAnyKey();
        return;
    }
    for (int i = 0; i < abs.size; ++i) {
        if (abs.personArray->name == name) {
            std::string name;
            std::cout << "请输入姓名： " << std::endl;
            std::cin >> name;
            abs.personArray[i].name = name;

            int sex = 0;
            while(sex != 1 && sex != 2) {
                std::cout << "请输入性别：" << std::endl;
                std::cout << "1 --- 男" << std::endl;
                std::cout << "2 --- 女" << std::endl;
                std::cin >> sex;
                abs.personArray[i].sex = sex;
            }

            std::cout << "请输入电话：" << std::endl;
            std::string phone;
            std::cin >> phone;
            abs.personArray[i].phone = phone;

            std::cout << "请输入地址：" << std::endl;
            std::string addr;
            std::cin >> addr;
            abs.personArray[i].addr = addr;
            waitForAnyKey();
            return;
        }
    }
    cout << "查无此人" << endl;
    waitForAnyKey();
}

/**
 * 清空联系人
 */
void clearAddressBooks(AddressBooks &abs) {
    abs.size = 0;
    waitForAnyKey();
}

/**
 * 按任意键继续
 */
void waitForAnyKey() {
    cout << "请按任意键继续" << endl;
    cin.clear();
    cin.sync();
    cin.get();
}

/**
 * 查询用户是否存在
 * @param AddressBooks
 * @param name
 * @return
 */
int isExist(AddressBooks &abs, std::string name) {
    for (int i = 0; i < abs.size; ++i) {
        if (abs.personArray[i].name == name) {
            return i;
        }
    }
    return -1;
}