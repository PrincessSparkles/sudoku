/*
 * possiblesolutiontest.cpp
 *
 * Tests for the Sudoku::PossibleSolution class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include <sstream>

#include <gtest/gtest.h>

#include "solver/possiblesolution.h"

/* ************************************************************************* */

using Sudoku::PossibleSolution;

class PossibleSolutionTest : public ::testing::Test
{
public:

protected:

private:
};

/* ************************************************************************* */
/* ************************************************************************* */

TEST_F(PossibleSolutionTest, DefaultConstructor)
{
    PossibleSolution possible;
    
    for (auto i = 1; i <= Sudoku::MaxDigit; i++)
    {
        ASSERT_TRUE(possible.IsPossible(i));
    }
}

/* ************************************************************************* */

TEST_F(PossibleSolutionTest, SetGet)
{
    PossibleSolution possible;
    
    for (auto i = 1; i <= Sudoku::MaxDigit; i++)
    {
        possible.IsPossible(i) = false;
        ASSERT_FALSE(possible.IsPossible(i));
    }
}

/* ************************************************************************* */

TEST_F(PossibleSolutionTest, IsPossible_0_throws)
{
    PossibleSolution possible;
    
    ASSERT_THROW(possible.IsPossible(0) = false, PossibleSolution::IsPossibleOutOfRange);
}

/* ************************************************************************* */

TEST_F(PossibleSolutionTest, IsPossible_MaxDigit_plus_one_throws)
{
    PossibleSolution possible;
    
    ASSERT_THROW(possible.IsPossible(Sudoku::MaxDigit + 1) = false, PossibleSolution::IsPossibleOutOfRange);
}

/* ************************************************************************* */
/* ************************************************************************* */

TEST_F(PossibleSolutionTest, const_DefaultConstructor)
{
    const PossibleSolution possible;
    
    for (auto i = 1; i <= Sudoku::MaxDigit; i++)
    {
        ASSERT_TRUE(possible.IsPossible(i));
    }
}

/* ************************************************************************* */

TEST_F(PossibleSolutionTest, const_IsPossible_0_throws)
{
    const PossibleSolution possible;
    
    ASSERT_THROW(bool pos = possible.IsPossible(0), PossibleSolution::IsPossibleOutOfRange);
}

/* ************************************************************************* */

TEST_F(PossibleSolutionTest, const_IsPossible_MaxDigit_plus_one_throws)
{
    const PossibleSolution possible;
    
    ASSERT_THROW(bool pos = possible.IsPossible(Sudoku::MaxDigit + 1), PossibleSolution::IsPossibleOutOfRange);
}

/* ************************************************************************* */
/* ************************************************************************* */

TEST_F(PossibleSolutionTest, IsPossibleOutOfRange__what)
{
    PossibleSolution::IsPossibleOutOfRange exception;
    
    ASSERT_STREQ("Sudoku::PossibleSolution IsPossibleOutOfRange", exception.what());
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
