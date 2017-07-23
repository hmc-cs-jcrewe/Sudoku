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
	for (size_t i = 0; i < 9; ++i)
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

size_t Square::setValue (Cell cell)
{
	int index = 100;
	if (cell.location_[0] == 0 || cell.location_[0] == 3 || cell.location_[0] == 6)		//top row of the square
	{
		if(cell.location_[1] == 0 || cell.location_[1] == 3 || cell.location_[1] == 6) 		//first column 
		{
			index = 0;
		}
		if(cell.location_[1] == 1 || cell.location_[1] == 4 || cell.location_[1] == 7) 		//middle column
		{
			index = 1;
		}
		if(cell.location_[1] == 2 || cell.location_[1] == 5 || cell.location_[1] == 8) 		//last column
		{
			index = 2;
		}
	}
	if(cell.location_[0] == 1 || cell.location_[0] == 4 || cell.location_[0] == 7)		//middle row of the square
	{
		if(cell.location_[1] == 0 || cell.location_[1] == 3 || cell.location_[1] == 6) 		//first column 
		{
			index = 3;
		}
		if(cell.location_[1] == 1 || cell.location_[1] == 4 || cell.location_[1] == 7) 		//middle column
		{
			index = 4;
		}
		if(cell.location_[1] == 2 || cell.location_[1] == 5 || cell.location_[1] == 8 ) 		//last column
		{
			index = 5;
		}
	}
	if(cell.location_[0] == 2 || cell.location_[0] == 5 || cell.location_[0] == 8)		//bottom row of the square
	{
		if(cell.location_[1] == 0 || cell.location_[1] == 3 || cell.location_[1] == 6) 		//first column 
		{
			index = 6;
		}
		if(cell.location_[1] == 1 || cell.location_[1] == 4 || cell.location_[1] == 7) 		//middle column
		{
			index = 7;
		}
		if(cell.location_[1] == 2 || cell.location_[1] == 5 || cell.location_[1] == 8) 		//last column
		{
			index = 8;
		}
	}

	cells_[index] = cell;
	++squareSize_;
	return cell.getValue();
}