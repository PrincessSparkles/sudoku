/*
 * cellsolver.h
 *
 * Class definition for the Sudoku CellSolver class
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
/// The CellSolver attempts to solve a cell by finding if all but one option
/// has been eliminated. If there is only one option for the cell, that is
/// returned as the solution
/// </summary>
class CellSolver : public ISolver
{
public:

    CellSolver() = default;
    ~CellSolver() = default;

#pragma region ISolver

    PuzzleDigit GetSolution(const SolverElem &cell) override;

#pragma endregion

protected:

private:
};

/* ************************************************************************* */

}