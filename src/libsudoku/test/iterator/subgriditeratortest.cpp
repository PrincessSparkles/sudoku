/*
 * subgriditeratortest.cpp
 *
 * Tests for the Sudoku::SubGridIterator class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include <gtest/gtest.h>

#include "mockpuzzlesolver.h"
#include "solver/solverelem.h"
#include "zone/subgrid.h"
#include "iterator/subgriditerator.h"

/* ************************************************************************* */

using Sudoku::SubGrid;

using ::testing::_;
using ::testing::ReturnRef;
using ::testing::Combine;

/* ************************************************************************* */

class SubGridIndexIteratorTest : public ::testing::TestWithParam<int>
{
public:

protected:

private:
};

/* ************************************************************************* */

INSTANTIATE_TEST_CASE_P(SubGridIterator,
                        SubGridIndexIteratorTest,
                        ::testing::Range(0, 9));
                        
/* ************************************************************************* */
/* ************************************************************************* */

TEST_P(SubGridIndexIteratorTest, Iterator)
{
    int subgridNum = GetParam();
    int expected_left[] = { 0, 3, 6, 0, 3, 6, 0, 3, 6 };
    int expected_top[] = { 0, 0, 0, 3, 3, 3, 6, 6, 6 };
    
    int left = expected_left[subgridNum];
    int top = expected_top[subgridNum];
    
    Sudoku::MockPuzzleSolver solver;
    Sudoku::SolverElem elem;
    
    {
        ::testing::InSequence callSequence;
        
        EXPECT_CALL(solver, Cell(left + 0, top + 0)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 1, top + 0)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 2, top + 0)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 0, top + 1)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 1, top + 1)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 2, top + 1)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 0, top + 2)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 1, top + 2)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 2, top + 2)).WillOnce(ReturnRef(elem));
    }
        
    SubGrid subgrid(solver, subgridNum);
    
    for (auto e : subgrid)
    {
        // do nothing
    } 
}

/* ************************************************************************* */

TEST_P(SubGridIndexIteratorTest, PostfixIncrement)
{
    int subgridNum = GetParam();
    int expected_left[] = { 0, 3, 6, 0, 3, 6, 0, 3, 6 };
    int expected_top[] = { 0, 0, 0, 3, 3, 3, 6, 6, 6 };
    
    int left = expected_left[subgridNum];
    int top = expected_top[subgridNum];
    
    Sudoku::MockPuzzleSolver solver;
    Sudoku::SolverElem elem;
    
    {
        ::testing::InSequence callSequence;
        
        EXPECT_CALL(solver, Cell(left + 0, top + 0)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 1, top + 0)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 2, top + 0)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 0, top + 1)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 1, top + 1)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 2, top + 1)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 0, top + 2)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 1, top + 2)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 2, top + 2)).WillOnce(ReturnRef(elem));
    }
        
    SubGrid subgrid(solver, subgridNum);
    
    for (auto it = std::begin(subgrid); it != std::end(subgrid); it++)
    {
        // get the cell to trigger the EXPECT_CALLs
        ASSERT_TRUE((*it).IsPossible(1));
    }    
}

/* ************************************************************************* */

TEST_P(SubGridIndexIteratorTest, EqualityOperator)
{
    int subgridNum = GetParam();
    int expected_left[] = { 0, 3, 6, 0, 3, 6, 0, 3, 6 };
    int expected_top[] = { 0, 0, 0, 3, 3, 3, 6, 6, 6 };
    
    int left = expected_left[subgridNum];
    int top = expected_top[subgridNum];
    
    Sudoku::MockPuzzleSolver solver;
    Sudoku::SolverElem elem;
    
    {
        ::testing::InSequence callSequence;
        
        EXPECT_CALL(solver, Cell(left + 0, top + 0)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 1, top + 0)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 2, top + 0)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 0, top + 1)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 1, top + 1)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 2, top + 1)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 0, top + 2)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 1, top + 2)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 2, top + 2)).WillOnce(ReturnRef(elem));
    }
        
    SubGrid subgrid(solver, subgridNum);
    
    auto it = std::begin(subgrid);
    
    for (;;)
    {
        // contrived loop to make sure that operator == gets called
        if (it == std::end(subgrid))
        {
            break;
        }
        
        // get the cell to trigger the EXPECT_CALLs
        ASSERT_TRUE((*it).IsPossible(1));
        
        // next cell
        it++;
    }    
}

/* ************************************************************************* */
/* ************************************************************************* */

class SubGridCoordIteratorTest : public ::testing::TestWithParam<::testing::tuple<int, int>>
{
public:

protected:

private:
};

/* ************************************************************************* */

INSTANTIATE_TEST_CASE_P(SubGridIterator,
                        SubGridCoordIteratorTest,
                        Combine(::testing::Range(0, 9), ::testing::Range(0, 9)));
                        
/* ************************************************************************* */
/* ************************************************************************* */

TEST_P(SubGridCoordIteratorTest, Iterator)
{
    int x = ::testing::get<0>(GetParam());
    int y = ::testing::get<1>(GetParam());
    
    int top = (y / 3) * 3;
    int left = (x / 3) * 3;
    
    Sudoku::MockPuzzleSolver solver;
    Sudoku::SolverElem elem;
    
    {
        ::testing::InSequence callSequence;
        
        EXPECT_CALL(solver, Cell(left + 0, top + 0)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 1, top + 0)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 2, top + 0)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 0, top + 1)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 1, top + 1)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 2, top + 1)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 0, top + 2)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 1, top + 2)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 2, top + 2)).WillOnce(ReturnRef(elem));
    }
        
    SubGrid subgrid(solver, x, y);
    
    for (auto e : subgrid)
    {
        // do nothing
    } 
}

/* ************************************************************************* */

TEST_P(SubGridCoordIteratorTest, PostfixIncrement)
{
    int x = ::testing::get<0>(GetParam());
    int y = ::testing::get<1>(GetParam());
    
    int top = (y / 3) * 3;
    int left = (x / 3) * 3;
    
    Sudoku::MockPuzzleSolver solver;
    Sudoku::SolverElem elem;
    
    {
        ::testing::InSequence callSequence;
        
        EXPECT_CALL(solver, Cell(left + 0, top + 0)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 1, top + 0)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 2, top + 0)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 0, top + 1)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 1, top + 1)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 2, top + 1)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 0, top + 2)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 1, top + 2)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 2, top + 2)).WillOnce(ReturnRef(elem));
    }
        
    SubGrid subgrid(solver, x, y);
    
    for (auto it = std::begin(subgrid); it != std::end(subgrid); it++)
    {
        // get the cell to trigger the EXPECT_CALLs
        ASSERT_TRUE((*it).IsPossible(1));
    }    
}

/* ************************************************************************* */

TEST_P(SubGridCoordIteratorTest, EqualityOperator)
{
    int x = ::testing::get<0>(GetParam());
    int y = ::testing::get<1>(GetParam());
    
    int top = (y / 3) * 3;
    int left = (x / 3) * 3;
    
    Sudoku::MockPuzzleSolver solver;
    Sudoku::SolverElem elem;
    
    {
        ::testing::InSequence callSequence;
        
        EXPECT_CALL(solver, Cell(left + 0, top + 0)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 1, top + 0)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 2, top + 0)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 0, top + 1)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 1, top + 1)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 2, top + 1)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 0, top + 2)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 1, top + 2)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(left + 2, top + 2)).WillOnce(ReturnRef(elem));
    }
        
    SubGrid subgrid(solver, x, y);
    
    auto it = std::begin(subgrid);
    
    for (;;)
    {
        // contrived loop to make sure that operator == gets called
        if (it == std::end(subgrid))
        {
            break;
        }
        
        // get the cell to trigger the EXPECT_CALLs
        ASSERT_TRUE((*it).IsPossible(1));
        
        // next cell
        it++;
    }    
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
