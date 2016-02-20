/*
 * puzzle.h
 *
 * Class definition for the Sudoku Puzzle class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#pragma once

#include <cstdint>    // for uint8_t

#include "twodarray.h"  // TwoDArray

namespace Sudoku
{

/* ************************************************************************* */

using PuzzleDigit = std::uint8_t;

static const int PuzzleWidth = 9;
static const int PuzzleHeight = 9;

static const int SubGridWidth = 3;
static const int SubGridHeight = 3;

/* ************************************************************************* */

class Puzzle : public TwoDArray<PuzzleDigit, PuzzleWidth, PuzzleHeight>
{
public:
    Puzzle();
    ~Puzzle() = default;

protected:

private:
};

/* ************************************************************************* */

}
