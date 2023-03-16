cmake_minimum_required(VERSION 3.23)
project(DAGrupo)

set(CMAKE_CXX_STANDARD 14)

add_executable(DAGrupo main.cpp src/CSVReader.cpp header/CSVReader.h src/Interface.cpp header/Interface.h src/Network.cpp header/Network.h src/Station.cpp header/Station.h src/graph.cpp header/graph.h)
