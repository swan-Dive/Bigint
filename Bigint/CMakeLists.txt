cmake_minimum_required(VERSION 2.6)
project(MAINBIGINT)
set(SOURCES main.cpp)
include_directories("header_folder")
add_subdirectory(header_folder)

add_executable(MainBigInt ${SOURCES})

target_link_libraries(MainBigInt BigInteger)