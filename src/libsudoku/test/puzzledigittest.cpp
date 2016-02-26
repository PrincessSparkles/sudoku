/*
 * puzzledigittest.cpp
 *
 * Tests for the Sudoku::PuzzleDigit class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include <gtest/gtest.h>

#include "sudoku/puzzledigit.h"

/* ************************************************************************* */

using Sudoku::PuzzleDigit;

class PuzzleDigitTest : public ::testing::Test
{
public:

protected:

private:
};

/* ************************************************************************* */
/* ************************************************************************* */

TEST_F(PuzzleDigitTest, DefaultConstructor)
{
    PuzzleDigit digit;
    
    ASSERT_EQ(0, digit.get());
}

/* ************************************************************************* */

TEST_F(PuzzleDigitTest, ValueConstructor)
{
    PuzzleDigit digit(1);
    
    ASSERT_EQ(1, digit.get());
}

/* ************************************************************************* */

TEST_F(PuzzleDigitTest, ValueConstructorOutOfRange)
{
    ASSERT_THROW(PuzzleDigit digit(10), PuzzleDigit::DigitOutOfRange);
}

/* ************************************************************************* */

TEST_F(PuzzleDigitTest, EqualityOperator)
{
    PuzzleDigit digit(1);

    // make sure both variants of == work
    ASSERT_TRUE(digit == 1);    
    ASSERT_TRUE(1 == digit);    
}

/* ************************************************************************* */

TEST_F(PuzzleDigitTest, AssignmentOperator)
{
    PuzzleDigit digit(1);

    ASSERT_EQ(1, digit);
    
    digit = 5;    

    ASSERT_EQ(5, digit);
}

/* ************************************************************************* */

TEST_F(PuzzleDigitTest, AssignmentOperatorOutOfRange)
{
    PuzzleDigit digit(1);

    ASSERT_EQ(1, digit);
    
    ASSERT_THROW(digit = 100, PuzzleDigit::DigitOutOfRange);    
}

/* ************************************************************************* */

TEST_F(PuzzleDigitTest, DigitOutOfRange__what)
{
    PuzzleDigit::DigitOutOfRange exception;
    
    ASSERT_STREQ("Sudoku::PuzzleDigit DigitOutOfRange", exception.what());
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
