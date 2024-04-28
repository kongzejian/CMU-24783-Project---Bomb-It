cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(../../public/src ${CMAKE_BINARY_DIR}/public)

add_subdirectory(simplewindow)
add_subdirectory(bitmap)
add_subdirectory(main)
add_subdirectory(sound)