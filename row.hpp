/**
 * \class Row
 * \brief Stores 9 cells for each of the rows in the Sudoku Board 
 *
 *
 */

#ifndef ROW_H
#define ROW_H
 //includes go here
#include <cstddef>
#include <list>

#include "cell.hpp"
using namespace std;
class Row
{
    
public:
    //data members 
    Cell row_[9];
    //number of cells in the row that contain a value
    size_t rowSize_ = 0;

    //default constructor
    Row();

    //paramaterized constructor
    Row(size_t size, list<Cell> cells);

    //copy constructor 
    Row(const Row&);
    
    //destructor 
    ~Row() = default;

    //member functions 
    bool completeRow();
    void getPossibilities();

};
#endif
