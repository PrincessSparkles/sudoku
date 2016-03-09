/*
 * subgrid.h
 *
 * Class definition for the Sudoku SubGrid class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#pragma once

#include "izone.h"

namespace Sudoku
{

/* ************************************************************************* */

class IPuzzleSolver;

/* ************************************************************************* */

/// <summary>
/// A subgrid in the PuzzleSolver grid
/// </summary>
class SubGrid : public IZone
{
public:

    /// <summary>
    /// construct the nth subgrid
    /// </summary>
    /// <remarks>
    /// The subgrids in the standard board are numbered 
    /// 1-9 left-to-right, top-to-bottom
    /// </remarks>
    /// <param name="solver">The PuzzleSolver containing this SubGrid</param>
    /// <param name="subgridNum">The index of this SubGrid</param>
    SubGrid(IPuzzleSolver &solver, int subgridNum);

    /// <summary>
    /// Construct the subgrid containing the cell (x,y)
    /// </summary>
    /// <param name="solver">The PuzzleSolver containing this SubGrid</param>
    /// <param name="x">x-coord of the reference cell</param>
    /// <param name="y">y-coord of the reference cell</param>
    SubGrid(IPuzzleSolver &solver, int x, int y);

    virtual ~SubGrid() = default;

#pragma region IZone

    ZoneIterator begin() override;
    ZoneIterator end() override;

#pragma endregion

protected:

private:

    /// <summary>
    /// The PuzzleSolver containing this SubGrid
    /// <summary>
    IPuzzleSolver &_solver;

    /// <summary>
    /// The y-coord of the top-left cell in the subgrid
    /// </summary>
    int _top;

    /// <summary>
    /// The x-coord of the top-left cell in the subgrid
    /// </summary>
    int _left;
};

/* ************************************************************************* */

}
