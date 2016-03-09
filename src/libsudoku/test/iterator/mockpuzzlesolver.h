/*
 * mockpuzzlesolver.h
 *
 * Class definition for the MockPuzzleSolver class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#pragma once

#include "gmock/gmock.h"

#include "solver/ipuzzlesolver.h"

namespace Sudoku
{

/* ************************************************************************* */

class MockPuzzleSolver : public IPuzzleSolver
{
public:
    MOCK_METHOD2(Cell, SolverElem &(int x, int y));
    MOCK_CONST_METHOD2(Cell, const SolverElem &(int x, int y));
};

/* ************************************************************************* */

}
