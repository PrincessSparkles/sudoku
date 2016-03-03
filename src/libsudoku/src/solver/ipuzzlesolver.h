/*
 * ipuzzlesolver.h
 *
 * Interface definition for the Sudoku IPuzzleSolver interface
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#pragma once

namespace Sudoku
{

/* ************************************************************************* */

// forward declares
class SolverElem;

/* ************************************************************************* */

/// <summary>
/// Interface for the puzzle solver
/// </summary>
class IPuzzleSolver
{
public:

    /// <summary>
    /// virtual destructor
    /// </summary>
    virtual ~IPuzzleSolver() = default;
    
    /// <summary>
    /// Get the cell with the specified coordinate
    /// </summary>
    /// <param name="x">The x-coord of the cell</param>
    /// <param name="y">The y-coord of the cell</param>
    /// <returns>The desired cell</returns>
    virtual SolverElem &Cell(int x, int y) = 0;
    
    /// <summary>
    /// Get the cell with the specified coordinate
    /// </summary>
    /// <param name="x">The x-coord of the cell</param>
    /// <param name="y">The y-coord of the cell</param>
    /// <returns>The desired cell</returns>
    virtual const SolverElem &Cell(int x, int y) const = 0;

protected:

private:
};

/* ************************************************************************* */

}
