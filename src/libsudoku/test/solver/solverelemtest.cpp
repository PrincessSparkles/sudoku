/*
 * solverelemtest.cpp
 *
 * Tests for the Sudoku::SolverElem class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include <gtest/gtest.h>

#include "solver/solverelem.h"

/* ************************************************************************* */

using Sudoku::SolverElem;

class SolverElemTest : public ::testing::Test
{
public:

protected:

private:
};

/* ************************************************************************* */
/* ************************************************************************* */

// We repeat a lot of the PossibleSolution tests as we're testing the API to
// SolverElem, and making sure that the member variable is 'wired-up' correctly

/* ************************************************************************* */
/* ************************************************************************* */

TEST_F(SolverElemTest, DefaultConstructor)
{
    SolverElem elem;
    
    for (auto i = 1; i <= Sudoku::MaxDigit; i++)
    {
        ASSERT_TRUE(elem.IsPossible(i));
    }
}

/* ************************************************************************* */

TEST_F(SolverElemTest, SetGet)
{
    SolverElem elem;
    
    for (auto i = 1; i <= Sudoku::MaxDigit; i++)
    {
        elem.IsPossible(i) = false;
        ASSERT_FALSE(elem.IsPossible(i));
    }
}

/* ************************************************************************* */

TEST_F(SolverElemTest, IsPossible_0_throws)
{
    SolverElem elem;
    
    ASSERT_THROW(elem.IsPossible(0) = false, Sudoku::PossibleSolution::IsPossibleOutOfRange);
}

/* ************************************************************************* */

TEST_F(SolverElemTest, IsPossible_MaxDigit_plus_one_throws)
{
    SolverElem elem;
    
    ASSERT_THROW(elem.IsPossible(Sudoku::MaxDigit + 1) = false, Sudoku::PossibleSolution::IsPossibleOutOfRange);
}

/* ************************************************************************* */
/* ************************************************************************* */

TEST_F(SolverElemTest, const_DefaultConstructor)
{
    const SolverElem elem;
    
    for (auto i = 1; i <= Sudoku::MaxDigit; i++)
    {
        ASSERT_TRUE(elem.IsPossible(i));
    }
}

/* ************************************************************************* */

TEST_F(SolverElemTest, const_IsPossible_0_throws)
{
    const SolverElem elem;
    
    ASSERT_THROW(bool pos = elem.IsPossible(0), Sudoku::PossibleSolution::IsPossibleOutOfRange);
}

/* ************************************************************************* */

TEST_F(SolverElemTest, const_IsPossible_MaxDigit_plus_one_throws)
{
    const SolverElem elem;
    
    ASSERT_THROW(bool pos = elem.IsPossible(Sudoku::MaxDigit + 1), Sudoku::PossibleSolution::IsPossibleOutOfRange);
}

/* ************************************************************************* */

TEST_F(SolverElemTest, DefaultSolutionIsZero)
{
    SolverElem elem;
    
    ASSERT_EQ(0, elem.Solution());
}

/* ************************************************************************* */

TEST_F(SolverElemTest, SetGetSolution)
{
    SolverElem elem;
    
    elem.Solution() = 2;
    
    ASSERT_EQ(2, elem.Solution());
}

/* ************************************************************************* */

TEST_F(SolverElemTest, const_DefaultSolutionIsZero)
{
    const SolverElem elem;
    
    ASSERT_EQ(0, elem.Solution());
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
