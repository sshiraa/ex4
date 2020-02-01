cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

find_package(Threads)
add_executable(ex4 Main.cpp Server.h ClientHandler.h CacheManager.h Searcher.h Searchable.h StringReverser.h MySerialServer.cpp
        MySerialServer.h cmake-build-debug/ MyTestClientHandler.cpp MyTestClientHandler.h StringReverser.cpp FileCacheManager.cpp
        FileCacheManager.h Main.h MyParallelServer.cpp MyParallelServer.h SocketManager.h ServerArguments.h ClientArguments.h
        IOManager.h SocketManager.cpp MyClientHandler.cpp MyClientHandler.h AstarAlgorithm.cpp AstarAlgorithm.h BestFirstSearch.cpp
        BestFirstSearch.h BFSAlgorithm.cpp BFSAlgorithm.h CompareCost.cpp CompareCost.h DFSAlgorithm.h DFSAlgorithm.cpp
        Isearchable.cpp Isearchable.h Isearcher.cpp Isearcher.h Solver.cpp Solver.h Matrix.cpp Matrix.h MatrixFactory.h
        MatrixFactory.cpp SearcherSolver.cpp SearcherSolver.h SolverAdapter.h SolverAdapter.cpp State.h State.cpp)