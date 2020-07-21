#include <string>

using namespace std;
std::string getImgName(string imgPath) {
    int pos = imgPath.find_last_of('/');
    std::string imgName(imgPath.substr(pos + 1));
    imgName.erase(imgName.end() - 4, imgName.end());
    if (imgName.back() == '.')
        imgName.pop_back();
    return imgName;
}
int main() {
    int img_work = 8123;
    int img_count = 123123;
    cout <<  ((float) (int)((img_work / (float) img_count) * 100)) / 100 << endl;
    return 0;
}