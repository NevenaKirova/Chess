cmake_minimum_required(VERSION 3.15)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chess main.cpp Game.cpp Game.h Piece.cpp Piece.h)