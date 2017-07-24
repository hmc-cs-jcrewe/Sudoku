/**
 * \file board.cpp
 *
 * \author Jackson Crewe
 *
 * \brief Declares the SudokuBoard class.
 */

 //includes go here
 #include <stdexcept>
 #include <list>
 #include <iostream>


 #include "Board.hpp"



SudokuBoard::SudokuBoard(Cell cells[81])
{
    //construct the rows_ array
    for (size_t i = 0; i < 81; ++i)
    {
        rows_[cells[i].location_[0]].cells_[cells[i].location_[1]] = cells[i];
    }

   // for (size_t i = 0; i < 9; ++i)
   // {
   //     Row row = Row();
   //     row.rowSize_ = 0;
//
   //     for ( size_t j = 0; j < 9; ++j)
   //     {
   //         row.cells_[j] = cells[i + j];
   //         if (!(cells[i + j].isEmpty()))
   //         {
   //             ++row.rowSize_;
   //         }
   //     }
   //     rows_[i] = row;
   // }
//
   // //construct the columns_ array
   // for(size_t i = 0; i < 81; ++i)
   //// {
   //     if (i < 9)
   //     {
   //         columns_[i % 9].cells_[0] = cells[i];
   //         if (!(cells[i].isEmpty()))
   //         {
   //             ++columns_[i % 9].rowSize_;
   //         }
//
   //         break;
   //     }
   //     if (i < 18 && i >= 9)
   //     {
   //         columns_[i % 9].cells_[1] = cells[i];
   //         if (!(cells[i].isEmpty()))
   //         {
   //             ++columns_[i % 9].rowSize_;
   //         }
//
   //         break;
   //     }
   //     if ( i < 27 && i >= 18)
   //     {
   //         columns_[i % 9].cells_[2] = cells[i];
   //         if (!(cells[i].isEmpty()))
   //         {
   //             ++columns_[i % 9].rowSize_;
   //         }
   //         break;
   //     }
   //     if ( i < 36 && i >= 27)
   //     {
   //         columns_[i % 9].cells_[3] = cells[i];
   //         if (!(cells[i].isEmpty()))
   //         {
   //             ++columns_[i % 9].rowSize_;
   //         }
//
   //         break;
   //     }
   //     if ( i < 45 && i >=36)
   //     {
   //         columns_[i % 9].cells_[4] = cells[i];
   //         if (!(cells[i].isEmpty()))
   //         {
   //             ++columns_[i % 9].rowSize_;
   //         }
//
   //         break;
   //     }
   //     if ( i < 54 && i >= 45)
   //     {
   //         columns_[i % 9].cells_[5] = cells[i];
   //         if (!(cells[i].isEmpty()))
   //         {
   //             ++columns_[i % 9].rowSize_;
   //         }
//
   //         break;
   //     }
   //     if ( i < 63 && i >= 54)
   //     {
   //         columns_[i % 9].cells_[6] = cells[i];
   //         if (!(cells[i].isEmpty()))
   //         {
   //             ++columns_[i % 9].rowSize_;
   //         }
//
   //         break;
   //     }
   //     if ( i < 72 && i >= 63)
   //     {
   //         columns_[i % 9].cells_[7] = cells[i];
   //         if (!(cells[i].isEmpty()))
   //         {
   //             ++columns_[i % 9].rowSize_;
   //         }
//
   //         break;
   //     }
   //     if ( i < 81 && i >= 72)
   //     {
   //         columns_[i % 9].cells_[8] = cells[i];
   //         if (!(cells[i].isEmpty()))
   //         {
   //             ++columns_[i % 9].rowSize_;
   //         }
//
   //         break;
   //     }
   //// }
//
   //construct the columns arrary

   for (size_t i = 0; i < 81; ++i)
   {
        columns_[cells[i].location_[1]].cells_[cells[i].location_[0]] = cells[i];
   }
    //construct the squares array
    for (size_t i = 0; i < 81; ++i)
    {
        squares_[(cells[i].location_[2]) - 1].setValue(cells[i]);
    }
}

SudokuBoard::SudokuBoard(const SudokuBoard& other)
{
	for (size_t i = 0; i < 9; ++i)
	{
		columns_[i] = other.columns_[i];
		rows_[i] = other.rows_[i];
        squares_[i] = other.squares_[i];
	}
}

Row SudokuBoard::getRow(size_t r)
{
    return rows_[r];
}

Row SudokuBoard::getCol(size_t c)
{
    return columns_[c];
}

Square SudokuBoard::getSquare(size_t s)
{
	return squares_[s];
}
Row SudokuBoard::makeRow(int values[9])
{
	size_t rowSize = 0; 
	list<Cell> rowCells;

	for (size_t i = 0; i < 9; ++i)
	{
		// it is a cell with a value 
		if (values[i] != -1)
		{
			++rowSize;
			Cell newCell = Cell(values[i]);
			rowCells.push_back(newCell);
		}
	}
	
	Row newRow = Row(rowCells, false);
	return newRow;
}

Row SudokuBoard::makeCol(int values[9])
{
	size_t rowSize = 0;
	list<Cell> rowCells;

	for (size_t i = 0; i < 9; ++i)
	{
		// it is a cell with a value 
		if (values[i] != -1)
		{
			++rowSize;
			Cell newCell = Cell(values[i]);
			rowCells.push_back(newCell);
		}
	}

	Row newRow = Row(rowCells, true);
	return newRow;
}


Square SudokuBoard::makeSquare(int values[9])
{
	size_t squareSize = 0;
	list<Cell> cellList;
	for (size_t i = 0; i < 9; ++i)
	{
		//it is a cell with a value
		if (values[i] != 0)
		{
			++squareSize;
			Cell newCell = Cell(values[i]);
			cellList.push_back(newCell);
		}
	}
	Square newSquare = Square(cellList);
	return newSquare;
}

bool SudokuBoard::operator==(const SudokuBoard& other)
{
	for (size_t i = 0; i < 9; ++i)
	{
		if (!(rows_[i] == other.rows_[i]))
		{
			return false;
		}
		if (!(columns_[i] == other.columns_[i]))
		{
			return false;
		}
		if (!(squares_[i] == other.squares_[i]))
		{
			return false;
		}
	}
	return true;
}

bool SudokuBoard::operator!=(const SudokuBoard& other)
{
	return !(*this == other);
}

bool SudokuBoard::isComplete()
{
    for (Row row : rows_)
    {
		if (!row.isCompleteRow())
		{
			return false;
		}
    }

    for (Row col : columns_)
    {
		if (!col.isCompleteRow())
		{
			return false;
		}
    }
    for(Square square: squares_)
    {
        if (!square.isCompleteSquare())
        {
            return false;
        }
    }
    return true;
}

//when there are no more possibilities left for any of the cells but the board isn't complete
bool SudokuBoard::inValidSolution()
{
	if (isComplete())
	{ return false; }

	for (size_t i = 0; i < 9; ++i)
	{
		for (size_t j = 0; j < 9; ++j)
		{
			if (!(rows_[i].cells_[j].possibilities_.empty()) || !(columns_[i].cells_[j].possibilities_.empty()))
			{ return false; }
		}
	}

    for (int i = 0; i < 3; ++i)
    {
        for (int k = 0; k <9; ++k)
        {
            if (!(squares_[i].cells_[k].possibilities_.empty()))
            { return false; }
        }
    }
	return true;
}

void SudokuBoard::updatePossibilities()
{
    for (size_t i = 0; i < 9; ++i)
    {
		rows_[i].getPossibilities();
		columns_[i].getPossibilities();
    }

	for (size_t i = 0; i < 9; ++i)
	{
        squares_[i].getPossibilities();	
	}
}








