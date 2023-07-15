cmake_minimum_required(VERSION 3.5)

project(Task_2_v1_client VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Network)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

add_executable(Task_2_v1_client
               ${PROJECT_SOURCES})

target_link_libraries(Task_2_v1_client PRIVATE Qt6::Widgets
                                               Qt6::Network)



