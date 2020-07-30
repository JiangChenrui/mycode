#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <vector>

/**
 * 将字符串分割
 * @param strStreams
 * @param streams
 * @return
 */
int stringToArray(std::string strStreams, std::vector <int> &streams);

/**
 * 校验文件后缀是否为zip
 * @param dir
 * @return
 */
int checkDirIsZip(char *dir);

/**
 * 校验文件是否为jpg图片
 * @param imgPath
 * @return
 */
bool checkIsImage(std::string imgPath);

float round(float f, int bits);

#endif //COMMON_H