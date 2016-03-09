/*
 * rowiterator.cpp
 *
 * Class implementation for the Sudoku RowIterator class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include "rowiterator.h"

#include "solver/ipuzzlesolver.h"
#include "solver/solverelem.h"

/* ************************************************************************* */

using Sudoku::RowIterator;

/* ************************************************************************* */
/* ************************************************************************* */

RowIterator::RowIterator(int rowIndex) :
    _rowIndex(rowIndex)
{
}

/* ************************************************************************* */

Sudoku::SolverElem &RowIterator::GetCell(IPuzzleSolver &solver, 
                                         int index) const
{
    return solver.Cell(index, _rowIndex);
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */