cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex4 main.cpp Server.h ClientHandler.h Solver.h CacheManager.h Searcher.h cmake-build-debug/Searchable.h Solution.cpp Solution.h mySerialServer.cpp mySerialServer.h)