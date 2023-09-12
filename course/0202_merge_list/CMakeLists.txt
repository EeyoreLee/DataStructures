cmake_minimum_required(VERSION 3.14)
project(MergeList)
set(CMAKE_C_STANDARD 11)

get_filename_component(COURSE ${CMAKE_SOURCE_DIR} DIRECTORY)

include_directories(${COURSE}/Status)

add_subdirectory(${COURSE}/Status Status)

add_executable(MergeList SqList.c MergeList.c MergeList-main.c)
target_link_libraries(MergeList Status)