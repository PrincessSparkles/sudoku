/*
 * main.cpp
 *
 * This file contains the main for the Sudoku solver application
 *
 * (c) 2016 Richard Oak
 */
 
/* ************************************************************************* */

#include <iostream>

#include "sudoku/sudoku.h"

/* ************************************************************************* */

/* ************************************************************************* */
/* ************************************************************************* */

int main(int argc, char *argv[])
{
    Sudoku::Puzzle puzzle;
    
    puzzle.Cell(7, 0) = 4;
    puzzle.Cell(0, 1) = 9;
    puzzle.Cell(1, 1) = 4;
    puzzle.Cell(1, 2) = 3;
    puzzle.Cell(2, 2) = 2;
    puzzle.Cell(3, 2) = 5;
    puzzle.Cell(4, 2) = 8;
    puzzle.Cell(6, 2) = 7;
    puzzle.Cell(3, 3) = 7;
    puzzle.Cell(5, 3) = 8;
    puzzle.Cell(7, 3) = 6;
    puzzle.Cell(8, 3) = 4;
    puzzle.Cell(0, 4) = 5;
    puzzle.Cell(1, 4) = 2;
    puzzle.Cell(5, 4) = 1;
    puzzle.Cell(3, 5) = 9;
    puzzle.Cell(5, 5) = 3;
    puzzle.Cell(7, 5) = 2;
    puzzle.Cell(8, 5) = 7;
    puzzle.Cell(1, 6) = 7;
    puzzle.Cell(2, 6) = 4;
    puzzle.Cell(3, 6) = 2;
    puzzle.Cell(4, 6) = 9;
    puzzle.Cell(6, 6) = 8;
    puzzle.Cell(0, 7) = 8;
    puzzle.Cell(1, 7) = 9;
    puzzle.Cell(7, 8) = 5;

    Sudoku::Puzzle solution = Sudoku::Solve(puzzle);

    std::cout << solution.getHTML() << std::endl;

    return 0;
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
 