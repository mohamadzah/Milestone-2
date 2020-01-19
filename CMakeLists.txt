cmake_minimum_required(VERSION 3.15)
project(Milestone_2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
add_executable(Milestone_2 main.cpp Server.h MySerialServer.cpp MySerialServer.h MyParallelServer.cpp MyParallelServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h FileCacheManager.cpp FileCacheManager.h CacheManager.h StringReverser.cpp StringReverser.h Searchable.h MyClientHandler.cpp MyClientHandler.h Searcher.h State.h AlgorithmSearchable.cpp AlgorithmSearchable.h Cell.h BestFirstSearch.h CompareCost.h)