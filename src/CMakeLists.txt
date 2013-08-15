project(my-smart-pointer)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

SET(my-smart-pointer_SOURCES main.cpp SmartPointer.cpp Exceptions.cpp Test.cpp SmartSharedPointer.cpp ReferenceCounter.cpp)
SET(my-smart-pointer_HEADERS SmartPointer.h Exceptions.h Test.h SmartSharedPointer.h ReferenceCounter.h)


# Add C++11 support :)
add_definitions (
    -std=c++11
)
