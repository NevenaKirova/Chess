cmake_minimum_required(VERSION 3.15)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chess main.cpp Game.cpp Game.h Piece.cpp Piece.h Pawn.h Rook.h Knight.h Bishop.h King.h Queen.h Board.cpp Board.h Pawn.cpp Queen.cpp Rook.cpp Knight.cpp Bishop.cpp King.cpp Moves.cpp Moves.h)