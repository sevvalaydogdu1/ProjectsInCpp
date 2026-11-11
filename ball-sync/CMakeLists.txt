cmake_minimum_required(VERSION 3.16)
project(BallSync LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(ball-sync
    src/main.cpp
    src/BallWidget.h
    src/BallWidget.cpp
)

target_link_libraries(ball-sync PRIVATE Qt6::Widgets)

if(MSVC)
    target_compile_options(ball-sync PRIVATE /W4)
else()
    target_compile_options(ball-sync PRIVATE -Wall -Wextra -Wpedantic)
endif()
