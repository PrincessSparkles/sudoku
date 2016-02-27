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

TEST_F(PuzzleTest, OutStreamOperatorBlank)
{
    std::string expected{
        ".........\n"
        ".........\n"
        ".........\n"
        ".........\n"
        ".........\n"
        ".........\n"
        ".........\n"
        ".........\n"
        ".........\n"
    };
    Puzzle puzzle;

    std::stringstream stream;

    stream << puzzle;

    ASSERT_EQ(expected, stream.str());
}

/* ************************************************************************* */

TEST_F(PuzzleTest, OutStreamOperator)
{
    std::string expected{
        ".......4.\n"
        "94.......\n"
        ".3258.7..\n"
        "...7.8.64\n"
        "52...1...\n"
        "...9.3.27\n"
        ".7429.8..\n"
        "89.......\n"
        ".......5.\n"
    };
    Puzzle puzzle;

    puzzle.Cell(7, 0) = 4;
    puzzle.Cell(0, 1) = 9;
    puzzle.Cell(1, 1) = 4;
    puzzle.Cell(1, 2) = 3;
    puzzle.Cell(2, 2) = 2;
    puzzle.Cell(3, 2) = 5;
    puzzle.Cell(4, 2) = 8;
    puzzle.Cell(6, 2) = 7;
    puzzle.Cell(3, 3) = 7;
    puzzle.Cell(5, 3) = 8;
    puzzle.Cell(7, 3) = 6;
    puzzle.Cell(8, 3) = 4;
    puzzle.Cell(0, 4) = 5;
    puzzle.Cell(1, 4) = 2;
    puzzle.Cell(5, 4) = 1;
    puzzle.Cell(3, 5) = 9;
    puzzle.Cell(5, 5) = 3;
    puzzle.Cell(7, 5) = 2;
    puzzle.Cell(8, 5) = 7;
    puzzle.Cell(1, 6) = 7;
    puzzle.Cell(2, 6) = 4;
    puzzle.Cell(3, 6) = 2;
    puzzle.Cell(4, 6) = 9;
    puzzle.Cell(6, 6) = 8;
    puzzle.Cell(0, 7) = 8;
    puzzle.Cell(1, 7) = 9;
    puzzle.Cell(7, 8) = 5;

    std::stringstream stream;

    stream << puzzle;

    ASSERT_EQ(expected, stream.str());
}
       
/* ************************************************************************* */

TEST_F(PuzzleTest, getHTML)
{
    Puzzle puzzle;

    puzzle.Cell(7, 0) = 4;
    puzzle.Cell(0, 1) = 9;
    puzzle.Cell(1, 1) = 4;
    puzzle.Cell(1, 2) = 3;
    puzzle.Cell(2, 2) = 2;
    puzzle.Cell(3, 2) = 5;
    puzzle.Cell(4, 2) = 8;
    puzzle.Cell(6, 2) = 7;
    puzzle.Cell(3, 3) = 7;
    puzzle.Cell(5, 3) = 8;
    puzzle.Cell(7, 3) = 6;
    puzzle.Cell(8, 3) = 4;
    puzzle.Cell(0, 4) = 5;
    puzzle.Cell(1, 4) = 2;
    puzzle.Cell(5, 4) = 1;
    puzzle.Cell(3, 5) = 9;
    puzzle.Cell(5, 5) = 3;
    puzzle.Cell(7, 5) = 2;
    puzzle.Cell(8, 5) = 7;
    puzzle.Cell(1, 6) = 7;
    puzzle.Cell(2, 6) = 4;
    puzzle.Cell(3, 6) = 2;
    puzzle.Cell(4, 6) = 9;
    puzzle.Cell(6, 6) = 8;
    puzzle.Cell(0, 7) = 8;
    puzzle.Cell(1, 7) = 9;
    puzzle.Cell(7, 8) = 5;

    std::stringstream stream;

    stream << puzzle.getHTML();

    // no real idea how to test this...
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
