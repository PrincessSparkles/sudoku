/*
 * cellsolvertest.cpp
 *
 * Tests for the Sudoku::CellSolver class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include <gtest/gtest.h>

#include "solver/cellsolver.h"
#include "solver/solverelem.h"

/* ************************************************************************* */

using Sudoku::CellSolver;

class CellSolverTest : public ::testing::TestWithParam<int>
{
public:

protected:

private:
};

/* ************************************************************************* */

INSTANTIATE_TEST_CASE_P(CellSolver,
                        CellSolverTest,
                        ::testing::Range(1, 10));

/* ************************************************************************* */
/* ************************************************************************* */

// not part of the class - so it's only called once
TEST(CellSolverTest, CellSolver)
{
    Sudoku::SolverElem elem;
    
    CellSolver solver;
    
    ASSERT_EQ(0, solver.GetSolution(elem).get());    
}

/* ************************************************************************* */

TEST_P(CellSolverTest, Solve)
{
    // setup an element with only one possible solution
    Sudoku::SolverElem elem;
    
    for (auto i = 1; i <= Sudoku::MaxDigit; i++)
    {
        elem.IsPossible(i) = false;
    }
    
    int solution = GetParam();
    elem.IsPossible(solution) = true;
    
    CellSolver solver;
    ASSERT_EQ(solution, solver.GetSolution(elem).get());
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
