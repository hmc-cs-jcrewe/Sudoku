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

    /**
     * \brief Default constructor for rows
     *
     */
    Row();

    /**
     * \brief Parameterized constructor for rows 
     *
     * \param cells     The standard list of cells to be added to the row
     *
     * \param isCol     A boolean describing if this object is being used as a row  
     *                  or a column in the board
     *
     */
    Row(list<Cell> cells, bool isCol);

    /**
     * \brief Copy constructor for rows 
     *
     * \param row      A constant reference to the row we wish to copy
     *
     */    
     Row(const Row& row);
    
    /**
     * \brief Destructor for rows 
     *
     */ 
    ~Row() = default;

    /**
     * \brief Standard comparison operator for rows  
     *
     * \param rhs     The row to which this is being compared
     *
     * \returns A boolean describing whether or not the rows are equal
     *
     */
    bool operator==(const Row& rhs);

    /**
     * \brief Standard not-comparison operator for rows  
     *
     * \param rhs     The row to which this is being compared
     *
     * \returns A boolean describing whether or not the rows are equal
     *
     */
    bool operator!=(const Row& rhs);

    /**
     * \brief  Checks if the row is complete
     *
     * \returns A boolean describing whether or not every cell 
     *           in the row contains a value
     *
     */
    bool isCompleteRow();

    /**
     * \brief Updates the possibilities for every cell in the row
     *
     */
    void getPossibilities();

    /**
     * \brief Finds the empty cell with the least number of possibilities remaining
     *
     * \returns A the cell with the minimum possibilities
     *
     */
	Cell minPossibilities();

    /**
     * \brief Sets the value of the provided cell into the row
     *
     * \param cell     The cell containing information on the value and 
     *                  location of the desired cell to set
     *
     * \returns A size_t of the value which was just set 
     *
     */
	size_t setValue(Cell cell);

};
#endif
