cmake_minimum_required(VERSION 3.6)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BoardArray.cpp BoardArray.h ColorManagement.h ColorManagement.cpp Move.cpp Move.h RuleBook.cpp RuleBook.h Play.cpp Play.h Player.h AutoPlayer.cpp AutoPlayer.h Game.cpp Game.h Player.cpp NeuralNetwork.cpp NeuralNetwork.h Brain.cpp Brain.h)
add_executable(untitled ${SOURCE_FILES})