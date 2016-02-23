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

Puzzle Solve(const Puzzle &puzzle);

/* ************************************************************************* */

}
