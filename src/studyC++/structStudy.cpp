#include <string>
#include <iostream>
#include <time.h>
using namespace std;

struct Student {
    string name;
    int age;
    int score;
};

struct Teacher {
    string name;
    Student students[5];
};

struct Hero {
    string name;
    int age;
    string sex;
};

/**
 * 赋值函数
 * @param Teacher
 * @param len
 */
void allocateSpace(Teacher teachers[], int len) {
    // 给老师赋值
    srand(time(NULL));
    string nameSeed = "ABCDEFGHIGK";
    for (int i = 0; i < len; ++i) {
        teachers[i].name = "Teacher_";
        teachers[i].name += nameSeed[i];
        // 给学生赋值
        for (int j = 0; j < 5; j++) {
            teachers[i].students[j].name = "Student_";
            teachers[i].students[j].name += nameSeed[j];
            teachers[i].students[j].age = rand() % 20 + 10;
            teachers[i].students[j].score = rand() % 50 + 51;
        }
    }
}

/**
 * 输出老师信息
 * @param Teacher
 */
void printInfo(Teacher teachers[], int len) {
    for (int i = 0; i < len; ++i) {
        cout << "老师名：" << teachers[i].name << endl;
        for (int j = 0; j < 5; ++j) {
            cout << "\t学生姓名：" << teachers[i].students[j].name
                 << "\t考试分数：" << teachers[i].students[j].score
                 << "\t学生年龄：" << teachers[i].students[j].age << endl;
        }
    }
}

void pointer_struct() {
    Student s1 = {"张三", 18, 100};
    Student *p = &s1;
    //结构体指针访问成员使用->
    cout << "name is: " << p->name << endl;
    cout << "age is: " << p->age << endl;
    cout << "score is: " << p->score << endl;
}

/**
 * 输出hero结构体内容
 * @param heros
 * @param len
 */
void printHero(Hero heros[], int len) {
    for (int i = 0; i < len; ++i) {
        cout << "姓名：" << heros[i].name
             << "\t年龄：" << heros[i].age
             << "\t性别：" << heros[i].sex << endl;
    }
}

/**
 * 对年龄进行排序
 * @param heros
 * @param len
 */
void bubbleSort(Hero heros[], int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (heros[j].age > heros[j+1].age) {
                Hero temp = heros[j];
                heros[j] = heros[j+1];
                heros[j+1] = temp;
            }
        }
    }
}

int heroSort() {
    Hero heroArray[5] = {
        {"刘备", 23, "男"},
        {"关羽", 22, "男"},
        {"张飞", 21, "男"},
        {"赵云", 20, "男"},
        {"貂蝉", 19, "女"}
    };

    int len = sizeof(heroArray) / sizeof(heroArray[0]);
    // printHero(heroArray, len);
    bubbleSort(heroArray, len);
    printHero(heroArray, len);
    return 0;
}