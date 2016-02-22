/*
 * twodarray.h
 *
 * Class definition for the Sudoku twodarray class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#pragma once

#include <array>

namespace Sudoku
{

/* ************************************************************************* */

/// <summary>
/// A class representing a fixed size 2-d array
/// </summary>
template<typename T, size_t Width, size_t Height>
class TwoDArray
{
public:

    TwoDArray() = default;    
    virtual ~TwoDArray() = default;
    
    /// <summary>
    /// Get the cell with the specified coordinate
    /// </summary>
    /// <param name="x">The x-coord of the cell</param>
    /// <param name="y">The y-coord of the cell</param>
    /// <returns>The desired cell</returns>
    T &Cell(size_t x, size_t y)
    {
        size_t pos = GetIndex(x, y);
        
        return _array[pos];
    }
    
    /// <summary>
    /// Get the cell with the specified coordinate
    /// </summary>
    /// <param name="x">The x-coord of the cell</param>
    /// <param name="y">The y-coord of the cell</param>
    /// <returns>The desired cell</returns>
    const T &Cell(size_t x, size_t y) const
    {
        size_t pos = GetIndex(x, y);
        
        return _array[pos];
    }
    
    /// <summary>
    /// The IndexOutOfRange class is thrown when an attempt to reference a Cell
    /// outside the specified range of the TwoDArray
    /// </summary>    
    class IndexOutOfRange : public std::exception
    {
    public:
        IndexOutOfRange() = default;
        ~IndexOutOfRange() = default;
        
        /// <summary>
        /// The exception text
        /// </summary>
        /// <returns>
        /// the excpetion text
        /// </returns>
        const char *what() const noexcept
        {
            return "Sudoku::TwoDArray IndexOutOfRange";
        }
    };
    
protected:

private:    

    /// <summary>
    /// Compute the index of the given cell within the 1-D array
    /// </summary>
    /// <param name="x">The x-coord of the cell</param>
    /// <param name="y">The y-coord of the cell</param>
    /// <returns>The index within `_array`</returns>
    static std::size_t GetIndex(size_t x, size_t y)
    {
        if (x >= Width)
        {
            throw IndexOutOfRange{};
        }
    
        if (y >= Height)
        {
            throw IndexOutOfRange{};
        }
        
        return (y * Width) + x;
    }

    /// <summary>
    /// 1-D array holding the 2-D array information
    /// </summary>
    /// <remarks>
    /// The 1-D array is layed out as contiguous rows from the 2-D array
    /// </remarks>
    std::array<T, Width * Height> _array;
};

/* ************************************************************************* */

}
