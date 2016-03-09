/*
 * subgrid.cpp
 *
 * Class implementation for the Sudoku SubGrid class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include <memory>   // std::make_shared

#include "subgrid.h"
#include "iterator/subgriditerator.h"

#include "sudoku/puzzle.h"  // Sudoku::PuzzleHeight
#include "solver/ipuzzlesolver.h"

/* ************************************************************************* */

using Sudoku::SubGrid;

/* ************************************************************************* */
/* ************************************************************************* */

namespace
{

/// <summary>
/// How many subgrids across the grid
/// </summary>
static const int numSubGridAcross = Sudoku::PuzzleWidth / Sudoku::SubGridWidth;    
/// <summary>
/// How many subgrids down the grid
/// </summary>
static const int numSubGridDown = Sudoku::PuzzleHeight / Sudoku::SubGridHeight;    

}

/* ************************************************************************* */
/* ************************************************************************* */

SubGrid::SubGrid(IPuzzleSolver &solver, int subGridNum) :
    _solver(solver),
    _top((subGridNum / numSubGridDown) * SubGridHeight),
    _left((subGridNum % numSubGridAcross) * SubGridWidth)
{
}

/* ************************************************************************* */

SubGrid::SubGrid(IPuzzleSolver &solver, int x, int y) :
    _solver(solver),
    _top((y / numSubGridDown) * SubGridHeight),
    _left((x / numSubGridAcross) * SubGridWidth)
{
}

/* ************************************************************************* */

Sudoku::ZoneIterator SubGrid::begin()
{
    ZoneIterator it(_solver, 0, std::make_shared<SubGridIterator>(_top, _left));

    return it;
}

/* ************************************************************************* */

Sudoku::ZoneIterator SubGrid::end()
{
    ZoneIterator it(_solver, 
        SubGridWidth * SubGridHeight, 
        std::make_shared<SubGridIterator>(_top, _left));

    return it;
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */