# 图片base64转二进制

http传递的图片含有“data:image/jpg;base64,”前缀，会对base64的解码造成影响，
在上传图片代码中使用正则表达式匹配字符串并删除前缀。

# cmake

    cmake -DCMAKE_TOOLCHAIN_FILE=../aarch64-himix100-linux.toolchain.cmake ..