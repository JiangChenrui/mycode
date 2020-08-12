#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

#define CEHUA 0
#define MEISHU 1
#define KAIFA 2

class Worker {
public:
    string m_name;
    int m_salary;
};

void createWorker(vector<Worker> & v) {
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; ++i) {
        Worker worker;
        worker.m_name = "员工";
        worker.m_name += nameSeed[i];
        worker.m_salary = rand() % 10000 + 10000;

        v.push_back(worker);
    }
}

// 员工分组
void setGroup(vector<Worker> &v, multimap<int, Worker> &m) {
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); ++it) {
        // 产生随机部门编号
        int deptId = rand() % 3;

        // key为部门编号，*it为员工
        m.insert(make_pair(deptId, *it));
    }
}

void showWorkerByGroup(multimap<int, Worker> &m) {
    cout << "策划部门：" << endl;
    multimap<int, Worker>::iterator pos =  m.find(CEHUA);
    int count = m.count(CEHUA);
    for (int index = 0; pos != m.end() && index < count; ++pos, ++index) {
        cout << "姓名：" << pos->second.m_name << "\t工资：" 
             << pos->second.m_salary << endl;
    }
    cout << "------------------------" << endl;
    cout << "美术部门：" << endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU);
    for (int index = 0; pos != m.end() && index < count; ++pos, ++index) {
        cout << "姓名：" << pos->second.m_name << "\t工资：" 
             << pos->second.m_salary << endl;
    }
    cout << "------------------------" << endl;
    cout << "开发部门：" << endl;
    pos = m.find(KAIFA);
    count = m.count(KAIFA);
    for (int index = 0; pos != m.end() && index < count; ++pos, ++index) {
        cout << "姓名：" << pos->second.m_name << "\t工资：" 
             << pos->second.m_salary << endl;
    }
    cout << "------------------------" << endl;

}

int main() {    
    srand(time(NULL));
    // 1.创建员工
    vector<Worker> vWorker;
    createWorker(vWorker);

    // ２.员工分组
    multimap<int, Worker> mWorker;
    setGroup(vWorker, mWorker);

    // ３.分组显示
    showWorkerByGroup(mWorker);
    // // 测试
    // for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); ++it) {
    //     cout << "姓名：" << it->m_name << "\t工资：" << it->m_salary << endl;
    // }
    return 0;
}