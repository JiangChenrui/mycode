cmake_minimum_required(VERSION 3.10)
PROJECT(TESTUNZIP)
set(CMAKE_CXX_STANDARD 11)

include_directories(src/include src/include/minizip)
link_directories(lib)

set(UNZIP src/unzip/testUnzip.cpp src/unzip/ioapi.c src/unzip/unzip.c)
set(COMMON src/include/common.h src/include/common.cpp)
set(ADRESSBOOK src/AdressBookManage/AdressBookManage.cpp
               src/AdressBookManage/AdressBookManage.h
               src/AdressBookManage/main.cpp)
               
add_executable(testUnzip ${UNZIP})
target_link_libraries(testUnzip z)

add_executable(getDirPath src/getDirPath/getDirPath.cpp)

add_executable(setTime src/cgi/setTime.cpp)

add_executable(main main.cpp ${COMMON})

add_executable(AdressBookManage src/AdressBookManage/main.cpp ${ADRESSBOOK})