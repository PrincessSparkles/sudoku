/*
 * columniterator.cpp
 *
 * Class implementation for the Sudoku ColumnIterator class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include "columniterator.h"

#include "solver/ipuzzlesolver.h"
#include "solver/solverelem.h"

/* ************************************************************************* */

using Sudoku::ColumnIterator;

/* ************************************************************************* */
/* ************************************************************************* */

ColumnIterator::ColumnIterator(int columnIndex) :
    _columnIndex(columnIndex)
{
}

/* ************************************************************************* */

Sudoku::SolverElem &ColumnIterator::GetCell(IPuzzleSolver &solver, 
                                            int index) const
{
    return solver.Cell(_columnIndex, index);
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */