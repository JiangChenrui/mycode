#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream> 
#include <iomanip> 

/**
 * 将字符串分割
 * @param strStreams
 * @param streams
 * @return
 */
int stringToArray(std::string strStreams, std::vector <int> &streams) {
    if (strStreams.empty()) {
        return -1;
    }
    //用,分割strStreams
    const char *split = ",";
    char *p;
    p = strtok((char*)strStreams.data(), split);
    while(p) {
        streams.push_back(std::stoi(p));
        p = strtok(NULL, split);
    }
    return 0;
}

/**
 * 校验文件后缀是否为zip
 * @param dir
 * @return
 */
int checkDirIsZip(char *dir) {
    int ret = 0;
    char *p;
    char *ptr;
    const char *split = ".";
    p = strtok(dir, split);
    if (p == "zip")
        return -1;
    while(p) {
        ptr = p;
        p = strtok(NULL, split);
    }
    ret = strcmp(ptr, "zip");
    return ret;
}

/**
 * 校验文件后缀是否为zip
 * @param dir
 * @return
 */
bool checkIsImage(std::string imgPath) {
    if (imgPath.empty())
        return false;
    std::string type = imgPath.substr(imgPath.find_last_of('.') + 1);
    if (type.compare("jpg") == 0 || type.compare("jpeg") == 0)
        return true;
    else 
        return false;
}