/*
 * puzzle.cpp
 *
 * Class implementation for the Sudoku Puzzle class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include <fstream>

#include "sudoku/puzzle.h"

/* ************************************************************************* */

using Sudoku::Puzzle;
using Sudoku::PuzzleWidth;
using Sudoku::PuzzleHeight;

/* ************************************************************************* */

std::ostream &Sudoku::operator <<(std::ostream &stream, const Puzzle &puzzle)
{
	for (auto y = 0; y < PuzzleHeight; y++)
	{
		for (auto x = 0; x < PuzzleWidth; x++)
		{
			PuzzleDigit digit = puzzle.Cell(x, y);
			
			if (digit == 0)
			{
				stream << ".";
			}
			else
			{
				stream << digit.get();
			}
		}
		
		stream << std::endl;
	}
	
	return stream;
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
