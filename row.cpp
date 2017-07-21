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
	for (size_t i = 0; i < 9; ++i)
	{
		cells_[i] = Cell();
	}
}

Row::Row(size_t size, list<Cell> cells)
{
	rowSize_ = size;
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
