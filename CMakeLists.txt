cmake_minimum_required(VERSION 3.10)

project(aed_project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    src/App.cpp
    src/Lecture.cpp
    src/Request.cpp
    src/Script.cpp
    src/Student.cpp
    src/Uc.cpp
    src/main.cpp
)

include_directories(inc)

add_executable(aed_project ${SOURCE_FILES})
