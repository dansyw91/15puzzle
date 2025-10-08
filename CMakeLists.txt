cmake_minimum_required(VERSION 3.10)
project(15puzzle)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(15puzzle
    src/Tile.cpp
    src/Board.cpp 
    src/UserInput.cpp
    src/main.cpp
    src/Direction.cpp
    src/Point.cpp
)
