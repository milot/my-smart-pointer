project(my-smart-pointer)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

SET(my-smart-pointer_SOURCES main.cpp SmartDeleter.cpp Test.cpp)
SET(my-smart-pointer_HEADERS SmartDeleter.h Test.h)


# Add C++11 support :)
add_definitions (
    -std=c++11
)
