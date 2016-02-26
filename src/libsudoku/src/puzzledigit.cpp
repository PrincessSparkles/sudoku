/*
 * puzzledigit.cpp
 *
 * Class implementation for the Sudoku PuzzleDigit class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include <fstream>

#include "sudoku/puzzledigit.h"

/* ************************************************************************* */

/* ************************************************************************* */
/* ************************************************************************* */

bool Sudoku::operator ==(const PuzzleDigitType &value, const PuzzleDigit &digit)
{
    return value == digit.get();
}

/* ************************************************************************* */

bool Sudoku::operator ==(const PuzzleDigit &digit, const PuzzleDigitType &value)
{
    return digit.get() == value;
}

/* ************************************************************************* */
/* ************************************************************************* */

std::ostream &Sudoku::operator <<(std::ostream &stream, const PuzzleDigit &digit)
{
    if (digit == 0)
    {
        stream << " ";
    }
    else
    {
        stream << digit.get();
    }
    
    return stream;
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
