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

template<typename T, size_t Width, size_t Height>
class TwoDArray
{
public:

    TwoDArray() = default;    
    ~TwoDArray() = default;
    
    T &Cell(size_t x, size_t y)
    {
        size_t pos = GetIndex(x, y);
        
        return _array[pos];
    }
    
    const T &Cell(size_t x, size_t y) const
    {
        size_t pos = GetIndex(x, y);
        
        return _array[pos];
    }
        
    class IndexOutOfRange : public std::exception
    {
    public:
        IndexOutOfRange() = default;
        ~IndexOutOfRange() = default;
        
        const char *what() const noexcept
        {
            return "Sudoku::TwoDArray IndexOutOfRange";
        }
    };
    
protected:

private:    

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

    std::array<T, Width * Height> _array;
};

/* ************************************************************************* */

}
