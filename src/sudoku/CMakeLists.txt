#
# CMakeLists.txt
#
# cmake file for sudoku executable
# inspired by http://rix0r.nl/blog/2015/08/13/cmake-guide/
#
# (c) 2016 Richard Oak
#

# We want the executable to be called sudoku, and the library
# to be called libsudoku.a
# This means both projects should have the same name, which cmake
# doesn't like. So we call the executable sudoku_exe and set
# it's OUTPUT_NAME via a call to set_target_properties
# taken from http://rachid.koucha.free.fr/tech_corner/cmake_manual.html#Project_3:_Generation_of_an_executable

# Define an executable
add_executable(sudoku_exe
    src/main.cpp)

set_property(TARGET sudoku_exe PROPERTY CXX_STANDARD 14)

# Define the libraries this project depends upon
target_link_libraries(sudoku_exe
    sudoku)
    
set_target_properties(sudoku_exe 
                      PROPERTIES OUTPUT_NAME sudoku)