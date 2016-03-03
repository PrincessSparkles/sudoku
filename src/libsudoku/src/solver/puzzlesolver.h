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
#include "solverelem.h"

#include "sudoku/puzzle.h"
#include "sudoku/twodarray.h"

namespace Sudoku
{ 

/* ************************************************************************* */

// forward declares
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

    /// <summary>
    /// Get the cell with the specified coordinate
    /// </summary>
    /// <param name="x">The x-coord of the cell</param>
    /// <param name="y">The y-coord of the cell</param>
    /// <returns>The desired cell</returns>
    SolverElem &Cell(int x, int y) override;
    
    /// <summary>
    /// Get the cell with the specified coordinate
    /// </summary>
    /// <param name="x">The x-coord of the cell</param>
    /// <param name="y">The y-coord of the cell</param>
    /// <returns>The desired cell</returns>
    const SolverElem &Cell(int x, int y) const override;

protected:

private:  

    /// <summary>
    /// The grid holding the current known information about the puzzle
    /// </summary>
    TwoDArray<SolverElem, PuzzleWidth, PuzzleHeight> _grid;  
};

/* ************************************************************************* */

}
