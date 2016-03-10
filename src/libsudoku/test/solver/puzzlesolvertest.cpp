/*
 * puzzlesolvertest.cpp
 *
 * Tests for the Sudoku::PuzzleSolver class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include <gtest/gtest.h>

#include "solver/puzzlesolver.h"

/* ************************************************************************* */

using Sudoku::PuzzleSolver;

class PuzzleSolverTest : public ::testing::Test
{
public:

protected:

private:
};

/* ************************************************************************* */
/* ************************************************************************* */

TEST_F(PuzzleSolverTest, Solve1)
{
    Sudoku::Puzzle puzzle;
    PuzzleSolver solver;
    
    Sudoku::Puzzle solution = solver.Solve(puzzle);
    
    // for now, just code coverage
}

/* ************************************************************************* */

TEST_F(PuzzleSolverTest, DefaultConstructor)
{
    PuzzleSolver solver;
    
    for (auto y = 0; y < Sudoku::PuzzleHeight; y++)
    {
        for (auto x = 0; x < Sudoku::PuzzleHeight; x++)
        {
            ASSERT_EQ(0, solver.Cell(x, y).Solution());
            
            for (auto i = 1; i <= Sudoku::MaxDigit; i++)
            {
                ASSERT_TRUE(solver.Cell(x, y).IsPossible(i));
            }
        }
    }
}

/* ************************************************************************* */

TEST_F(PuzzleSolverTest, const_DefaultConstructor)
{
    const PuzzleSolver solver;
    
    for (auto y = 0; y < Sudoku::PuzzleHeight; y++)
    {
        for (auto x = 0; x < Sudoku::PuzzleHeight; x++)
        {
            ASSERT_EQ(0, solver.Cell(x, y).Solution());
            
            for (auto i = 1; i <= Sudoku::MaxDigit; i++)
            {
                ASSERT_TRUE(solver.Cell(x, y).IsPossible(i));
            }
        }
    }
}

/* ************************************************************************* */
/* ************************************************************************* */

TEST_F(PuzzleSolverTest, XIndexOutOfRange)
{
    PuzzleSolver solver;

    // typedef, because we cannot put the templated type arguments in the 
    // ASSERT_ macro. The commas in the argument list are interpreted as 
    // arguments to the macro    
    typedef Sudoku::TwoDArray<Sudoku::SolverElem, Sudoku::PuzzleWidth, Sudoku::PuzzleHeight> SolverGrid;
    
    ASSERT_THROW(solver.Cell(9, 0).Solution() = 0, SolverGrid::IndexOutOfRange);
    ASSERT_THROW(auto &elem = solver.Cell(9, 0), SolverGrid::IndexOutOfRange);
}

/* ************************************************************************* */

TEST_F(PuzzleSolverTest, YIndexOutOfRange)
{
    PuzzleSolver solver;
    
    // typedef, because we cannot put the templated type arguments in the 
    // ASSERT_ macro. The commas in the argument list are interpreted as 
    // arguments to the macro    
    typedef Sudoku::TwoDArray<Sudoku::SolverElem, Sudoku::PuzzleWidth, Sudoku::PuzzleHeight> SolverGrid;
    
    ASSERT_THROW(solver.Cell(1, 9).Solution() = 0, SolverGrid::IndexOutOfRange);
    ASSERT_THROW(auto &elem = solver.Cell(3, 19), SolverGrid::IndexOutOfRange);
}

/* ************************************************************************* */
/* ************************************************************************* */

TEST_F(PuzzleSolverTest, IndexOutOfRange__what)
{
    typedef Sudoku::TwoDArray<Sudoku::SolverElem, Sudoku::PuzzleWidth, Sudoku::PuzzleHeight> SolverGrid;

    // typedef, because we cannot put the templated type arguments in the 
    // ASSERT_ macro. The commas in the argument list are interpreted as 
    // arguments to the macro    
    SolverGrid::IndexOutOfRange exception;
    
    ASSERT_STREQ("Sudoku::TwoDArray IndexOutOfRange", exception.what());
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
