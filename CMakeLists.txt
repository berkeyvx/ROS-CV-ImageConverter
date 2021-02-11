cmake_minimum_required(VERSION 3.5)

project(ImageConverter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  cv_bridge
  sensor_msgs
  image_transport
)

include_directories(
  "include/"
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable( image_convert_node
                src/Converter.cpp 
                include/Converter.hpp)

target_link_libraries(image_convert_node
   ${catkin_LIBRARIES}
   ${OpenCV_LIBS}
)
