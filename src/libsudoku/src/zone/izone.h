/*
 * izone.h
 *
 * Class definition for the Sudoku IZone interface
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#pragma once

namespace Sudoku
{

/* ************************************************************************* */

// forward declaration
class ZoneIterator;

/* ************************************************************************* */

/// <summary>
/// Interface representing a zone on the puzzle board
/// </summary>
class IZone
{
public:

    /// <summary>
    /// virtual destructor
    /// </summary>
    virtual ~IZone() = default;

    /// <summary>
    /// Returns a ZoneIterator pointing to the first cell of the zone
    /// </summary>
    /// <returns>An iterator to the beginning of the zone</returns>
    virtual ZoneIterator begin() = 0;

    /// <summary>
    /// Returns a ZoneIterator referring to the <i>past-the-end</i>
    /// cell in the zone
    /// </summary>
    /// <returns>An iterator past the last cell of the zone</returns>
    virtual ZoneIterator end() = 0;

protected:

private:
};

/* ************************************************************************* */

}
