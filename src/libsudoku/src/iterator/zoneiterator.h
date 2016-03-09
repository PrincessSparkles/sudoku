/*
 * zoneiterator.h
 *
 * Class definition for the Sudoku ZoneIterator class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#pragma once

#include <iterator> // std::iterator
#include <memory>   // std::shared_ptr

namespace Sudoku
{

/* ************************************************************************* */

class IPuzzleSolver;
class SolverElem;

/* ************************************************************************* */

/// <summary>
/// Loop over all of the cells in a zone
/// </summary>
class ZoneIterator : public std::iterator<std::input_iterator_tag, int>
{
public:

    /// <summary>
    /// Method for retrieving cells from a zone
    /// </summary> 
    class IStrategy
    {
    public:
        
        virtual ~IStrategy() = default;
        
        /// <summary>
        /// Get the nth cell in the zone
        /// </summary>
        /// <param name="solver">The IPuzzleSolver containing the cell</param>
        /// <param name="index">The index of the cell to get</param>
        /// <returns>The nth cell in the zone</returns>
        virtual SolverElem &GetCell(IPuzzleSolver &solver, int index) const = 0;
    
    protected:
    
    private:
    };

    /// <summary>
    /// construct an iterator for a zone
    /// </summary>
    /// <param name="solver">
    /// The PuzzleSolver over whose cells we are iterating
    /// </param>
    /// <param name="index">
    /// index of the cell we're going to return
    /// </param> 
    /// <param name="strategy">
    /// method of indexing the cells in the zone
    /// </param> 
    ZoneIterator(IPuzzleSolver &solver, int index, 
        std::shared_ptr<IStrategy> strategy);
    
    virtual ~ZoneIterator() = default;

    /// <summary>
    /// move `this` to point to the next cell
    /// </summary>
    /// <returns>`*this`</returns>
    ZoneIterator &operator++();
    
    /// <summary>
    /// Get the next cell
    /// </summary>
    /// <returns>an iterator pointing to the next cell</returns>
    ZoneIterator operator++(int);
    
    /// <summary>
    /// Equality operator
    /// </summary>
    /// <remarks>
    /// ZoneIterators are equal if their `_index`s are equal
    /// </remarks>
    /// <param name="other">object to compare against</param>
    /// <returns>
    /// true if `this == `<paramref name="other"/>, false otherwise
    /// </returns>
    bool operator ==(const ZoneIterator &other);
    
    /// <summary>
    /// Non-equality operator
    /// </summary>
    /// <remarks>
    /// ZoneIterators are equal if their `_index`s are equal
    /// </remarks>
    /// <param name="other">object to compare against</param>
    /// <returns>
    /// true if `this != `<paramref name="other"/>, false otherwise
    /// </returns>
    bool operator !=(const ZoneIterator &other);
    
    /// <summary>
    /// Get the current cell
    /// </summary>
    /// <returns>The current cell</returns>
    SolverElem &operator *();

protected:

private:

    /// <summary>
    /// The PuzzleSolver over whose cells we are iterating
    /// </summary>
    IPuzzleSolver &_solver;
    
    /// <summary>
    /// index of the cell we're going to return
    /// </summary> 
    int _index;

    /// <summary>
    /// method of indexing the cells in the zone
    /// </summary> 
    std::shared_ptr<IStrategy> _strategy;
};

/* ************************************************************************* */

}
