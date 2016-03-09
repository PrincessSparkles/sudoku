/*
 * column.cpp
 *
 * Class implementation for the Sudoku Column class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include <memory>   // std::make_shared

#include "column.h"
#include "iterator/columniterator.h"

#include "sudoku/puzzle.h"  // Sudoku::PuzzleHeight
#include "solver/ipuzzlesolver.h"

/* ************************************************************************* */

using Sudoku::Column;

/* ************************************************************************* */
/* ************************************************************************* */

Column::Column(IPuzzleSolver &solver, int columnIndex) :
    _solver(solver),
    _columnIndex(columnIndex)
{
}

/* ************************************************************************* */

Sudoku::ZoneIterator Column::begin()
{
    ZoneIterator it(_solver, 
        0, 
        std::make_shared<ColumnIterator>(_columnIndex));
    
    return it;
}

/* ************************************************************************* */

Sudoku::ZoneIterator Column::end()
{
    ZoneIterator it(_solver, 
        PuzzleHeight, 
        std::make_shared<ColumnIterator>(_columnIndex));
    
    return it;
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */