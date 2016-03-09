/*
 * columniterator.h
 *
 * Class definition for the Sudoku ColumnIterator class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#pragma once

#include "zoneiterator.h"

namespace Sudoku
{

/* ************************************************************************* */

class IPuzzleSolver;
class SolverElem;

/* ************************************************************************* */

/// <summary>
/// Iterate over all of the cells in a Column
/// </summary>
class ColumnIterator : public ZoneIterator::IStrategy
{
public:
    
    /// <summary>
    /// Construct nth column
    /// </summary>
    /// <param name="columnIndex">The index of the column being iterated</param>
    explicit ColumnIterator(int columnIndex);
    virtual ~ColumnIterator() = default;

protected:

#pragma region ZoneIterator::IStrategy

    virtual SolverElem &GetCell(IPuzzleSolver &solver, 
                                int index) const override;

#pragma endregion

private:

    /// <summary>
    /// The index of the column being iterated
    /// </summary>
    int _columnIndex;
};

/* ************************************************************************* */

}
