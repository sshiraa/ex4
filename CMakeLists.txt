cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

find_package(Threads)
add_executable(ex4 main.cpp Server.h ClientHandler.h Solver.h CacheManager.h Searcher.h Searchable.h StringReverser.h mySerialServer.cpp
        mySerialServer.h cmake-build-debug/ MyTestClientHandler.cpp MyTestClientHandler.h StringReverser.cpp)