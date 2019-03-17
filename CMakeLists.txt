cmake_minimum_required(VERSION 3.13)
project(cs201_portfolio C)

set(CMAKE_C_STANDARD 11)

add_executable(cs201_portfolio src/main.c tests/testMain.c src/fileReader.c src/fileReader.h src/foodItem.c src/foodItem.h)