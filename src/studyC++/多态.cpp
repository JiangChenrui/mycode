#include <iostream>
#include <string>
using namespace std;


// 虚析构和纯虚析构
// 动物类
class Animal {
public:
    Animal() {
        cout << "Animal构造函数" << endl;
    }
    // 利用虚析构可以解决 父类指针释放子类对象不干净的问题
    // virtual ~Animal() { 
    //     cout << "Animal析构函数" << endl;
    // }
    // 纯虚析构，需要有具体实现
    // 有了纯虚析构，这个类也属于抽象类，无法实例化对象
    virtual ~Animal() = 0;
    // 加入虚函数
    virtual void speak() = 0;
};

Animal::~Animal() {
    cout << "纯虚析构" << endl;
}

// 猫类
class Cat : public Animal {
public:
    Cat(string name) {
        cout << "cat构造函数" << endl;
        m_Name = new string(name);
    }
    void speak() {
        cout << *m_Name<< "小猫在说话" << endl;
    }
    ~Cat() {
        cout << "Cat析构函数调用" << endl;
        delete m_Name;
        m_Name = NULL;
    }
    string *m_Name;
};

// 狗类
class Dog : public Animal {
public:
    void speak() {
        cout << "狗在说话" << endl;
    }
};

// 执行说话的函数
// 地址早绑定，在编译阶段确定函数地址
// 如果想执行让猫说话，需要使用动态多态，运行阶段再绑定地址

// 动态多态满足条件
// 1.有继承关系
// 2.子类重写父类虚函数（函数返回值，函数名，参数列表完全相同）

// 动态多态使用
// 父类的指针或者引用 执行子类对象
void doSpeak (Animal *animal) {
    animal->speak();
    delete animal;
}

void test01() {
    doSpeak(new Cat("Tome"));
    // 父类指针在析构的时候，不会调用子类的析构函数，如果子类有堆区属性，会有内存泄露的情况
    // doSpeak(new Dog);
}

/**
 * 计算器类
 */
class Calculator {
public:
    // 获取运算结果
    int getResult(string oper) {
        if (oper == "+") {
            return m_Num1 + m_Num2;
        } 
        else if (oper == "-") {
            return m_Num1 - m_Num2;
        }
        else if (oper == "*") {
            return m_Num1 * m_Num2;
        }
        return -1;
        // 如果想扩展新的功能，需要修改源码
        // 在真实开发中，提倡开闭原则
        // 开闭原则：对扩展进行开发，对修改进行关闭
    }
    int m_Num1;
    int m_Num2;
};

void test02() {
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 10;
    cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
    cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
    cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
       
}

// 利用多态实现计算器
// 多态好处
// 1.组织结构清晰
// 2.可读性强
// 3.对于前期和后期扩展及维护性高
class AbstractCalculator {
public:
    // 纯虚函数，有了纯虚函数的类为抽象类
    // 抽象类特点
    // 1.无法实例化对象；
    // 2.抽象类的子类必须重写父类中的纯虚函数，否则也属于抽象类
    virtual int getResult() = 0;

    int m_Num1;
    int m_Num2;
};

// 设计加法计算器类
class AddCalculator : public AbstractCalculator {
public:
    virtual int getResult() {
        return m_Num1 + m_Num2;
    }
};

// 减法计算器类
class SubCalculator : public AbstractCalculator {
public:
    virtual int getResult() {
        return m_Num1 - m_Num2;
    }
};

class MulCalculator : public AbstractCalculator {
public:
    virtual int getResult() {
        return m_Num1 * m_Num2;
    }
};

// 制作饮品
class AbstractDrinking {
public:
    // 煮水
    virtual void Boil() = 0;

    // 冲泡
    virtual void Brew() = 0;

    // 到人杯中
    virtual void PourInCup() = 0;

    // 加入辅料
    virtual void PutSomething() = 0;

    // 制作饮品
    void makeDirink() {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};

// 制作咖啡
class Coffee : public AbstractDrinking {
public:
    // 煮水
    virtual void Boil() {
        cout << "煮农夫山泉" << endl;
    }

    // 冲泡
    virtual void Brew() {
        cout << "冲泡咖啡" << endl;
    }

    // 到人杯中
    virtual void PourInCup()  {
        cout << "倒入杯中" << endl;
    }

    // 加入辅料
    virtual void PutSomething() {
        cout << "加入糖和牛奶" << endl;
    }
};

// 制作茶
class Tea : public AbstractDrinking {
public:
    // 煮水
    virtual void Boil() {
        cout << "煮矿泉水" << endl;
    }

    // 冲泡
    virtual void Brew() {
        cout << "冲泡茶叶" << endl;
    }

    // 到人杯中
    virtual void PourInCup()  {
        cout << "倒入杯中" << endl;
    }

    // 加入辅料
    virtual void PutSomething() {
        cout << "加入枸杞" << endl;
    }
};

void test03() {
    AbstractCalculator *abc = new AddCalculator;
    abc->m_Num1 = 100;
    abc->m_Num2 = 100;
    cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
    // 用完后销毁
    delete abc;

    abc = new SubCalculator;
    cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc;

    abc = new MulCalculator;
    cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc;
}

void doWork(AbstractDrinking * abs) {
    // AbstractDrinking * abs = new Coffee
    abs->makeDirink();
    delete abs;
}

void test04() {
    // 制作咖啡
    doWork(new Coffee);

    cout << "-----------------" << endl;
    doWork(new Tea);
}

// 电脑组装实现
class CPU {
public:
    //　抽象计算函数
    virtual void calculate() = 0;
};

class VideoCard {
public:
    // 抽象显示函数
    virtual void display() = 0;
};

class Memory {
public:
    // 抽象存储函数
    virtual void storage() = 0;
};

// 电脑类
class Computer {
public:
    Computer(CPU *cpu, VideoCard *videoCard, Memory *memory) {
        m_cpu = cpu;
        m_vc = videoCard;
        m_mem = memory;
    }

    void work() {
        m_cpu->calculate();
        m_vc->display();
        m_mem->storage();
    }

    ~Computer() {
        if (m_cpu != NULL) {
            delete m_cpu;
            m_cpu = NULL;
        }
        if (m_vc != NULL) {
            delete m_cpu;
            m_vc = NULL;
        }
        if (m_mem != NULL) {
            delete m_cpu;
            m_mem = NULL;
        }
    }

private:
    CPU *m_cpu;
    VideoCard *m_vc;
    Memory *m_mem;
};

// 具体厂商
class IntelCPU : public CPU {
public:
    virtual void calculate() {
        cout << "Intel cpu" << endl;
    }
};

class IntelVideoCard : public VideoCard {
public:
    virtual void display() {
        cout << "Intel video card" << endl;
    }
};

class IntelMemory : public Memory {
public:
    virtual void storage() {
        cout << "Intel memory" << endl;
    }
};

class AmdCPU : public CPU {
public:
    virtual void calculate() {
        cout << "Amd cpu" << endl;
    }
};

class AmdVideoCard : public VideoCard {
public:
    virtual void display() {
        cout << "Amd video card" << endl;
    }
};

class AmdMemory : public Memory {
public:
    virtual void storage() {
        cout << "Amd memory" << endl;
    }
};

void test05() {
    CPU * intelCpu = new IntelCPU;
    VideoCard * intelCard = new IntelVideoCard;
    Memory * intelMem = new IntelMemory;

    // 创建第一台电脑
    Computer * computer1 = new Computer(intelCpu, intelCard, intelMem);
    computer1->work();
    delete computer1;

    // 创建第二台电脑
    Computer * computer2 = new Computer(new AmdCPU, new AmdVideoCard, new AmdMemory);
    computer2->work();
    delete computer2;
}

int main() {
    test05();
    return 0;
}