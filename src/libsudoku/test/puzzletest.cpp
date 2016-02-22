/*
 * puzzletest.cpp
 *
 * Tests for the Sudoku::Puzzle class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include <sstream>

#include <gtest/gtest.h>

#include "sudoku/puzzle.h"

/* ************************************************************************* */

using Sudoku::Puzzle;
using Sudoku::PuzzleDigit;

class PuzzleTest : public ::testing::Test
{
public:

protected:

private:
};

/* ************************************************************************* */
/* ************************************************************************* */

TEST_F(PuzzleTest, BasicAccess)
{
    Puzzle puzzle;
    
    puzzle.Cell(0, 0) = 1;
    puzzle.Cell(0, 5) = 3;
    
    ASSERT_EQ(1, puzzle.Cell(0, 0));
    ASSERT_EQ(3, puzzle.Cell(0, 5));
}

/* ************************************************************************* */

TEST_F(PuzzleTest, XIndexOutOfRange)
{
    Puzzle puzzle;
    
    ASSERT_THROW(puzzle.Cell(9, 0) = 0, Puzzle::IndexOutOfRange);
    ASSERT_THROW(PuzzleDigit digit = puzzle.Cell(9, 0), Puzzle::IndexOutOfRange);
}

/* ************************************************************************* */

TEST_F(PuzzleTest, YIndexOutOfRange)
{
    Puzzle puzzle;
    
    ASSERT_THROW(puzzle.Cell(1, 9) = 0, Puzzle::IndexOutOfRange);
    ASSERT_THROW(PuzzleDigit digit = puzzle.Cell(3, 19), Puzzle::IndexOutOfRange);
}

/* ************************************************************************* */

TEST_F(PuzzleTest, BlankGridIsZeroed)
{
    Puzzle puzzle;

    for (auto y = 0; y < Sudoku::PuzzleHeight; y++)
    {
        for (auto x = 0; x < Sudoku::PuzzleWidth; x++)
        {
            ASSERT_EQ(0, puzzle.Cell(x, y)) << "(" << x << ", " << y << ")";
        }
    }    
}

/* ************************************************************************* */

TEST_F(PuzzleTest, IndexOutOfRange__what)
{
    Puzzle::IndexOutOfRange exception;
    
    ASSERT_STREQ("Sudoku::TwoDArray IndexOutOfRange", exception.what());
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
