/*
 * sudoku.h
 *
 * This file contains the library header for the sudoku solver
 *
 * (c) 2016 Richard Oak
 */
 
#pragma once

/* ************************************************************************* */

#include "puzzle.h"

namespace Sudoku
{

/* ************************************************************************* */

/// <summary>
/// Solve the puzzle
/// </summary>
/// <param name="puzzle">The puzzle to solve</param>
/// <returns>The solved puzzle</returns>
Puzzle Solve(const Puzzle &puzzle);

/* ************************************************************************* */

}
