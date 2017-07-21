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
    location_ = {0,0,0};
    for (size_t i = 1; i < 10; ++i)
    {
        possibilities_.push_back(i);
    }
}

Cell::Cell(int value, size_t row, size_t col, size_t squareNum)
{
    value_ = value;
    location_ = {row, col, squareNum};
    empty_ = true;
    for (size_t i = 1; i < 10; ++i)
    {
        possibilities_.push_back(i);
    }
}

Cell::Cell(int value)
{
    value_ = value;
    location_ = {0 , 0 , 0};
    empty_ = true; 
    for (size_t i = 1; i < 10; ++i)
    {
        possibilities_.push_back(i);
    }   
}

Cell::Cell(const Cell& cell)
{
    empty_ = cell.empty_;
    value_ = cell.value_;
    possibilities_ = cell.possibilities_;
    location_ = cell.location_;
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