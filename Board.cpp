/**
 * \file chunkystring.cpp
 *
 * \author Jackson Crewe
 *
 * \brief Declares the SudokuBoard class.
 */

 //includes go here
 #include <stdexcept>


 #include "Board.hpp"


 //SudokuBoard class definition

//parameterized constructor
SudokuBoard::SudokuBoard(Cell[] cells)
{
    throw new exception();
}

SudokuBoard::Row SudokuBoard::getRow(size_t r)
{
    throw new exception();
}

SudokuBoard::Row SudokuBoard::getCol(size_t c)
{
    throw new exception();
}

SudokuBoard::Row SudokuBoard::makeRow(size_t[] values)

{
    throw new exception();
}

SudokuBoard::Row SudokuBoard::makeCol(size_t[] values)
{
    throw new exception();
}

SudokuBoard::Square SudokuBoard::makeSquare(size_t[] values)
{
    throw new exception();
}

bool SudokuBoard::isComplete()
{
    throw new exception();
}

bool SudokuBoard::inValidSolution()
{
    throw new exception();
}

void SudokuBoard::updatePossibilities()
{
    throw new exception();
}


//Cell subclass definition

SudokuBoard::Cell::Cell()
{
    throw new exception();
}

SudokuBoard::Cell::Cell(size_t value, size_t row, size_t col, size_t squareNum)
{
    throw new exception();
}

bool SudokuBoard::Cell::isEmpty()
{
    throw new exception();
}

size_t SudokuBoard::Cell::getValue()
{
    throw new exception();
}

size_t SudokuBoard::Cell::getLocation()
{
    throw new exception();
}

size_t SudokuBoard::Cell::numPossibilities()
{
    throw new exception();
}


//Row subclass definition

SudokuBoard::Row::Row()
{
    throw new exception();
}

SudokuBoard::Row::Row(size_t size, Cell[] cells)
{
    throw new exception();
}

bool SudokuBoard::Row::completeRow()
{
    throw new exception();
}

//Square subclass definition

SudokuBoard::Square::Square()
{
    throw new exception();
}

SudokuBoard::Square::Square(size_t size, Cell[] cells)
{
    throw new exception();
}

bool SudokuBoard::Square::completeSquare()
{
    throw new exception();
}
