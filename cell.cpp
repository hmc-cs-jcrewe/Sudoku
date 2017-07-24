/**
 * \file cell.cpp
 *
 * \author Jackson Crewe
 *
 * \brief Declares the Cell class.
 */

//includes go here
#include <stdexcept>

#include "cell.hpp"

using namespace std;
Cell::Cell()
{
    value_ = 0;
    empty_ = true;
	for (size_t i = 0; i < 3; ++i)
	{
		location_[i] = (size_t)0;
	}

    for (size_t i = 1; i < 10; ++i)
    {
        possibilities_.push_back(i);
    }
}

Cell::Cell(int value, size_t row, size_t col, size_t squareNum)
{
    value_ = value;
	location_[0] = row;
	location_[1] = col;
	location_[2] = squareNum;
    if (value == 0)
    {
        empty_ = true;
        for (size_t i  = 1; i < 10 ; ++i)
        {
            possibilities_.push_back(i);
        }
    } else {
        empty_ = false;
        possibilities_.push_back(value);
    }
    
}

Cell::Cell(int value)
{
    value_ = value;
	for (size_t i = 0; i < 3; ++i)
	{
		location_[i] = (size_t)0;
	}
    if (value == 0)
    {
        empty_ = true;
        for (size_t i  = 1; i < 10 ; ++i)
        {
            possibilities_.push_back(i);
        }
    }
    else{
        empty_ = false;
        possibilities_.push_back(value);

    } 
}

Cell::Cell(const Cell& cell)
{
    empty_ = cell.empty_;
    value_ = cell.value_;
    possibilities_ = cell.possibilities_;
	for (size_t i = 0; i < 3; ++i)
	{
		location_[i] = cell.location_[i];
	}
}
 
bool Cell::operator==(const Cell& rhs)
{

    if(value_ == rhs.value_ && empty_ == rhs.empty_ 
            && possibilities_ == rhs.possibilities_)
            {
                for (size_t i = 0; i < 3; ++i)
                {
                    if (location_[i] != rhs.location_[i])
                    {
                        return false;
                    }
                }
                return true;
            }
    return false;
}

 bool Cell::operator!=(const Cell& rhs)
 {
    return !(*this == rhs);
 }

 Cell& Cell::operator=(const Cell& rhs)
 {
     value_ = rhs.value_;
     empty_ = rhs.empty_;
     possibilities_ = rhs.possibilities_;
     for (size_t i = 0; i < 3; ++i)
     {
         location_[i] = rhs.location_[i];
     }
     return *this;
 }
bool Cell::isEmpty()
{
    if (value_ == 0)
    {
        return true;
    }
    return false;
}

size_t Cell::getValue()
{
    return value_;
}

size_t Cell::numPossibilities()
{
    return possibilities_.size();
}