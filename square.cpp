/**
 * \file cell.cpp
 *
 * \author Jackson Crewe
 *
 * \brief Declares the Square class.
 */

//includes go here
#include "square.hpp"

Square::Square()
{
    squareSize_ = 0;
    for (size_t i = 0; i < 9; i++)
    {
        cells_[i] = Cell();
    }
}

Square::Square(list<Cell> cells)
{
    squareSize_ = cells.size();
    size_t j = 0;
    for (auto i = cells.begin(); i != cells.end(); ++i)
    {
        Cell newCell = Cell(*i);
        cells_[j] = newCell;
        ++j;
    }
}

Square::Square(const Square & square)
{
	squareSize_ = square.squareSize_;
	for (size_t i = 0; i < 10; ++i)
	{
		cells_[i] = square.cells_[i];
	}
}

bool Square::isCompleteSquare()
{
   for (size_t i = 0; i < 9; ++i)
	{
		if (cells_[i].isEmpty())
		{
			return false;
		}
	}
	return true;
}

void Square::getPossibilities()
{
    list<size_t> values;
	// build up all the values that have been placed in the row
	for (size_t i = 0; i < 9; ++i)
	{
		if (!cells_[i].isEmpty())
		{
			values.push_back(cells_[i].getValue());
		}
	}

	// remove every value in values from the possibilities list assigned to 
	// and cell that is still empty
	for (size_t i = 0; i < 9; ++i)
	{
		if (cells_[i].isEmpty())
		{
			for (auto j = values.begin(); j != values.end(); ++j)
			{
				cells_[i].possibilities_.remove(*j);
			}
		}
	}
}