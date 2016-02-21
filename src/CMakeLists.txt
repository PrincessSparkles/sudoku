#
# CMakeLists.txt
#
# cmake file for sudoku project
# inspired by http://rix0r.nl/blog/2015/08/13/cmake-guide/
#
# (c) 2016 Richard Oak
#

# At least 3.2, but newer is better!
cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 14)

project(sudoku VERSION 0.1 LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../cmake")

enable_testing()

# our targets
add_subdirectory(libsudoku)
add_subdirectory(sudoku)
