/*
 * possiblesolution.cpp
 *
 * Class implementation for the Sudoku PossibleSolution class
 *
 * (c) Richard Oak 2016
 */

/* ************************************************************************* */

#include "possiblesolution.h"

/* ************************************************************************* */

using Sudoku::PossibleSolution;

/* ************************************************************************* */
/* ************************************************************************* */

PossibleSolution::PossibleSolution()
{
    for (auto i = 0; i < MaxDigit; i++)
    {
        _possible[i] = true;
    }
}

/* ************************************************************************* */

bool &PossibleSolution::IsPossible(const PuzzleDigitType &digit)
{
    if ((digit == 0) || (digit > MaxDigit)) 
    {
        throw IsPossibleOutOfRange();
    }
    
    return _possible[digit - 1];
}

/* ************************************************************************* */

const bool &PossibleSolution::IsPossible(const PuzzleDigitType &digit) const
{
    if ((digit == 0) || (digit > MaxDigit)) 
    {
        throw IsPossibleOutOfRange();
    }
    
    return _possible[digit - 1];
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
