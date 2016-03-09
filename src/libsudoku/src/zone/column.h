/*
 * column.h
 *
 * Class definition for the Sudoku Column class
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
/// A column in the PuzzleSolver grid
/// </summary>
class Column : public IZone
{
public:
    
    /// <summary>
    /// construct the nth Column
    /// </summary>
    /// <param name="solver">The PuzzleSolver containing this Column</param>
    /// <param name="columnIndex">The index of this Column</param>
    Column(IPuzzleSolver &solver, int columnIndex);
    virtual ~Column() = default;
    
#pragma region IZone
    
    ZoneIterator begin() override;
    ZoneIterator end() override;
    
#pragma endregion

protected:

private:

    /// <summary>
    /// The PuzzleSolver containing this Column
    /// <summary>
    IPuzzleSolver &_solver;
    
    /// <summary>
    /// This Column's index
    /// </summary>
    int _columnIndex;
};

/* ************************************************************************* */

}
