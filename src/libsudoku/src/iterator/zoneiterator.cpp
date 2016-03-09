/*
 * zoneiterator.cpp
 *
 * Class implementation for the Sudoku ZoneIterator class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include "zoneiterator.h"

#include "solver/ipuzzlesolver.h"
#include "solver/solverelem.h"

/* ************************************************************************* */

using Sudoku::ZoneIterator;

/* ************************************************************************* */
/* ************************************************************************* */

ZoneIterator::ZoneIterator(Sudoku::IPuzzleSolver &solver, int index, std::shared_ptr<IStrategy> strategy) :
    _solver(solver),
    _index(index),
    _strategy(strategy)
{
}

/* ************************************************************************* */

ZoneIterator &ZoneIterator::operator ++()
{
    _index++;
    return *this;
}

/* ************************************************************************* */

ZoneIterator ZoneIterator::operator ++(int)
{
    ZoneIterator tmp(*this);
    operator++();
    return tmp;
}

/* ************************************************************************* */

bool ZoneIterator::operator ==(const ZoneIterator &other)
{
    return _index == other._index;
}

/* ************************************************************************* */

bool ZoneIterator::operator !=(const ZoneIterator &other)
{
    return _index != other._index;
}

/* ************************************************************************* */

Sudoku::SolverElem &ZoneIterator::operator *()
{
    return _strategy->GetCell(_solver, _index);
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
