/*
 * puzzlesolver.cpp
 *
 * Class implementation for the Sudoku PuzzleSolver class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include <vector>
#include <memory>

#include "puzzlesolver.h"

#include "sudoku/puzzle.h"

#include "zone/column.h"
#include "zone/row.h"
#include "zone/subgrid.h"

#include "solver/cellsolver.h"
#include "solver/zonesolver.h"

/* ************************************************************************* */

using Sudoku::PuzzleSolver;

/* ************************************************************************* */
/* ************************************************************************* */

namespace
{
    
/* ************************************************************************* */

/// <summary>
/// Copy all of the cells from the puzzle into the solver 
/// </summary>
/// <param name="solver">[out] The puzzle solver being setup</param>
/// <param name="puzzle">The puzzle that is being solved</param>
void SetupBoard(PuzzleSolver &solver, const Sudoku::Puzzle &puzzle)
{
    for (auto y = 0; y < Sudoku::PuzzleHeight; y++)
    {
        for (auto x = 0; x < Sudoku::PuzzleWidth; x++)
        {
            Sudoku::PuzzleDigit digit = puzzle.Cell(x, y);
            
            if (digit.get() != 0)
            {
                solver.Cell(x, y).Solve(digit);
            }
        }
    }    
}

/* ************************************************************************* */

/// <summary>
/// Try and solve each of the cells in the puzzle, using the supplied ISolver
/// </summary>
/// <param name="solver">The puzzle solver</param>
/// <param name="solvers">The methods for solving a cell</param>
/// <returns>
/// If a cell was solved, return true. Otherwise return false as there's no new
/// information and we'll not be able to make anymore headway in solving the puzzle
/// </returns>
bool SolveBoard(PuzzleSolver &solver, const std::vector<std::unique_ptr<Sudoku::ISolver>> &solvers)
{
    bool result = false;
    
    for (auto y = 0; y < Sudoku::PuzzleHeight; y++)
    {
        for (auto x = 0; x < Sudoku::PuzzleWidth; x++)
        {
            for (auto &solve : solvers)
            {
                Sudoku::PuzzleDigit digit = solve->GetSolution(solver.Cell(x, y));
                
                if (digit.get() != 0)
                {
                    solver.Cell(x, y).Solve(digit);
                    result = true;    
                }
            }
        }
    }
    
    return result;
}
    
/* ************************************************************************* */

/// <summary>
/// Copy all of the cells from the puzzle into the solver 
/// </summary>
/// <param name="solver">The puzzle solver containing the solution</param>
/// <param name="puzzle">[out] Where to put the solution</param>
void GetSolution(const PuzzleSolver &solver, Sudoku::Puzzle &puzzle)
{
    for (auto y = 0; y < Sudoku::PuzzleHeight; y++)
    {
        for (auto x = 0; x < Sudoku::PuzzleWidth; x++)
        {
            Sudoku::PuzzleDigit digit = solver.Cell(x, y).Solution();
            
            puzzle.Cell(x, y) = digit;
        }
    }    
}
    
/* ************************************************************************* */

} // anonymous namespace

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
    std::vector<std::unique_ptr<ISolver>> solvers;
    
    solvers.push_back(std::make_unique<CellSolver>());
    solvers.push_back(std::make_unique<ZoneSolver>());

    SetupBoard(*this, puzzle);

    while (SolveBoard(*this, solvers))
    {
        // loop around, until there's nothing more we can solve
        ;
    }
    
    Sudoku::Puzzle solution;
    GetSolution(*this, solution);
    
    return solution;
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
