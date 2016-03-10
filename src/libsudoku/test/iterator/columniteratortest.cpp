/*
 * columniteratortest.cpp
 *
 * Tests for the Sudoku::ColumnIterator class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include <gtest/gtest.h>

#include "mockpuzzlesolver.h"
#include "solver/solverelem.h"
#include "zone/column.h"
#include "iterator/columniterator.h"

/* ************************************************************************* */

using Sudoku::Column;

using ::testing::_;
using ::testing::ReturnRef;

/* ************************************************************************* */

class ColumnIteratorTest : public ::testing::TestWithParam<int>
{
public:

protected:

private:
};

/* ************************************************************************* */

INSTANTIATE_TEST_CASE_P(ColumnIterator,
                        ColumnIteratorTest,
                        ::testing::Range(0, 9));
                        
/* ************************************************************************* */
/* ************************************************************************* */

TEST_P(ColumnIteratorTest, Iterator)
{
    int colNum = GetParam();
    
    Sudoku::MockPuzzleSolver solver;
    Sudoku::SolverElem elem;
    
    {
        ::testing::InSequence callSequence;
        
        EXPECT_CALL(solver, Cell(colNum,0)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,1)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,2)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,3)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,4)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,5)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,6)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,7)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,8)).WillOnce(ReturnRef(elem));
    }
            
    Column column(solver, colNum);
    
    for (auto &e : column)
    {
        // do nothing
    } 
}

/* ************************************************************************* */

TEST_P(ColumnIteratorTest, PostfixIncrement)
{
    // more tests for coverage
    int colNum = GetParam();
    
    Sudoku::MockPuzzleSolver solver;
    Sudoku::SolverElem elem;
    
    {
        ::testing::InSequence callSequence;
        
        EXPECT_CALL(solver, Cell(colNum,0)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,1)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,2)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,3)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,4)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,5)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,6)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,7)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,8)).WillOnce(ReturnRef(elem));
    }
            
    Column column(solver, colNum);

    for (auto it = std::begin(column); it != std::end(column); it++)
    {
        // get the cell to trigger the EXPECT_CALLs
        ASSERT_TRUE((*it).IsPossible(1));
    }    
}

/* ************************************************************************* */

TEST_P(ColumnIteratorTest, EqualityOperator)
{
    // more tests for coverage
    int colNum = GetParam();
    
    Sudoku::MockPuzzleSolver solver;
    Sudoku::SolverElem elem;
    
    {
        ::testing::InSequence callSequence;
        
        EXPECT_CALL(solver, Cell(colNum,0)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,1)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,2)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,3)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,4)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,5)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,6)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,7)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(colNum,8)).WillOnce(ReturnRef(elem));
    }
            
    Column column(solver, colNum);

    auto it = std::begin(column);
    
    for (;;)
    {
        // contrived loop to make sure that operator == gets called
        if (it == std::end(column))
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
