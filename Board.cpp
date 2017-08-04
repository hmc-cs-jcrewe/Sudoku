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
    for (size_t i = 0; i < 9; ++i)
    {
        rows_[i].rowSize_ = 0;
        columns_[i].rowSize_ = 0;
        squares_[i].squareSize_ = 0;
    }
    //construct the rows_ array
    //need to construct the 0 ,0 location specially because the default cells also have  0 , 0 locations    TODO -- fix this bug
    
    //having trouble dealing with that first cell, won't be a problem in the actual application because every cell will have a location
    if (cells[0].getValue() != 0)
    {
        rows_[0].rowSize_ = 1;
        columns_[0].rowSize_ = 1;
    }

    //trouble dealing with location of 0 , 0
    rows_[0].cells_[0] = cells[0];

    for (size_t i = 1; i < 81; ++i)
    {
        if (cells[i].location_[0] == 0 && cells[i].location_[1] == 0)
        {
            //as of now we need the first cell in the cells array to hold info for the top left corner of the board
            rows_[cells[i].location_[0]].cells_[cells[i].location_[1]]  = cells[0];
        }
        else 
        {
            rows_[cells[i].location_[0]].cells_[cells[i].location_[1]] = cells[i];
            if (cells[i].getValue() != 0)
            {
                ++(rows_[cells[i].location_[0]].rowSize_);
            }
        }

    }
   //construct the columns arrary

   for (size_t i = 0; i < 81; ++i)
   {
       if (cells[i].location_[1] == 0 && cells[i].location_[0] == 0)
        {
            //as of now we need the first cell in the cells array to hold info for the top left corner of the board
            columns_[cells[i].location_[1]].cells_[cells[i].location_[0]]  = cells[0];
        }
        else 
        {
            columns_[cells[i].location_[1]].cells_[cells[i].location_[0]] = cells[i];
            if (cells[i].getValue() != 0)
            {
                ++columns_[cells[i].location_[1]].rowSize_ ;
            }
        }

   }
 //   //construct the squares array -- segmentation fault occurs here
    //when using a default cell, its location_[2] = 0, so 0 - 1 is -1, so it is trying to index -1

    for (size_t i = 0; i < 81; ++i)
    {
        if ( cells[i].location_[2] != 0)
        {
            squares_[(cells[i].location_[2]) - 1].setValue(cells[i]);
        }
    }

    //set isCol values 
    for (size_t i = 0; i < 9; ++i)
    {
        rows_[i].isCol_ = false;
        columns_[i].isCol_ = true;
    }

    //set sizes 


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
    list<Cell> cells;
    for (size_t i = 0; i < 9; ++i)
    {
        cells.push_back(columns_[c].cells_[i]);
    }
    Row newCol = Row (cells, true);
    return newCol;
}

Square SudokuBoard::getSquare(size_t s)
{
	return squares_[s];
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

size_t SudokuBoard::setValue(Cell cell)
{
    rows_[cell.location_[0]].setValue(cell);
    columns_[cell.location_[1]].setValue(cell);
    return squares_[cell.location_[2] - 1].setValue(cell);
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
        //not the same cells within each data structure 
		rows_[i].getPossibilities();
		columns_[i].getPossibilities();
        squares_[i].getPossibilities();
    }

    //consolidate the possibilities from all 3 structures 
    for ( size_t i = 0; i < 9; ++i)
    {
        for (size_t j = 0; j < 9; ++j)
        {
            list<size_t> combined = intersect(rows_[i].cells_[j].possibilities_, columns_[j].cells_[i].possibilities_);     //combines the row and column possibilities
            rows_[i].cells_[j].possibilities_ = combined;           
            columns_[j].cells_[i].possibilities_ = combined;

            list<size_t> finalPoss;
            if ( i < 3)     //square 1 , 2 or 3
            {
                if ( j < 3)     //square 1
                {
                    finalPoss = intersect (rows_[i].cells_[j].possibilities_ , squares_[0].cells_[3 * i + j].possibilities_);
                    squares_[0].cells_[3 * i + j].possibilities_ = finalPoss;
                    rows_[i].cells_[j].possibilities_ = finalPoss;
                    columns_[j].cells_[i].possibilities_ = finalPoss;

                }
                else if ( j < 6)    // square 2
                {
                    finalPoss = intersect (rows_[i].cells_[j].possibilities_ , squares_[1].cells_[3 * i + j - 3].possibilities_);
                    squares_[1].cells_[3 * i + j - 3].possibilities_ = finalPoss;
                    rows_[i].cells_[j].possibilities_ = finalPoss;
                    columns_[j].cells_[i].possibilities_ = finalPoss;
                }
                else            //square 3
                {
                    finalPoss = intersect (rows_[i].cells_[j].possibilities_ , squares_[2].cells_[3 * i + j - 6].possibilities_);
                    squares_[2].cells_[3 * i + j - 6].possibilities_ = finalPoss;
                    rows_[i].cells_[j].possibilities_ = finalPoss;
                    columns_[j].cells_[i].possibilities_ = finalPoss;
                }
            }
            else if ( i < 6)    //square 4, 5  or 6
            {
                if ( j < 3)     //square 4
                {
                    finalPoss = intersect (rows_[i].cells_[j].possibilities_ , squares_[3].cells_[3 * (i - 3) + j].possibilities_);
                    squares_[3].cells_[3 * (i - 3) + j].possibilities_ = finalPoss;
                    rows_[i].cells_[j].possibilities_ = finalPoss;
                    columns_[j].cells_[i].possibilities_ = finalPoss;

                }
                else if ( j < 6)    // square 5
                {
                    finalPoss = intersect (rows_[i].cells_[j].possibilities_ , squares_[4].cells_[3 * (i - 3) + j - 3].possibilities_);
                    squares_[4].cells_[3 * (i - 3) + j - 3].possibilities_ = finalPoss;
                    rows_[i].cells_[j].possibilities_ = finalPoss;
                    columns_[j].cells_[i].possibilities_ = finalPoss;
                }
                else            //square 6
                {
                    finalPoss = intersect (rows_[i].cells_[j].possibilities_ , squares_[5].cells_[3 * (i - 3) + j - 6].possibilities_);
                    squares_[5].cells_[3 * (i - 3) + j - 6].possibilities_ = finalPoss;
                    rows_[i].cells_[j].possibilities_ = finalPoss;
                    columns_[j].cells_[i].possibilities_ = finalPoss;
                }
            }
            else            //square 7 , 8 or 9
            {
                if ( j < 3)     //square 7
                {
                    finalPoss = intersect (rows_[i].cells_[j].possibilities_ , squares_[6].cells_[3 * (i - 6) + j].possibilities_);
                    squares_[6].cells_[3 * (i - 6) + j].possibilities_ = finalPoss;
                    rows_[i].cells_[j].possibilities_ = finalPoss;
                    columns_[j].cells_[i].possibilities_ = finalPoss;

                }
                else if ( j < 6)    // square 8
                {
                    finalPoss = intersect (rows_[i].cells_[j].possibilities_ , squares_[7].cells_[3 * (i - 6) + j - 3].possibilities_);
                    squares_[7].cells_[3 * (i - 6) + j - 3].possibilities_ = finalPoss;
                    rows_[i].cells_[j].possibilities_ = finalPoss;
                    columns_[j].cells_[i].possibilities_ = finalPoss;
                }
                else            //square 9
                {
                    finalPoss = intersect (rows_[i].cells_[j].possibilities_ , squares_[8].cells_[3 * (i - 6) + j - 6].possibilities_);
                    squares_[8].cells_[3 * (i - 6) + j - 6].possibilities_ = finalPoss;
                    rows_[i].cells_[j].possibilities_ = finalPoss;
                    columns_[j].cells_[i].possibilities_ = finalPoss;
                }
            }
        }
    }

    //TODO: combine row/column possibilities with square possibilities
}

// Finding the intersection between two possibilities lists -- the nested loops aren't a 
// problem as this function is still worst case constant runtime 
list<size_t> SudokuBoard::intersect(list<size_t> list1, list<size_t> list2)
{
    list<size_t> results;
    for (auto i = list1.begin() ; i != list1.end() ; ++i)
    {
        for (auto k = list2.begin() ; k != list2.end() ; ++k)
        {
            if (*i == *k)   //if the element in list 1 also exists in list2, add it to results
            {
                results.push_back(*i);
            }
        }
    }
    return results;
}








