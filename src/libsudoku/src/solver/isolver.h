/*
 * isolver.h
 *
 * Interface definition for the Sudoku ISolver interface
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#pragma once

#include "sudoku/puzzledigit.h"

namespace Sudoku
{

/* ************************************************************************* */

class SolverElem;

/* ************************************************************************* */

/// <summary>
/// Interface for the Solver
/// </summary>
/// <remarks>
/// A Solver is an algorithm for trying to solve a cell in the grid
/// </remarks>
class ISolver
{
public:

    /// <summary>
    /// virtual destructor
    /// </summary>
    virtual ~ISolver() = default;
    
    /// <summary>
    /// Find a solution for the cell
    /// </summary>
    /// <param name="cell">The cell to solve</param>
    /// <returns>The solution, or 0 if no clear solution can be found</returns>
    virtual PuzzleDigit GetSolution(const Sudoku::SolverElem &cell) = 0;

protected:

private:

};

/* ************************************************************************* */

}
