#
# CMakeLists.txt
#
# cmake file for sudoku library
# inspired by http://rix0r.nl/blog/2015/08/13/cmake-guide/
#
# (c) 2016 Richard Oak
#

# Define library. Only source files here!
project(libsudoku VERSION 0.1 LANGUAGES CXX)

Include(CodeCoverage)

add_library(sudoku
    src/puzzle.cpp
    src/sudoku.cpp)

set_property(TARGET sudoku PROPERTY CXX_STANDARD 14)

# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
target_include_directories(sudoku PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

# If we have compiler requirements for this library, list them
# here
target_compile_features(sudoku
    PUBLIC cxx_auto_type
    PRIVATE cxx_variadic_templates)

# This makes the project importable from the build directory
export(TARGETS sudoku FILE LibSudokuConfig.cmake)

###############################################################################

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})
include_directories(src)
        
# Every library has unit tests, of course
add_executable(testlibsudoku
    test/puzzletest.cpp
    test/main.cpp)

target_link_libraries(testlibsudoku
    ${GTEST_LIBRARIES}
    ${GTEST_MAIN_LIBRARIES}
    gmock
    gmock_main
    pthread
    sudoku)

add_test(testlibsudoku testlibsudoku)

SETUP_TARGET_FOR_COVERAGE(
    lcovlibsudoku   # target name
    testlibsudoku   # test program
    coverage        # where to put the results
)