## 图片base64转二进制

http传递的图片含有“data:image/jpg;base64,”前缀，会对base64的解码造成影响，
在上传图片代码中使用正则表达式匹配字符串并删除前缀。

## cmake

    cmake -DCMAKE_TOOLCHAIN_FILE=../aarch64-himix100-linux.toolchain.cmake ..

## [c++ string char* char[]互相转换](https://blog.csdn.net/yzhang6_10/article/details/51164300)

## [vscode调试c++工程](http://alanli7991.github.io/2019/12/10/CMake10%E4%B8%8D%E5%90%8CIDE%E7%9A%84%E5%B7%AE%E5%88%AB%E5%92%8C%E9%80%89%E6%8B%A9/)

[参考网站](https://zhuanlan.zhihu.com/p/52874931)

## vscode文件地址

* $workspaceRoot：在VS Code中打开的文件夹的路径 
* $dir：正在运行的代码文件的目录 
* $dirWithoutTrailingSlash：运行的代码文件目录不带斜杠 
* $fullFileName：正在运行的代码文件的全名 
* $fileName：正在运行的代码文件的基本名称，即没有目录的文件 
* $fileNameWithoutExt：代码文件的基本名称，不带扩展名