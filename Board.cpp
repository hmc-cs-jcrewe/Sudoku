/**
 * \file Board.cpp
 *
 * \author Jackson Crewe
 *
 * \brief Implements the SudokuBoard class. For further documentation, see Board.hpp
 */

 //includes go here
 #include <stdexcept>
 #include <list>
 #include <iostream>


 #include "Board.hpp"


SudokuBoard::SudokuBoard()
{
        //Create 81 empty cells that all contain a location
    Cell cells[81];
    cells[0] = Cell(0,0,0,1);
    cells[1] = Cell(0,0,1,1);
    cells[2] = Cell(0,0,2,1);
    cells[3] = Cell(0,0,3,2);
    cells[4] = Cell(0,0,4,2);
    cells[5] = Cell(0,0,5,2);
    cells[6] = Cell(0,0,6,3);
    cells[7] = Cell(0,0,7,3);
    cells[8] = Cell(0,0,8,3);
    cells[9] = Cell(0,1,0,1);
    cells[10] = Cell(0,1,1,1);
    cells[11] = Cell(0,1,2,1);
    cells[12] = Cell(0,1,3,2);
    cells[13] = Cell(0,1,4,2);
    cells[14] = Cell(0,1,5,2);
    cells[15] = Cell(0,1,6,3);
    cells[16] = Cell(0,1,7,3);
    cells[17] = Cell(0,1,8,3);
    cells[18] = Cell(0,2,0,1);
    cells[19] = Cell(0,2,1,1);
    cells[20] = Cell(0,2,2,1);
    cells[21] = Cell(0,2,3,2);
    cells[22] = Cell(0,2,4,2);
    cells[23] = Cell(0,2,5,2);
    cells[24] = Cell(0,2,6,3);
    cells[25] = Cell(0,2,7,3);
    cells[26] = Cell(0,2,8,3);
    cells[27] = Cell(0,3,0,4);
    cells[28] = Cell(0,3,1,4);
    cells[29] = Cell(0,3,2,4);
    cells[30] = Cell(0,3,3,5);
    cells[31] = Cell(0,3,4,5);
    cells[32] = Cell(0,3,5,5);
    cells[33] = Cell(0,3,6,6);
    cells[34] = Cell(0,3,7,6);
    cells[35] = Cell(0,3,8,6);
    cells[36] = Cell(0,4,0,4);
    cells[37] = Cell(0,4,1,4);
    cells[38] = Cell(0,4,2,4);
    cells[39] = Cell(0,4,3,5);
    cells[40] = Cell(0,4,4,5);
    cells[41] = Cell(0,4,5,5);
    cells[42] = Cell(0,4,6,6);
    cells[43] = Cell(0,4,7,6);
    cells[44] = Cell(0,4,8,6);
    cells[45] = Cell(0,5,0,4);
    cells[46] = Cell(0,5,1,4);
    cells[47] = Cell(0,5,2,4);
    cells[48] = Cell(0,5,3,5);
    cells[49] = Cell(0,5,4,5);
    cells[50] = Cell(0,5,5,5);
    cells[51] = Cell(0,5,6,6);
    cells[52] = Cell(0,5,7,6);
    cells[53] = Cell(0,5,8,6);
    cells[54] = Cell(0,6,0,7);
    cells[55] = Cell(0,6,1,7);
    cells[56] = Cell(0,6,2,7);
    cells[57] = Cell(0,6,3,8);
    cells[58] = Cell(0,6,4,8);
    cells[59] = Cell(0,6,5,8);
    cells[60] = Cell(0,6,6,9);
    cells[61] = Cell(0,6,7,9);
    cells[62] = Cell(0,6,8,9);
    cells[63] = Cell(0,7,0,7);
    cells[64] = Cell(0,7,1,7);
    cells[65] = Cell(0,7,2,7);
    cells[66] = Cell(0,7,3,8);
    cells[67] = Cell(0,7,4,8);
    cells[68] = Cell(0,7,5,8);
    cells[69] = Cell(0,7,6,9);
    cells[70] = Cell(0,7,7,9);
    cells[71] = Cell(0,7,8,9);
    cells[72] = Cell(0,8,0,7);
    cells[73] = Cell(0,8,1,7);
    cells[74] = Cell(0,8,2,7);
    cells[75] = Cell(0,8,3,8);
    cells[76] = Cell(0,8,4,8);
    cells[77] = Cell(0,8,5,8);
    cells[78] = Cell(0,8,6,9);
    cells[79] = Cell(0,8,7,9);
    cells[80] = Cell(0,8,8,9);

    *this = SudokuBoard(cells);
}
SudokuBoard::SudokuBoard(Cell cells[81])
{
    for (size_t i = 0; i < 9; ++i)
    {
        rows_[i].rowSize_ = 0;
        columns_[i].rowSize_ = 0;
        squares_[i].squareSize_ = 0;
    }
    //construct the rows_ array    
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

void SudokuBoard::print(ostream& loc)
{
    loc << "\e[1m" << "------------------------------------" << "\e[0m" << std::endl;
    for (size_t i = 0; i < 9; ++i)
    {
        for (Cell cell : rows_[i].cells_)
        {
            if (cell.location_[1] == 0 || cell.location_[1] == 3 || cell.location_[1] == 6)
            {
                if (cell.getValue() != 0)
                {
                    loc << "\e[1m" << "| " << "\e[0m" << cell.getValue() << " ";
                }
                else
                {
                    loc << "\e[1m" << "| " << "\e[0m" << " " << " ";
                }
            }
            else 
            {
                if (cell.getValue() != 0)
                {
                    loc << "| " << cell.getValue() << " ";
                }
                else
                {
                    loc << "| " << " " << " ";
                }
            }
        }
        loc << "\e[1m" << "|" << "\e[0m" << std::endl;
        if (i == 2 || i == 5 || i == 8)
        {
            loc << "\e[1m" << "------------------------------------" << "\e[0m" << std::endl;
        }
        else
        {
            loc << "------------------------------------" << std::endl;
        }

    }
}








