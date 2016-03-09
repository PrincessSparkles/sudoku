/*
 * rowiterator.h
 *
 * Class definition for the Sudoku RowIterator class
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

/* ************************************************************************* */

/// <summary>
/// Iterate over all of the cells in a Row
/// </summary>
class RowIterator : public ZoneIterator::IStrategy
{
public:
    
    /// <summary>
    /// Construct nth row
    /// </summary>
    /// <param name="rowIndex">The index of the row being iterated</param>
    explicit RowIterator(int rowIndex);
    virtual ~RowIterator() = default;

protected:

#pragma region ZoneIterator::IStrategy

    virtual SolverElem &GetCell(IPuzzleSolver &solver, 
                                int index) const override;

#pragma endregion

private:

    /// <summary>
    /// The index of the row being iterated
    /// </summary>
    int _rowIndex;
};

/* ************************************************************************* */

}
