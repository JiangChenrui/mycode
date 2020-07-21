#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include <iostream>
#include <queue>
#include <regex>
#include <string>
#include <vector>

using namespace std;
const char *IMAGE_DIR = "/home/ftpuser/data";
const char *NEW_IMAGE_DIR = "/home/ftpuser/camera";

int main() {
    // 打开文件夹
    struct dirent *ptr;
    vector<clock_t> time(10);
    queue<string> imgque;
    DIR *dir;
    dir = opendir(IMAGE_DIR);
    printf("文件列表:\n");
    string re = ".*\\.jpg";
    regex reg(re);

    while ((ptr = readdir(dir)) != NULL) {
        if (regex_match(ptr->d_name, reg)) {
            char *temp = new char(strlen(IMAGE_DIR) + strlen(ptr->d_name) + 2);
            sprintf(temp, "%s/%s", IMAGE_DIR, ptr->d_name);
            // cout << temp << endl;
            imgque.push(temp);
            char *new_image_path =
                new char(strlen(NEW_IMAGE_DIR) + strlen(ptr->d_name) + 2);
            sprintf(new_image_path, "%s/%s", NEW_IMAGE_DIR, ptr->d_name);
            cout << imgque.front().c_str() << ' '
                 << rename(imgque.front().c_str(), new_image_path) << endl;
            // imgque.pop();
        }
    }
    // while(!imgque.empty()) {
    // 	imgque.pop();
    // }
    closedir(dir);
    return 0;
}
