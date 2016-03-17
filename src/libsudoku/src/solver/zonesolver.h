/*
 * zonesolver.h
 *
 * Class definition for the Sudoku ZoneSolver class
 *
 * (c) Richard Oak 2016
 */

/* ************************************************************************* */

#pragma once

#include "isolver.h"

namespace Sudoku
{ 

/* ************************************************************************* */

/// <summary>
/// The ZoneSolver attempts to solve a cell by finding a digit that has not 
/// yet been discounted. It then looks at each zone the cell is part of to see
/// if the cell is the only choice in that zone for that digit. If so, that is
/// the solution that is returned. If no zone has only one choice for any digit
/// then zero is returned
/// </summary>
class ZoneSolver : public ISolver
{
public:

    ZoneSolver() = default;
    ~ZoneSolver() = default;

#pragma region ISolver

    PuzzleDigit GetSolution(const SolverElem &cell) override;

#pragma endregion

protected:

private:
};

/* ************************************************************************* */

}