/*
 * puzzlesolver.cpp
 *
 * Class implementation for the Sudoku PuzzleSolver class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include "puzzlesolver.h"

#include "sudoku/puzzle.h"

#include "zone/column.h"
#include "zone/row.h"
#include "zone/subgrid.h"

/* ************************************************************************* */

using Sudoku::PuzzleSolver;

/* ************************************************************************* */
/* ************************************************************************* */

PuzzleSolver::PuzzleSolver()
{
    for (auto y = 0; y < PuzzleHeight; y++)
    {
        for (auto x = 0; x < PuzzleWidth; x++)
        {
            // construct the zones for this cell
            Cell(x, y).Zones().push_back(std::make_unique<Column>(*this, x));
            Cell(x, y).Zones().push_back(std::make_unique<Row>(*this, y));
            Cell(x, y).Zones().push_back(std::make_unique<SubGrid>(*this, x, y));
        }
    }
}

/* ************************************************************************* */

Sudoku::Puzzle PuzzleSolver::Solve(const Sudoku::Puzzle &puzzle)
{
    return puzzle;
}

/* ************************************************************************* */

Sudoku::SolverElem &PuzzleSolver::Cell(int x, int y)
{
    return _grid.Cell(x, y);
}

/* ************************************************************************* */

const Sudoku::SolverElem &PuzzleSolver::Cell(int x, int y) const
{
    return _grid.Cell(x, y);
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
