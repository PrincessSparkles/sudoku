/*
 * rowiteratortest.cpp
 *
 * Tests for the Sudoku::RowIterator class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include <gtest/gtest.h>

#include "mockpuzzlesolver.h"
#include "solver/solverelem.h"
#include "zone/row.h"
#include "iterator/rowiterator.h"

/* ************************************************************************* */

using Sudoku::Row;

using ::testing::_;
using ::testing::ReturnRef;

/* ************************************************************************* */

class RowIteratorTest : public ::testing::TestWithParam<int>
{
public:

protected:

private:
};

/* ************************************************************************* */

INSTANTIATE_TEST_CASE_P(RowIterator,
                        RowIteratorTest,
                        ::testing::Range(0, 9));
						
/* ************************************************************************* */
/* ************************************************************************* */

TEST_P(RowIteratorTest, Iterator)
{
	int rowNum = GetParam();
	
	Sudoku::MockPuzzleSolver solver;
	Sudoku::SolverElem elem;
	
    {
        ::testing::InSequence callSequence;
        
        EXPECT_CALL(solver, Cell(0,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(1,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(2,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(3,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(4,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(5,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(6,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(7,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(8,rowNum)).WillOnce(ReturnRef(elem));
    }
    	
	Row row(solver, rowNum);
	
	for (auto e : row)
	{
		// do nothing
	} 
}

/* ************************************************************************* */

TEST_P(RowIteratorTest, PostfixIncrement)
{
	int rowNum = GetParam();
	
	Sudoku::MockPuzzleSolver solver;
	Sudoku::SolverElem elem;
	
    {
        ::testing::InSequence callSequence;
        
        EXPECT_CALL(solver, Cell(0,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(1,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(2,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(3,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(4,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(5,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(6,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(7,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(8,rowNum)).WillOnce(ReturnRef(elem));
    }
    	
	Row row(solver, rowNum);
	
    for (auto it = std::begin(row); it != std::end(row); it++)
    {
        // get the cell to trigger the EXPECT_CALLs
        ASSERT_TRUE((*it).IsPossible(1));
    }    
}

/* ************************************************************************* */

TEST_P(RowIteratorTest, EqualityOperator)
{
	int rowNum = GetParam();
	
	Sudoku::MockPuzzleSolver solver;
	Sudoku::SolverElem elem;
	
    {
        ::testing::InSequence callSequence;
        
        EXPECT_CALL(solver, Cell(0,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(1,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(2,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(3,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(4,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(5,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(6,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(7,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(8,rowNum)).WillOnce(ReturnRef(elem));
    }
    	
	Row row(solver, rowNum);
	
    auto it = std::begin(row);
    
    for (;;)
    {
        // contrived loop to make sure that operator == gets called
        if (it == std::end(row))
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
