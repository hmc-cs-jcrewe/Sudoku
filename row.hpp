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
#include <iostream>

#include "cell.hpp"
using namespace std;
class Row
{
    
public:
    // data members 
   
	Cell cells_[9];
    // number of cells in the row that contain a value
    size_t rowSize_;

    // is the row a column 
     bool isCol_;

    //default constructor
    Row();

    //paramaterized constructors
    Row(list<Cell> cells, bool isCol);

    //copy constructor 
    Row(const Row& row);
    
    //destructor 
    ~Row() = default;

    //operators 
    bool operator==(const Row& rhs);
    bool operator!=(const Row& rhs);

    //member functions 
    bool isCompleteRow();
    void getPossibilities();
	Cell minPossibilities();
	size_t setValue(Cell cell);

	//TODO -- should this have a location data member?
};
#endif
