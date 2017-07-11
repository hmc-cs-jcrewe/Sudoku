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


 #include "board.hpp"



SudokuBoard::SudokuBoard(Cell cells[81])
{
    //construct the rows_ array
    for (size_t i = 0; i < 9; ++i)
    {
        Row row = Row();
        row.rowSize_ = 0;

        for ( size_t j = 0; j < 9; ++j)
        {
            row.row_[j] = cells[i + j];
            if (!(cells[i + j].isEmpty()))
            {
                ++row.rowSize_;
            }
        }
        rows_[i] = row;
    }

    //construct the columns_ array
    for(size_t i = 0; i < 81; ++i)
    {
        if (i < 9)
        {
            columns_[i % 9].row_[0] = cells[i];
            if (!(cells[i].isEmpty()))
            {
                ++columns_[i % 9].rowSize_;
            }

            break;
        }
        if (i < 18 && i >= 9)
        {
            columns_[i % 9].row_[1] = cells[i];
            if (!(cells[i].isEmpty()))
            {
                ++columns_[i % 9].rowSize_;
            }

            break;
        }
        if ( i < 27 && i >= 18)
        {
            columns_[i % 9].row_[2] = cells[i];
            if (!(cells[i].isEmpty()))
            {
                ++columns_[i % 9].rowSize_;
            }
            break;
        }
        if ( i < 36 && i >= 27)
        {
            columns_[i % 9].row_[3] = cells[i];
            if (!(cells[i].isEmpty()))
            {
                ++columns_[i % 9].rowSize_;
            }

            break;
        }
        if ( i < 45 && i >=36)
        {
            columns_[i % 9].row_[4] = cells[i];
            if (!(cells[i].isEmpty()))
            {
                ++columns_[i % 9].rowSize_;
            }

            break;
        }
        if ( i < 54 && i >= 45)
        {
            columns_[i % 9].row_[5] = cells[i];
            if (!(cells[i].isEmpty()))
            {
                ++columns_[i % 9].rowSize_;
            }

            break;
        }
        if ( i < 63 && i >= 54)
        {
            columns_[i % 9].row_[6] = cells[i];
            if (!(cells[i].isEmpty()))
            {
                ++columns_[i % 9].rowSize_;
            }

            break;
        }
        if ( i < 72 && i >= 63)
        {
            columns_[i % 9].row_[7] = cells[i];
            if (!(cells[i].isEmpty()))
            {
                ++columns_[i % 9].rowSize_;
            }

            break;
        }
        if ( i < 81 && i >= 72)
        {
            columns_[i % 9].row_[8] = cells[i];
            if (!(cells[i].isEmpty()))
            {
                ++columns_[i % 9].rowSize_;
            }

            break;
        }
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

bool SudokuBoard::isComplete()
{
    for (Row row : rows_)
    {
    for (Cell cell : row.row_ )
    {
        if (cell.isEmpty())
        {
            return false;
        }
    }
    }

    for (Row col : columns_)
    {
    for (Cell cell: col.row_)
    {
        if (cell.isEmpty())
        {
            return false;
        }        
    }
    }
    for (int j = 0; j < 3; ++j)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int k = 0; k <3; ++k)
            {
                for( Cell cell: squares_[j][i].square_[k])
                {
                    if (cell.isEmpty())
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool SudokuBoard::inValidSolution()
{
    throw new exception();
}

void SudokuBoard::updatePossibilities()
{
    for (Row row: rows_)
    {
        row.getPossibilities();
    }
    for (Row col : columns_)
    {
        col.getPossibilities();
    }
}








