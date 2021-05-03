add_library(util util/util.cpp util/util.hpp util/proc.cpp)
target_link_libraries(util ${OpenCV_LIBS})
add_library(imageStitch imageStitch/imageStitch.hpp imageStitch/imageStitch.cpp)
target_link_libraries(imageStitch ${OpenCV_LIBS})