/*
 * zonesolver.cpp
 *
 * Class implementation for the Sudoku ZoneSolver class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include "zonesolver.h"
#include "solver/solverelem.h"
#include "iterator/zoneiterator.h"

/* ************************************************************************* */

using Sudoku::ZoneSolver;

/* ************************************************************************* */
/* ************************************************************************* */

Sudoku::PuzzleDigit ZoneSolver::GetSolution(const SolverElem &cell)
{
    PuzzleDigit solution(0);
    
    for (auto i = 1; i <= MaxDigit; i++)
    {
        if (cell.IsPossible(i))
        {
            for (auto &zone : cell.Zones())
            {
                int count = 0;
                
                for (auto &elem : *zone)
                {
                    if (elem.IsPossible(i))
                    {
                        count++;
                    }
                }
                
                if (count == 1)
                {
                    // there's one cell in the zone where 'i' is possible
                    // and it's this cell
                    solution = i;
                    break;
                }
            }
            
            if (solution.get() != 0)
            {
                // we found a solution
                break;
            }
        }
    }
    
    return solution;
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
