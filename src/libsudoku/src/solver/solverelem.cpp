/*
 * solverelem.cpp
 *
 * This file contains the class implementation for the Sudoku::SolverElem class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include "solverelem.h"

#include "iterator/zoneiterator.h"
 
/* ************************************************************************* */

using Sudoku::SolverElem;

/* ************************************************************************* */
/* ************************************************************************* */

void SolverElem::Solve(const PuzzleDigit &solution)
{
    // first set the solution
    _solution = solution;
    
    // we cannot put any other digit here
    // we set IsPossible(solution) = false as well as it means we don't
    // have to check if this digit is solved separately
    for (auto i = 1; i <= MaxDigit; i++)
    {
        IsPossible(i) = false;
    }
    
    // we cannot put 'solution' in any other zone
    for (auto &zone : Zones())
    {
        for (auto &elem : *zone)
        {
            elem.IsPossible(solution.get()) = false;
        }
    }
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
 