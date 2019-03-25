cmake_minimum_required(VERSION 3.13)
project(cs201_portfolio C)

set(CMAKE_C_STANDARD 11)

add_executable(cs201_portfolio src/main.c tests/testMain.c src/dataLoader.c src/dataLoader.h src/foodItem.c src/foodItem.h src/sll.h src/sll.c src/hashtable.c src/hashtable.h src/userInterface.c src/userInterface.h src/interfaceController.c src/interfaceController.h src/logger.c src/logger.h)