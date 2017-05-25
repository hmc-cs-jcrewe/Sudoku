/**
 * \file SudokuBoard.hpp
 *
 * \authors Jackson Crewe
 *
 * \brief Declares the SudokuBoard class.
 */

//Anything to include goes here
#include <cstddef>

/**
 * \class SudokuBoard
 * \brief A 2D array of all the cells in the sudoku board
 *
 * \details
 *  Stores an array of characters that will be displayed to the screen, and
 * a Sprite that will be added to the screen.
 *
 */
class SudokuBoard {
private: 
    //forward definition of a cell
    class Cell;

    //forward definition of a row
    class Row;

    //forward definition of a square 
    class Square;

public:
   // default constructor 
   SudokuBoard();

   //paramaterized constructor
   SudokuBoard(Cell[] cells);

   //copy constructor
   SudokuBoard(const SudokuBoard&) = delete;

   //destructor
   ~SudokuBoard();

   //getters
   Row getRow(size_t r);
   Row getCol(size_t c);

   //setters
   Row makeRow(size_t [] values);
   Row makeCol(size_t [] values);
   Square makeSquare(size_t [] values);


private:
Row rows_[9];
Row columns_[9];
Square squares_[3][3];

/**
 * \class Cell
 * \brief Stores data for each individual cell in our Sudoku Board
 *
 * \details
 *  Stores the default value of the cell, the possibilities of values 
 *  the cell could contain, and the location of the cell within the board
 *
 */
    class Cell {
        
        //data members 
        size_t value_;
        size_t possibilities_ [9];
        size_t location_[3];

        //default constructor 
        Cell();

        //paramaterized constructor
        Cell(int value, int row, int col, int squareNum);

        //copy constructor 
        Cell(const Cell&) = delete;

        //destructor
        ~Cell();

        //member functions
        bool isEmpty();
        size_t getValue();
        size_t getLocation();
        size_t numPossibilities();

    };


/**
 * \class Row
 * \brief Stores 9 cells for each of the rows in the Sudoku Board 
 *
 *
 */

    class Row{
        //data members 
        Cell row_[9];
        //number of cells in the row that contain a value
        size_t rowSize_;

        //default constructor
        Row();

        //paramaterized constructor
        Row(size_t size, Cell[] cells);

        //copy constructor 
        Row(const Row&) = delete;
        
        //destructor 
        ~Row();

    };

/**
 * \class Square
 * \brief Stores 9 cells for each of the small squares in the Sudoku Board 
 *
 *
 */

    class Square{
    //data members
    Cell square_[3][3];
    //number of cells in the square that contain a value
    size_t squareSize_;

    //default constructor
    Square();

    //paramaterized constructor 
    Square(size_t size, Cell[] cells);


    };
};