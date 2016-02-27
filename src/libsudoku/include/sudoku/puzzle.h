/*
 * puzzle.h
 *
 * Class definition for the Sudoku Puzzle class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#pragma once

#include <string>

#include "twodarray.h"      // TwoDArray
#include "puzzledigit.h"    // PuzzleDigit

namespace Sudoku
{

/* ************************************************************************* */

/// <summary>
/// The width of a sudoku puzzle
/// </summary>
static const int PuzzleWidth = 9;
/// <summary>
/// The height of a sudoku puzzle
/// </summary>
static const int PuzzleHeight = 9;

/// <summary>
/// The width of a sub-grid within a sudoku puzzle
/// </summary>
static const int SubGridWidth = 3;
/// <summary>
/// The height of a sub-grid within a sudoku puzzle
/// </summary>
static const int SubGridHeight = 3;

/* ************************************************************************* */

/// <summary>
/// A class representing the sudoku puzzle
/// </summary>
/// <remarks>
/// A Cell with a value of 0 is considered blank.
/// </remarks>
class Puzzle : public TwoDArray<PuzzleDigit, PuzzleWidth, PuzzleHeight>
{
public:

    /// <summary>
    /// constructor
    /// </summary>
    /// <remarks>
    /// The Puzzle is initially set to blank
    /// </remarks>
    Puzzle() = default;
    ~Puzzle() = default;
    
    /// <summary>
    /// Get a page of HTML that draws the Puzzle
    /// </summary>
    /// <returns>The HTML page</returns>
    std::string getHTML() const;

protected:

private:
};

/* ************************************************************************* */

std::ostream &operator <<(std::ostream &os, const Puzzle &puzzle);

/* ************************************************************************* */

}
