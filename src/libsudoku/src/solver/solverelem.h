/*
 * solverelem.h
 *
 * Class definition for the Sudoku SolverElem class
 *
 * (c) Richard Oak 2016
 */

/* ************************************************************************* */

#pragma once

#include "sudoku/puzzledigit.h" // PuzzleDigitType

#include "solver/possiblesolution.h"
#include "solver/zonecollection.h"

namespace Sudoku
{ 

/* ************************************************************************* */

/// <summary>
/// Class representing the information the PuzzleSolver has about this cell
/// </summary>
class SolverElem
{
public:

    SolverElem() = default;
    ~SolverElem() = default;
    
    /// <summary>
    /// force the class to be non-copy constructable
    /// </summary>
    SolverElem(const SolverElem &) = delete;
    
    /// <summary>
    /// Force the class to be non-copy assignable
    /// </summary>
    /// <returns>Nothing - this method is deleted</returns>
    SolverElem &operator =(const SolverElem &) = delete;
    
    /// <summary>
    /// Gets/Sets whether digit 'x' is a possibility for this cell
    /// </summary>
    /// <param name="digit">The digit that might be possible</param>
    /// <returns>the possibility</returns>
    bool &IsPossible(const PuzzleDigitType &digit)
    {
        return _possible.IsPossible(digit);
    }

    /// <summary>
    /// Gets whether digit 'x' is a possibility for this cell
    /// </summary>
    /// <param name="digit">The digit that might be possible</param>
    /// <returns>the possibility</returns>
    const bool &IsPossible(const PuzzleDigitType &digit) const
    {
        return _possible.IsPossible(digit);
    }
    
    /// <summary>
    /// Set the solution for this cell
    /// </summary>
    /// <remarks>
    /// This method also sets IsPossible equal to false for all entries
    /// for this cell.
    /// It also sets the IsPossible(solution) to false for each entry 
    /// in each zone that this cell is part of 
    /// </remarks>
    /// <param name="solution">The solution to this cell</param>
    void Solve(const PuzzleDigit &solution);
    
    /// <summary>
    /// Get the solution for this cell (zero if unsolved)
    /// </summary>
    /// <returns>The current solution</returns>
    const PuzzleDigit &Solution() const
    {
        return _solution;
    }
    
    /// <summary>
    /// Get the ZoneCollection
    /// </summary>
    /// <returns>The ZoneCollection</returns>
    ZoneCollection &Zones()
    {
        return _zones;
    }

    /// <summary>
    /// Get the ZoneCollection
    /// </summary>
    /// <returns>The ZoneCollection</returns>
    const ZoneCollection &Zones() const
    {
        return _zones;
    }

protected:

private:

    /// <summary>
    /// Possible solutions for this cell
    /// </summary>
    PossibleSolution _possible;

    /// <summary>
    /// If non-zero, the value that has been determined for this element
    /// Otherwise, this cell is as yet unsolved
    /// </summary>
    PuzzleDigit _solution;
    
    /// <summary>
    /// The zones that this cell is part of
    /// </summary>
    ZoneCollection  _zones;
};

/* ************************************************************************* */

}
