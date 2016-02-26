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

/// <summary>
/// Class representing legal values in the Puzzle grid
/// </summary>
/// <remarks>
/// A value of zero indicates that the cell is blank (i.e. unsolved)
/// </remarks>
/// <remarks>
/// An attempt to assign or initialise a Digit with a value greater than MaxDigit
/// will result in a DigitOutOfRange exception being thrown
/// </remarks>
class PuzzleDigit
{
public:
    /// <summary>
    /// Default constructor
    /// </summary>
    /// <remarks>
    /// Initialises the value to zero
    /// </remarks>
    PuzzleDigit() :
        PuzzleDigit(0)
    {
    }
    
    /// <summary>
    /// Initialise a digit to the given value
    /// </summary>
    /// <param name="value">The initial value for the digit</param>
    explicit PuzzleDigit(PuzzleDigitType value)
    {
        Assign(value);
    }
    
    ~PuzzleDigit() = default;
    
    /// <summary>
    /// Assign `this` the given value
    /// </summary>
    /// <param name="value">The value to assign</param>
    /// <returns>reference to `this`</returns>
    PuzzleDigit &operator =(const PuzzleDigitType &value)
    {
        Assign(value);
        
        return *this;
    }
    
    /// <summary>
    /// Get the value of this digit
    /// </summary>
    /// <returns>The value of this digit</returns>
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

    /// <summary>
    /// Assign `this` the value <paramref name="value"/>
    /// </summary>
    /// <remarks>
    /// This method performs the check to ensure that <paramref name="value"/> is
    /// less than or equal to `MaxDigit`.
    /// An exception of type DigitOutOfRange is thrown if not.
    /// </remarks>
    /// <param name="value">The value to assign</param>
    void Assign(PuzzleDigitType value)
    {
        if (value > MaxDigit)
        {
            throw DigitOutOfRange();
        }
        
        _value = value;
    }

    /// <summary>
    /// The value of this digit
    /// </summary>
    PuzzleDigitType _value;
};

/* ************************************************************************* */
    
/// <summary>
/// Equality operator
/// </summary>
/// <param name="value">digit to test</param>
/// <param name="digit">digit to test</param>
/// <returns>`value == digit._value`</returns>
bool operator ==(const PuzzleDigitType &value, const PuzzleDigit &digit);

/* ************************************************************************* */

}
