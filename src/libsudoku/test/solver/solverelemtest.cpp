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
#include "solver/puzzlesolver.h"

#include "iterator/zoneiterator.h"

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
/* ************************************************************************* */

class SolverElemSolveTest : public ::testing::TestWithParam<::testing::tuple<int, int, int>>
{
public:

protected:

private:
};

using ::testing::Combine;
using ::testing::Range;

/* ************************************************************************* */

INSTANTIATE_TEST_CASE_P(SolverElemTest,
                        SolverElemSolveTest,
                        Combine(Range(0, 9), Range(0, 9), Range(1,10)));
                        
/* ************************************************************************* */
/* ************************************************************************* */

TEST_P(SolverElemSolveTest, Solve)
{
    int x = ::testing::get<0>(GetParam());
    int y = ::testing::get<1>(GetParam());
    int solution = ::testing::get<2>(GetParam());
    
    int top = (y / 3) * 3;
    int left = (x / 3) * 3;
    
    Sudoku::PuzzleSolver solver;
    
    // solution is initially blank
    ASSERT_EQ(0, solver.Cell(x, y).Solution());
    
    // IsPossible is true for all possible digits
    for (auto i = 1; i <= Sudoku::MaxDigit; i++)
    {
        ASSERT_TRUE(solver.Cell(x, y).IsPossible(i));   
    }
    
    // check the zones, to make sure that the solution could be put anywhere
    for (auto &zone : solver.Cell(x, y).Zones())
    {
        for (auto &elem : *zone)
        {
            ASSERT_TRUE(elem.IsPossible(solution));
        }
    }
        
    // ** SOLVE THE CELL **
    solver.Cell(x, y).Solve(solution);       

    // the solution has been set
    ASSERT_EQ(solution, solver.Cell(x, y).Solution());

    // No digit is possible in the cell
    for (auto i = 1; i <= Sudoku::MaxDigit; i++)
    {
        ASSERT_FALSE(solver.Cell(x, y).IsPossible(i));   
    }    

    // check the zones, to make sure that the solution can't be put anywhere
    for (auto &zone : solver.Cell(x, y).Zones())
    {
        for (auto &elem : *zone)
        {
            ASSERT_FALSE(elem.IsPossible(solution));
        }
    }
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
