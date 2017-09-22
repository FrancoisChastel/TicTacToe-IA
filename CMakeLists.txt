cmake_minimum_required(VERSION 3.3)
project(TicTacToe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp constants.hpp deadline.hpp gamestate.cpp gamestate.hpp move.hpp player.cpp player.hpp)
add_executable(TicTacToe ${SOURCE_FILES})