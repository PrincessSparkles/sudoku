/*
 * subgriditerator.h
 *
 * Class definition for the Sudoku SubGridIterator class
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
/// Iterate over all of the cells in a SubGrid
/// </summary>
class SubGridIterator : public ZoneIterator::IStrategy
{
public:
    
    /// <summary>
    /// Construct subgrid rooted at (x,y)
    /// </summary>
    /// <param name="top">
    /// The y-coord of the top of the subgrid being iterated
    /// </param>
    /// <param name="left">
    /// The x-coord of the left of the subgrid being iterated
    /// </param>
    SubGridIterator(int top, int left);
    virtual ~SubGridIterator() = default;

protected:

#pragma region ZoneIterator::IStrategy

    virtual SolverElem &GetCell(IPuzzleSolver &solver, 
                                int index) const override;

#pragma endregion

private:

    /// <summary>
    /// The y-coord of the top of the subgrid being iterated
    /// </summary>
    int _top;
    /// <summary>
    /// The x-coord of the left of the subgrid being iterated
    /// </summary>
    int _left;
};

/* ************************************************************************* */

}
