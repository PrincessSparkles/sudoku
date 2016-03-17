/*
 * zonesolvertest.cpp
 *
 * Tests for the Sudoku::ZoneSolver class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include <gtest/gtest.h>

#include "solver/zonesolver.h"
#include "solver/puzzlesolver.h"
#include "solver/solverelem.h"

/* ************************************************************************* */

using Sudoku::ZoneSolver;

class ZoneSolverTest : public ::testing::Test
{
public:

    virtual void SetUp()
    {
        _solver.Cell(7, 0).Solve(Sudoku::PuzzleDigit(4));
        _solver.Cell(0, 1).Solve(Sudoku::PuzzleDigit(9));
        _solver.Cell(1, 1).Solve(Sudoku::PuzzleDigit(4));
        _solver.Cell(1, 2).Solve(Sudoku::PuzzleDigit(3));
        _solver.Cell(2, 2).Solve(Sudoku::PuzzleDigit(2));
        _solver.Cell(3, 2).Solve(Sudoku::PuzzleDigit(5));
        _solver.Cell(4, 2).Solve(Sudoku::PuzzleDigit(8));
        _solver.Cell(6, 2).Solve(Sudoku::PuzzleDigit(7));
        _solver.Cell(3, 3).Solve(Sudoku::PuzzleDigit(7));
        _solver.Cell(5, 3).Solve(Sudoku::PuzzleDigit(8));
        _solver.Cell(7, 3).Solve(Sudoku::PuzzleDigit(6));
        _solver.Cell(8, 3).Solve(Sudoku::PuzzleDigit(4));
        _solver.Cell(0, 4).Solve(Sudoku::PuzzleDigit(5));
        _solver.Cell(1, 4).Solve(Sudoku::PuzzleDigit(2));
        _solver.Cell(5, 4).Solve(Sudoku::PuzzleDigit(1));
        _solver.Cell(3, 5).Solve(Sudoku::PuzzleDigit(9));
        _solver.Cell(5, 5).Solve(Sudoku::PuzzleDigit(3));
        _solver.Cell(7, 5).Solve(Sudoku::PuzzleDigit(2));
        _solver.Cell(8, 5).Solve(Sudoku::PuzzleDigit(7));
        _solver.Cell(1, 6).Solve(Sudoku::PuzzleDigit(7));
        _solver.Cell(2, 6).Solve(Sudoku::PuzzleDigit(4));
        _solver.Cell(3, 6).Solve(Sudoku::PuzzleDigit(2));
        _solver.Cell(4, 6).Solve(Sudoku::PuzzleDigit(9));
        _solver.Cell(6, 6).Solve(Sudoku::PuzzleDigit(8));
        _solver.Cell(0, 7).Solve(Sudoku::PuzzleDigit(8));
        _solver.Cell(1, 7).Solve(Sudoku::PuzzleDigit(9));
        _solver.Cell(7, 8).Solve(Sudoku::PuzzleDigit(5));
    }

protected:

    Sudoku::PuzzleSolver _solver;

private:

};

/* ************************************************************************* */
/* ************************************************************************* */

TEST_F(ZoneSolverTest, Solve)
{
    ZoneSolver solver;
    
    EXPECT_EQ(7, solver.GetSolution(_solver.Cell(2, 4)));  // subgrid
    EXPECT_EQ(7, solver.GetSolution(_solver.Cell(0, 0)));  // column
}

/* ************************************************************************* */

TEST_F(ZoneSolverTest, NoSolve)
{
    ZoneSolver solver;
    
    EXPECT_EQ(0, solver.GetSolution(_solver.Cell(1, 7)));
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
