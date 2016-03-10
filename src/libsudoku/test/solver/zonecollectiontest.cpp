/*
 * zonecollectiontest.cpp
 *
 * Tests for the Sudoku::ZoneCollection class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include <gtest/gtest.h>

#include "solver/zonecollection.h"

#include "iterator/zoneiterator.h"
#include "solver/solverelem.h"
#include "zone/column.h"
#include "zone/row.h"
#include "zone/subgrid.h"

#include "iterator/mockpuzzlesolver.h"

/* ************************************************************************* */

using Sudoku::ZoneCollection;

using ::testing::ReturnRef;

class ZoneCollectionTest : public ::testing::Test
{
public:

protected:

private:
};

/* ************************************************************************* */
/* ************************************************************************* */

TEST_F(ZoneCollectionTest, DefaultConstructor)
{
    ZoneCollection collection;
    
    ASSERT_EQ(0, collection.size());
}

/* ************************************************************************* */

TEST_F(ZoneCollectionTest, IterateZones)
{
    Sudoku::MockPuzzleSolver solver;
    Sudoku::SolverElem elem;
    
    auto colNum = 0;
    auto rowNum = 0;
    auto subgridNum = 0;

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

        EXPECT_CALL(solver, Cell(0,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(1,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(2,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(3,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(4,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(5,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(6,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(7,rowNum)).WillOnce(ReturnRef(elem));
        EXPECT_CALL(solver, Cell(8,rowNum)).WillOnce(ReturnRef(elem));

        int expected_left[] = { 0, 3, 6, 0, 3, 6, 0, 3, 6 };
        int expected_top[] = { 0, 0, 0, 3, 3, 3, 6, 6, 6 };
        
        int left = expected_left[subgridNum];
        int top = expected_top[subgridNum];
        
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

    ZoneCollection collection;

    collection.push_back(std::make_unique<Sudoku::Column>(solver, colNum));    
    collection.push_back(std::make_unique<Sudoku::Row>(solver, rowNum));    
    collection.push_back(std::make_unique<Sudoku::SubGrid>(solver, subgridNum));    

    for (auto &zone : collection)
    {
        for (auto &e : *zone)
        {
            // do nothing
        }
    }    
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
