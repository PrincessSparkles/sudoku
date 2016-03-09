/*
 * row.cpp
 *
 * Class implementation for the Sudoku Row class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include <memory>   // std::make_shared

#include "row.h"
#include "iterator/rowiterator.h"

#include "sudoku/puzzle.h"  // Sudoku::PuzzleHeight
#include "solver/ipuzzlesolver.h"

/* ************************************************************************* */

using Sudoku::Row;

/* ************************************************************************* */
/* ************************************************************************* */

Row::Row(IPuzzleSolver &solver, int rowIndex) :
    _solver(solver),
    _rowIndex(rowIndex)
{
}

/* ************************************************************************* */

Sudoku::ZoneIterator Row::begin()
{
    ZoneIterator it(_solver, 0, std::make_shared<RowIterator>(_rowIndex));

    return it;
}

/* ************************************************************************* */

Sudoku::ZoneIterator Row::end()
{
    ZoneIterator it(_solver, 
        PuzzleWidth, 
        std::make_shared<RowIterator>(_rowIndex));

    return it;
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
