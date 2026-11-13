cmake_minimum_required(VERSION 3.16)
project(Pong LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(pong WIN32
    src/main.cpp
    src/colors.h
    src/GameWindow.h
    src/GameWindow.cpp
    src/renderer.h
    src/renderer.cpp
    src/game.h
    src/game.cpp
)

target_link_libraries(pong PRIVATE Qt6::Widgets)

if(MSVC)
    target_compile_options(pong PRIVATE /W4)
else()
    target_compile_options(pong PRIVATE -Wall -Wextra -Wpedantic)
endif()
