#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <iostream>

int readFileList(std::string basePath, std::vector <std::string> &imgPaths)
{
    DIR *dir;
    struct dirent *ptr;
    std::string childDir = basePath;

    if ((dir=opendir(basePath.data())) == NULL)
    {
        perror("Open dir error...");
        exit(1);
    }

    while ((ptr=readdir(dir)) != NULL)
    {
        if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
            continue;
        else if(ptr->d_type == DT_REG)
            imgPaths.push_back(basePath + "/" + ptr->d_name);
        else if(ptr->d_type == DT_DIR)    ///dir
        {
            childDir += "/";
            childDir += ptr->d_name;
            readFileList(childDir.data(), imgPaths);
        }
    }
    closedir(dir);
    return 1;
}

int main()
{
    std::string basePath = "/home/ftpuser/88";
    std::vector <std::string> imgPaths;
    imgPaths.reserve(1024);
    readFileList(basePath.data(), imgPaths);
    std::cout << imgPaths.size() << std::endl;
    std::vector <std::string> errImgPaths;
    errImgPaths = imgPaths;
    while (!errImgPaths.empty()) {
        std::cout << errImgPaths.back() << std::endl;
        errImgPaths.pop_back();
    }
    return 0;
}