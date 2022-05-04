cmake_minimum_required(VERSION 3.21)
project(Hra)

set(CMAKE_CXX_STANDARD 20)

add_executable(Hra main.cpp GameEngine.cpp GameEngine.h Village.cpp Village.h Building.cpp Building.h ResourceTable.cpp ResourceTable.h)
