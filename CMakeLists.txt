cmake_minimum_required(VERSION 3.10)
PROJECT(TESTUNZIP)
set(CMAKE_CXX_STANDARD 11)

include_directories(src/include src/include/minizip)
set(UNZIP src/unzip/testUnzip.cpp src/unzip/ioapi.c src/unzip/unzip.c)
link_directories(lib/hisi)

add_executable(testUnzip ${UNZIP})
target_link_libraries(testUnzip z)