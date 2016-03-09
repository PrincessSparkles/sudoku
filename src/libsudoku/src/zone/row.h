/*
 * row.h
 *
 * Class definition for the Sudoku Row class
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
/// A row in the PuzzleSolver grid
/// </summary>
class Row : public IZone
{
public:

    /// <summary>
    /// construct the nth row
    /// </summary>
    /// <param name="solver">The PuzzleSolver containing this Row</param>
    /// <param name="rowIndex">The index of this Row</param>
    Row(IPuzzleSolver &solver, int rowIndex);
    virtual ~Row() = default;

#pragma region IZone
    
    ZoneIterator begin() override;
    ZoneIterator end() override;
    
#pragma endregion

protected:

private:

    /// <summary>
    /// The PuzzleSolver containing this Row
    /// <summary>
    IPuzzleSolver &_solver;

    /// <summary>
    /// This Row's index
    /// </summary>
    int _rowIndex;
};

/* ************************************************************************* */

}
