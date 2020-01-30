cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

find_package(Threads)
add_executable(ex4 Main.cpp Server.h ClientHandler.h Solver.h CacheManager.h Searcher.h Searchable.h StringReverser.h MySerialServer.cpp
        MySerialServer.h cmake-build-debug/ MyTestClientHandler.cpp MyTestClientHandler.h StringReverser.cpp FileCacheManager.cpp FileCacheManager.h Main.h MyParallelServer.cpp MyParallelServer.h)