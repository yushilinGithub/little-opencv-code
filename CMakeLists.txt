cmake_minimum_required(VERSION 2.8)
project(mining_video_stitch)

find_package(OpenCV REQUIRED)

#include_directories(${OpenCV_INCLUDE_DIRS})
#message(STATUS "include_directories : ${OpenCV_INCLUDE_DIRS}")

add_executable(app main.cpp)
add_subdirectory(src)
target_link_libraries(app ${OpenCV_LIBS} util imageStitch)
message(STATUS "target_link_linraries: ${OpenCV_LIBS}")
