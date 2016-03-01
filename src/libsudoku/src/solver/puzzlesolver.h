/*
 * puzzlesolver.h
 *
 * Class definition for the Sudoku PuzzleSolver class
 *
 * (c) Richard Oak 2016
 */

/* ************************************************************************* */

#pragma once

#include "ipuzzlesolver.h"

namespace Sudoku
{ 

/* ************************************************************************* */

// forward declare
class Puzzle;

/* ************************************************************************* */

/// <summary>
/// class that actually solves the puzzle
/// </summary>
class PuzzleSolver : public IPuzzleSolver
{
public:
    
    PuzzleSolver() = default;
    ~PuzzleSolver() = default;
    
    /// <summary>
    /// Solve the puzzle
    /// </summary>
    /// <param name="puzzle">The puzzle to solve</param>
    /// <returns>The solved puzzle</returns>
    Puzzle Solve(const Puzzle &puzzle);

protected:

private:  
};

/* ************************************************************************* */

}
