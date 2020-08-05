#ifndef ADRESSBOOKMANAGE_H
#define ADRESSBOOKMANAGE_H
#include <string>
#define MAX 1000

struct Person {
    std::string name;
    int sex; // 1 男  2 女
    std::string phone;
    std::string addr;
};

struct AddressBooks {
    Person personArray[MAX];
    int size;
};

/**
 * 初始化通讯录
 */
void initAddressBooks(AddressBooks &abs);

/**
 * 添加联系人
 */
void addPerson(AddressBooks *abs);

/**
 * 显示联系人
 */
void printPerson(AddressBooks &abs);

/**
 * 删除联系人
 */
void delPerson(AddressBooks &abs);

/**
 * 查找联系人
 */
void selectPerson(AddressBooks &abs);

/**
 * 修改通讯录
 */
void modifyPerson(AddressBooks &abs);

/**
 * 清空联系人
 */
void clearAddressBooks(AddressBooks &abs);

/**
 * 显示用户菜单
 */
void showMenu();

/**
 * 按任意键继续
 */
void waitForAnyKey();

/**
 * 查询用户是否存在
 * @param AddressBooks
 * @param name
 * @return
 */
int isExist(AddressBooks &abs, std::string name);

#endif //ADRESSBOOKMANAGE_H