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

// http://www.theguardian.com/lifeandstyle/2016/mar/14/sudoku-3382-easy
Sudoku::Puzzle Easy3382()
{
    Sudoku::Puzzle puzzle;
    
    puzzle.Cell(7,0) = 9;
    puzzle.Cell(8,0) = 7;
    puzzle.Cell(3,1) = 5;
    puzzle.Cell(4,1) = 7;
    puzzle.Cell(7,1) = 8;
    puzzle.Cell(3,2) = 4;
    puzzle.Cell(4,2) = 2;
    puzzle.Cell(5,2) = 6;
    
    puzzle.Cell(1,3) = 8;
    puzzle.Cell(2,3) = 1;   
    puzzle.Cell(7,3) = 4;
    puzzle.Cell(1,4) = 7;
    puzzle.Cell(2,4) = 6;
    puzzle.Cell(6,4) = 3;
    puzzle.Cell(8,4) = 2;
    puzzle.Cell(2,5) = 2;
    puzzle.Cell(5,5) = 5;
    puzzle.Cell(6,5) = 9;
    
    puzzle.Cell(4,6) = 5;
    puzzle.Cell(5,6) = 8;
    puzzle.Cell(8,6) = 1;
    puzzle.Cell(0,7) = 1;
    puzzle.Cell(1,7) = 3;
    puzzle.Cell(3,7) = 7;
    puzzle.Cell(0,8) = 7;
    puzzle.Cell(4,8) = 1;
    puzzle.Cell(6,8) = 5;
    
    return puzzle;
}

/* ************************************************************************* */
/* ************************************************************************* */

TEST_F(PuzzleSolverTest, Solve1)
{
    std::string expected{
        "654381297\n"
        "213579486\n"
        "897426153\n"
        "981237645\n"
        "576894312\n"
        "342165978\n"
        "429658731\n"
        "135742869\n"
        "768913524\n"
    };
    Sudoku::Puzzle puzzle = Easy3382();
    PuzzleSolver solver;
    
    Sudoku::Puzzle solution = solver.Solve(puzzle);

    std::stringstream stream;

    stream << solution;

    ASSERT_EQ(expected, stream.str());
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
            // each cell has 3 zones: column, row, subgrid
            ASSERT_EQ(3, solver.Cell(x, y).Zones().size()); 
            
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
