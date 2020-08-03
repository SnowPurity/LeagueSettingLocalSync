cmake_minimum_required(VERSION 3.17)
project(leagueSettingBackUp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
add_executable(leagueSettingBackUp main.cpp)