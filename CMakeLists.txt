cmake_minimum_required(VERSION 3.23)
project(DA_2022-2023P1)

set(CMAKE_CXX_STANDARD 14)

add_executable(DA_2022-2023P1 main.cpp src/CSVReader.cpp header/CSVReader.h src/Interface.cpp header/Interface.h src/Network.cpp header/Network.h src/Station.cpp header/Station.h)
