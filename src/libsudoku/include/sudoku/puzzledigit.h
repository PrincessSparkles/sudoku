/*
 * puzzledigit.h
 *
 * Class definition for the Sudoku PuzzleDigit class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#pragma once

#include <cstdint>      // std::uint8_t
#include <exception>    // std::exception

namespace Sudoku
{

/* ************************************************************************* */

using PuzzleDigitType = uint8_t;

static const int MaxDigit = 9;

/* ************************************************************************* */

class PuzzleDigit
{
public:
    PuzzleDigit() :
        PuzzleDigit(0)
    {
    }
    
    PuzzleDigit(PuzzleDigitType value)
    {
        Assign(value);
    }
    
    ~PuzzleDigit() = default;
    
    PuzzleDigitType get() const
    {
        return _value;
    }
    
    /// <summary>
    /// The DigitOutOfRange class is thrown when an attempt to create an invalid
    /// digit (i.e. the value of the digit is greater than MaxDigit) is made.
    /// </summary>    
    class DigitOutOfRange : public std::exception
    {
    public:
        DigitOutOfRange() = default;
        ~DigitOutOfRange() = default;
        
        /// <summary>
        /// The exception text
        /// </summary>
        /// <returns>
        /// the excpetion text
        /// </returns>
        const char *what() const noexcept
        {
            return "Sudoku::PuzzleDigit DigitOutOfRange";
        }
    };

protected:

private:

    void Assign(PuzzleDigitType value)
    {
        if (value > MaxDigit)
        {
            throw DigitOutOfRange();
        }
        
        _value = value;
    }

    PuzzleDigitType _value;
};

/* ************************************************************************* */
    
bool operator ==(const PuzzleDigitType &value, const PuzzleDigit &digit);

/* ************************************************************************* */

}
