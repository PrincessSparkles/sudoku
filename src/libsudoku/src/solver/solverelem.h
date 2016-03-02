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
    /// Gets/Sets whether digit 'x' is a possibility for this cell
    /// </summary>
    /// <param name="digit">The digit that might be possible</param>
    /// <returns>the possibility</returns>
    bool &IsPossible(const PuzzleDigitType &digit);

    /// <summary>
    /// Gets whether digit 'x' is a possibility for this cell
    /// </summary>
    /// <param name="digit">The digit that might be possible</param>
    /// <returns>the possibility</returns>
    const bool &IsPossible(const PuzzleDigitType &digit) const;

protected:

private:

    /// <summary>
    /// Possible solutions for this cell
    /// </summary>
    PossibleSolution _possible;

};

/* ************************************************************************* */

}
