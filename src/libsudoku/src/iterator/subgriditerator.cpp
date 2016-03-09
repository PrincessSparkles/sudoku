/*
 * subgriditerator.cpp
 *
 * Class implementation for the Sudoku SubGridIterator class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include "subgriditerator.h"

#include "solver/ipuzzlesolver.h"
#include "sudoku/puzzle.h"  // SubGridWidth, SubGridHeight

/* ************************************************************************* */

using Sudoku::SubGridIterator;

/* ************************************************************************* */
/* ************************************************************************* */

SubGridIterator::SubGridIterator(int top, int left) :
    _top(top),
    _left(left)
{
}

/* ************************************************************************* */

Sudoku::SolverElem &SubGridIterator::GetCell(IPuzzleSolver &solver, int index) const
{
    int x = _left + index % SubGridWidth;
    int y = _top + index / SubGridHeight;
    
    return solver.Cell(x, y);
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */