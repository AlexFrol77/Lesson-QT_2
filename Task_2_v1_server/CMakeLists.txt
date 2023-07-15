cmake_minimum_required(VERSION 3.14)

project(Task_2_v1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Network)

add_executable(Task_2_v1
  main.cpp
  server.h
  server.cpp
)
target_link_libraries(Task_2_v1 Qt6::Core
                                Qt6::Network)
