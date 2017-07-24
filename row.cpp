/**
 * \file row.cpp
 *
 * \author Jackson Crewe
 *
 * \brief Declares the Row class.
 */

 //includes go here
#include <list>
#include "row.hpp"

Row::Row()
{
	rowSize_ = 0;
	isCol_ = false;
	for (size_t i = 0; i < 9; ++i)
	{
		cells_[i] = Cell();
	}
}

Row::Row(list<Cell> cells, bool isCol)
{
	rowSize_ = cells.size();
	isCol_ = isCol;
	size_t j = 0;
	for (auto i = cells.begin(); i != cells.end(); ++i)
	{
		Cell newCell = Cell(*i);
		cells_[j] = newCell;
		++j;
	}
}

Row::Row(const Row& row)
{
	rowSize_ = row.rowSize_;
	for (size_t i = 0; i < 9; ++i)
	{
		cells_[i] = row.cells_[i];
	}
}

bool Row::operator==(const Row& rhs)
{
	if (rhs.rowSize_ == rowSize_ && isCol_ == rhs.isCol_)
	{
		for (size_t i = 0; i < 9; ++i)
		{
			if (!(rhs.cells_[i] == cells_[i]))
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

bool Row::operator!=(const Row& rhs)
{
	return !(*this == rhs);
}
bool Row::isCompleteRow()
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

void Row::getPossibilities()
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

size_t Row::setValue(Cell cell)
{
	size_t index = 0;
	if (isCol_)		// use the cell's column location
	{
		index = cell.location_[0];
	}
	else
	{
		index = cell.location_[1];
	}

	Cell newCell = Cell();
	newCell.empty_ = false;
	for (size_t i = 0; i < 3; ++i)
	{
		newCell.location_[i] = cell.location_[i];
	}

	// sets the newCells's possibilities and value to only the first (and hopefully only)
	// element of cell's possibilities list
	newCell.possibilities_ = list<size_t>(1, *(cell.possibilities_.begin()));
	newCell.value_ = *(cell.possibilities_.begin());
	cells_[index] = newCell;
	return newCell.value_;
}