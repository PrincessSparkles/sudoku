/*
 * puzzle.cpp
 *
 * Class implementation for the Sudoku Puzzle class
 *
 * (c) Richard Oak 2016
 */
 
/* ************************************************************************* */

#include <fstream>  // std::ostream
#include <sstream>  // std::stringstream

#include "sudoku/puzzle.h"

/* ************************************************************************* */

using Sudoku::Puzzle;
using Sudoku::PuzzleWidth;
using Sudoku::PuzzleHeight;
using Sudoku::SubGridWidth;
using Sudoku::SubGridHeight;

/* ************************************************************************* */

namespace   // unnamed namespace
{

/* ************************************************************************* */

/// <summary>
/// Get the HTML HEAD for the puzzle
/// </summary>
/// <returns>HTML HEAD tag, containing TITLE and STYLE</returns>
std::string getHTMLHead()
{
    std::string head =
        "<head>\n"
        "    <title>Sudoku - (c) Richard Oak 2016</title>\n"
        "    <style>\n"
        "        table.sudoku {\n"
        "            border-collapse: collapse\n"    
        "        }\n"
        "\n"
        "        tr.sudoku.top {\n"
        "            border-top: 3px solid black;\n"
        "        }\n"
        "\n"
        "        tr.sudoku.bottom {\n"
        "            border-bottom: 3px solid black;\n"
        "        }\n"
        "\n"       
        "        td.sudoku {\n"
        "            border: 1px solid gray;\n"
        "            width: 25;\n"
        "            height: 25;\n"
        "            font-family: sans-serif;\n"
        "            vertical-align: middle;\n"
        "            text-align: center;\n"
        "        }\n"
        "\n"
        "        td.sudoku.left {\n"
        "            border-left: 3px solid black;\n"    
        "        }\n"
        "\n"        
        "        td.sudoku.right {\n"
        "            border-right: 3px solid black;\n"
        "        }\n"
        "    </style>\n"
        "</head>";
    
    return head;
}

/* ************************************************************************* */

/// <summary>
/// Get the HTML BODY for the puzzle
/// </summary>
/// <param name="puzzle">The puzzle for which the HTML is being generated</param>
/// <returns>HTML BODY tag, containing TABLE</returns>
std::string getHTMLBody(const Puzzle &puzzle)
{
    std::stringstream stream;
    
    stream << "<body>" << std::endl;
    stream << "<table class=\"sudoku\">" << std::endl;

    for (auto y = 0; y < PuzzleHeight; y++)
    {
        // open tag, open quote for class names
        stream << "    <tr class=\"sudoku";
        
        if (y % SubGridHeight == 0)
        {
            stream << " top";
        }
        else if (y % SubGridHeight == (SubGridHeight - 1))
        {
            stream << " bottom";
        }
        
        // close quote and close tag
        stream << "\">" << std::endl;
        
        for (auto x = 0; x < PuzzleWidth; x++)
        {
            // open tag, open quote for class names
            stream << "        <td class=\"sudoku";
            
            if (x % SubGridWidth == 0)
            {
                stream << " left";
            }
            else if (x % SubGridWidth == (SubGridWidth - 1))
            {
                stream << " right";
            }
            
            // close quote and close tag
            stream << "\">";
            
            stream << puzzle.Cell(x, y);
            
            stream << "</td>" << std::endl;
        }
        
        stream << "    </tr>" << std::endl;
    }
    
    stream << "</table>" << std::endl;
    stream << "</body>" << std::endl;
    
    return stream.str();
}

/* ************************************************************************* */
    
}   // unnamed namespace

/* ************************************************************************* */
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
                stream << digit;
            }
        }
        
        stream << std::endl;
    }
    
    return stream;
}

/* ************************************************************************* */

std::string Puzzle::getHTML() const
{
    std::stringstream stream;
    
    stream << "<HTML>" << std::endl;
    stream << ::getHTMLHead() << std::endl;
    stream << ::getHTMLBody(*this) << std::endl;
    stream << "</HTML>" << std::endl;
    
    return stream.str();    
}

/* ************************************************************************* */
/* ************************************************************************* */
/* ************************************************************************* */
