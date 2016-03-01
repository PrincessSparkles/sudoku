/*
 * possiblesolution.h
 *
 * Class definition for the Sudoku PossibleSolution class
 *
 * (c) Richard Oak 2016
 */

/* ************************************************************************* */

#pragma once

#include <array>    // std::array

#include "sudoku/puzzledigit.h" // MaxDigit,PuzzleDigitType

namespace Sudoku
{ 

/* ************************************************************************* */

/// <summary>
/// Is it possible to put digit 'x' in this cell, or has it been eliminated?
/// </summary>
/// <remarks>
/// The array is indexed 0-MaxDigit, but we access it 1-MaxDigit+1. So we
/// use the IsPossible methods to access the array to ensure we always
/// use the right index
/// </remarks>
class PossibleSolution
{
public:
    /// <summary>
    /// constructor
    /// </summary>
    PossibleSolution();
    ~PossibleSolution() = default;
    
    /// <summary>
    /// Gets/Sets whether digit 'x' is a possibility for this cell
    /// </summary>
    /// <param name="digit">The digit that might be possible</param>
    /// <returns>the possibility</returns>
    bool &IsPossible(const PuzzleDigitType &digit);

    /// <summary>
    /// Gets whether digit 'x' is a possibility for this cell
    /// </summary>
    /// <param name="digit">The digit that might be possible</param>
    /// <returns>the possibility</returns>
    const bool &IsPossible(const PuzzleDigitType &digit) const;

    /// <summary>
    /// The IsPossibleOutOfRange class is thrown when an attempt index the
    /// _possible array is made that does not equate to a valid digit
    /// </summary>    
    /// <remarks>
    /// Zero is considered an invalid digit (as it represents a blank cell)
    /// </remarks> 
    class IsPossibleOutOfRange : public std::exception
    {
    public:
        IsPossibleOutOfRange() = default;
        ~IsPossibleOutOfRange() = default;
        
        /// <summary>
        /// The exception text
        /// </summary>
        /// <returns>
        /// the excpetion text
        /// </returns>
        const char *what() const noexcept
        {
            return "Sudoku::PossibleSolution IsPossibleOutOfRange";
        }
    };

protected:

private:

    /// <summary>
    /// array holding the possibilities
    /// </summary>
    /// <remarks>
    /// The array is indexed 0-MaxDigit, but we access it 1-MaxDigit+1. So we
    /// use the IsPossible methods to access the array to ensure we always
    /// use the right index
    /// </remarks>
    std::array<bool, MaxDigit> _possible;  
};

/* ************************************************************************* */

}
