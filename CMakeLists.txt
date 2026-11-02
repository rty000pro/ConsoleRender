cmake_minimum_required(VERSION 3.0)

project(ConsoleRender LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#################################


#find_package(Boost REQUIRED COMPONENTS program_option)


#################################

add_executable(ConsoleRender
    src/main.cpp
    src/engine/Screen.cpp
    src/engine/Screen.h
    src/engine/GraphScreen.cpp 
    src/engine/GraphScreen.h
)

#target_link_libraries(test1 PRIVATE
#    Boost:program_option
#)