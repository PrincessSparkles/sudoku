/*
 * cellsolver.cpp
 *
 * Class implementation for the Sudoku CellSolver class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include "cellsolver.h"
#include "solver/solverelem.h"

/* ************************************************************************* */

using Sudoku::CellSolver;

/* ************************************************************************* */
/* ************************************************************************* */

Sudoku::PuzzleDigit CellSolver::GetSolution(const SolverElem &cell)
{
    PuzzleDigit solution;
    int count = 0;
    
    for (auto i = 1; i <= MaxDigit; i++)
    {
        if (cell.IsPossible(i))
        {
            solution = i;
            count++;
        }
    }
    
    if (count == 1)
    {
        return solution;
    }
    else
    {
        return PuzzleDigit(0);
    }
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
