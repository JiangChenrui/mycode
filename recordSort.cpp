#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#define MAX_SIZE 128

using namespace std;
class Record {
public:
    Record(int id, unsigned char* gender, short depart, int age) {
        this->id = id;
        this->gender = gender;
        this->depart = depart;
        this->age = age;
    }
    int id;
    unsigned char* gender;
    short depart;
    int age;
};

class compareRecord {
public:
    bool operator() (const Record &r1, const Record &r2) {
        return r1.id > r2.id;
    }
};

vector<string> split(const string &str, const string &splitChar) {
    vector<string> res;
    if (str == "")
        return res;
    string strs = str + splitChar;
    size_t pos = strs.find(splitChar);

    while (pos != strs.npos) {
        string temp = strs.substr(0, pos);
        res.push_back(temp);
        strs = strs.substr(pos+1, strs.size());
        pos = strs.find(splitChar);
    }
    return res;
}

int foo(const char* filename, vector<Record> &list) {
    set<Record, compareRecord> minRecord;
    ifstream ifs;

    ifs.open("test.txt", ios::in);
    if (!ifs.is_open()) return -1;

    int res = 0;
    string buf;
    while (getline(ifs, buf)) {
        vector<string> temp = split(buf, "\t");
        Record r(stoi(temp[0]), (unsigned char*)temp[1].c_str(), stoi(temp[2]), stoi(temp[3]));
        if (minRecord.size() < MAX_SIZE) minRecord.insert(r);
        else {
            if (r.id < minRecord.begin()->id) {
                minRecord.erase(minRecord.begin());
                minRecord.insert(r);
            }
        }
    }
    ifs.close();
    for (set<Record, compareRecord>::iterator it = minRecord.begin(); it != minRecord.end(); ++it) {
        Record r(it->id, it->gender, it->depart, it->age);
        list.push_back(r);
    }
    return minRecord.size();
}

int main() {
    const char* filename = "test.txt";
    vector<Record> list;
    int res = foo(filename, list);
    cout << res << endl;
    return 0;
}