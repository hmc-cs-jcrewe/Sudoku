

//includes go here
#include <stdexcept>
#include <list>
#include <iostream>
#include <string>
#include <stack>
#include<vector>


#include "solver.h"
//board needs to have 17 prefilled spaces for a single solution to exist
Solver::Solver(QObject *parent): QObject(parent) {

}

SudokuBoard Solver::makeEmptyBoard()
{
    //build the board
    Cell cells[81];

    //Create 81 empty cells that all contain a location
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

    SudokuBoard empty = SudokuBoard(cells);
    empty.updatePossibilities();
    return empty;
}

SudokuBoard Solver::addBoardValues(QStringList values, SudokuBoard emptyBoard)
{
    Cell cells[81];
    //Process values -- acrobatics required to deal with JavaScripts inablity to handle types


   // vector<int> intsFiller;

    vector<vector<int>> intFiller2;

    for (int i = 0; i < values.length(); ++i) {
        vector<int> tmp;
        for (int j = 0; j < values[i].length() + 1; ++j)
        {
            if(values[i][j] == " "){
                tmp.push_back(0);
            }
            else if(values[i][j] != ","){
                tmp.push_back(values[i][j].digitValue());
            }
            else if(values[i][j] == "," && values[i][j+1] == ","){
                tmp.push_back(0);
            }
        }
        intFiller2.push_back(tmp);
    }


    int ints[81];
    int i = 0;


    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            ints[9*i + j] = intFiller2[i][j];
        }
}



    cells[0] = Cell(ints[0],0 ,0,1);
    cells[1] = Cell(ints[1],0,1,1);
    cells[2] = Cell(ints[2],0,2,1);
    cells[3] = Cell(ints[9],0,3,2);
    cells[4] = Cell(ints[10],0,4,2);
    cells[5] = Cell(ints[11],0,5,2);
    cells[6] = Cell(ints[18],0,6,3);
    cells[7] = Cell(ints[19],0,7,3);
    cells[8] = Cell(ints[20],0,8,3);
    cells[9] = Cell(ints[3],1,0,1);
    cells[10] = Cell(ints[4],1,1,1);
    cells[11] = Cell(ints[5],1,2,1);
    cells[12] = Cell(ints[12],1,3,2);
    cells[13] = Cell(ints[13],1,4,2);
    cells[14] = Cell(ints[14],1,5,2);
    cells[15] = Cell(ints[21],1,6,3);
    cells[16] = Cell(ints[22],1,7,3);
    cells[17] = Cell(ints[23],1,8,3);
    cells[18] = Cell(ints[6],2,0,1);
    cells[19] = Cell(ints[7],2,1,1);
    cells[20] = Cell(ints[8],2,2,1);
    cells[21] = Cell(ints[15],2,3,2);
    cells[22] = Cell(ints[16],2,4,2);
    cells[23] = Cell(ints[17],2,5,2);
    cells[24] = Cell(ints[24],2,6,3);
    cells[25] = Cell(ints[25],2,7,3);
    cells[26] = Cell(ints[26],2,8,3);

    cells[27] = Cell(ints[27],3,0,4);
    cells[28] = Cell(ints[28],3,1,4);
    cells[29] = Cell(ints[29],3,2,4);
    cells[30] = Cell(ints[36],3,3,5);
    cells[31] = Cell(ints[37],3,4,5);
    cells[32] = Cell(ints[38],3,5,5);
    cells[33] = Cell(ints[45],3,6,6);
    cells[34] = Cell(ints[46],3,7,6);
    cells[35] = Cell(ints[47],3,8,6);
    cells[36] = Cell(ints[30],4,0,4);
    cells[37] = Cell(ints[31],4,1,4);
    cells[38] = Cell(ints[32],4,2,4);
    cells[39] = Cell(ints[39],4,3,5);
    cells[40] = Cell(ints[40],4,4,5);
    cells[41] = Cell(ints[41],4,5,5);
    cells[42] = Cell(ints[48],4,6,6);
    cells[43] = Cell(ints[49],4,7,6);
    cells[44] = Cell(ints[50],4,8,6);
    cells[45] = Cell(ints[33],5,0,4);
    cells[46] = Cell(ints[34],5,1,4);
    cells[47] = Cell(ints[35],5,2,4);
    cells[48] = Cell(ints[42],5,3,5);
    cells[49] = Cell(ints[43],5,4,5);
    cells[50] = Cell(ints[44],5,5,5);
    cells[51] = Cell(ints[51],5,6,6);
    cells[52] = Cell(ints[52],5,7,6);
    cells[53] = Cell(ints[53],5,8,6);


    cells[54] = Cell(ints[54],6,0,7);
    cells[55] = Cell(ints[55],6,1,7);
    cells[56] = Cell(ints[56],6,2,7);
    cells[57] = Cell(ints[63],6,3,8);
    cells[58] = Cell(ints[64],6,4,8);
    cells[59] = Cell(ints[65],6,5,8);
    cells[60] = Cell(ints[72],6,6,9);
    cells[61] = Cell(ints[73],6,7,9);
    cells[62] = Cell(ints[74],6,8,9);
    cells[63] = Cell(ints[57],7,0,7);
    cells[64] = Cell(ints[58],7,1,7);
    cells[65] = Cell(ints[59],7,2,7);
    cells[66] = Cell(ints[66],7,3,8);
    cells[67] = Cell(ints[67],7,4,8);
    cells[68] = Cell(ints[68],7,5,8);
    cells[69] = Cell(ints[75],7,6,9);
    cells[70] = Cell(ints[76],7,7,9);
    cells[71] = Cell(ints[77],7,8,9);
    cells[72] = Cell(ints[60],8,0,7);
    cells[73] = Cell(ints[61],8,1,7);
    cells[74] = Cell(ints[62],8,2,7);
    cells[75] = Cell(ints[69],8,3,8);
    cells[76] = Cell(ints[70],8,4,8);
    cells[77] = Cell(ints[71],8,5,8);
    cells[78] = Cell(ints[78],8,6,9);
    cells[79] = Cell(ints[79],8,7,9);
    cells[80] = Cell(ints[80],8,8,9);

    for (int i = 0; i < 81; ++i){
        emptyBoard.setValue(cells[i]);
    }
    emptyBoard.updatePossibilities();
    return emptyBoard;

}
SudokuBoard Solver::solve(SudokuBoard board)
{
    std::stack<SudokuBoard> boardStack;

    boardStack.push(board);
    Cell minCell = Cell();
    while (!boardStack.empty())
    {
        SudokuBoard topBoard = boardStack.top();    //access top element 
        boardStack.pop(); //remove the element we are currently using 
        
        if (topBoard.isComplete())
        {
            return topBoard;
        }
        else 
        {
            // Find the cell with the least number of possibilities remaining, called minCell
            for (size_t i = 0; i < 9; ++i)
            {  
                Cell newCell = topBoard.rows_[i].minPossibilities();   //minPossibilities is not working correctly
                if (newCell.possibilities_.size() < minCell.possibilities_.size())
                {
                    minCell = newCell;
                }
            }   

            // Create a new board for each of the possibilities in the minCell and add them to the stack
            for (auto i = minCell.possibilities_.begin() ; i != minCell.possibilities_.end(); ++i)
            {
                SudokuBoard newBoard = SudokuBoard(topBoard);
                Cell addCell = Cell (*i , minCell.location_[0] , minCell.location_[1] , minCell.location_[2]);
                newBoard.setValue(addCell);
                newBoard.updatePossibilities();
                boardStack.push(newBoard);
            }   

            minCell = Cell();   //reset minCell    
        }
    }

    std::cout << "The program couldn't find a solution to the provided board, are you sure the entered board has a valid solution?" << std::endl;
    SudokuBoard failBoard = SudokuBoard();  // if the board reaches the end of the stack without 
    Cell failCell  = Cell(100, 0  , 0 , 1); // finding a solution return a faulty board 
    failBoard.setValue(failCell);
    return failBoard;
}

QList<int> Solver::getSolution(SudokuBoard solvedBoard) {
    if (solvedBoard.isComplete()){
        QList<int> solutionInts;
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                solutionInts.append(solvedBoard.squares_[i].cells_[j].value_);
               }
        }
        return solutionInts;
    }
        else {
            QList<int> emptyList;
            return emptyList;
        }
}

QList<int> Solver::solutionWrapper(QStringList values){
    SudokuBoard emptyBoard = this->makeEmptyBoard();
    SudokuBoard preliminaryBoard = this->addBoardValues(values, emptyBoard);
    SudokuBoard solvedBoard = this->solve(preliminaryBoard);
    return this->getSolution(solvedBoard);
}

//To run in terminal, within the Sudoku directory type: make solution

/*
int main()
{

    //build the board
    Cell cells[81];
	
    //Create 81 empty cells that all contain a location
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

	SudokuBoard empty = SudokuBoard(cells);
    empty.updatePossibilities();

    // Create the cells you want to start with here 
	Cell cells20 = Cell (2, 0 , 0 , 1);
	Cell cells29 = Cell(1 , 0 , 3 , 2);
	Cell cells218 = Cell(7 , 0 , 6 , 3);
	Cell cells227 = Cell(9 , 1 , 1 , 1);
	Cell cells236 = Cell(6 , 1 , 4 , 2);
	Cell cells245 = Cell(3 , 2 , 2 , 1);
	Cell cells254 = Cell(8 , 2 , 8 , 3);
	Cell cells263 = Cell(7 , 3 , 0 , 4);
	Cell cells272 = Cell(9 , 3 , 4 , 5);
    Cell cells1 = Cell(6 , 3 , 6 , 6);
    Cell cells2 = Cell(4 , 4 , 2 , 4);
    Cell cells3 = Cell(8 , 4 , 5 , 5);
    Cell cells4 = Cell(1 , 4 , 8 , 6);
    Cell cells5 = Cell(5 , 5 , 1 , 4);
    Cell cells6 = Cell (2 , 5 , 3 , 5);
    Cell cells7 = Cell (3 , 5 , 7 , 6);
    Cell cells8 = Cell (6 , 6 , 0 , 7);
    Cell cells9 = Cell (3 , 6 , 3, 8);
    Cell cells10 = Cell (4 , 6 , 7 , 9);
    Cell cells11 = Cell (8 , 7 , 1 , 7);
    Cell cells12 = Cell (1 , 8 , 2 , 7);
    Cell cells13 = Cell (5 , 8 , 4 , 8);
    Cell cells14 = Cell (2, 8 , 6 , 9);

    // Add your starter cells to the board here
    empty.setValue(cells20);
	empty.setValue(cells29);
	empty.setValue(cells218);
	empty.setValue(cells227);
	empty.setValue(cells236);
	empty.setValue(cells245);
	empty.setValue(cells254);
	empty.setValue(cells263);
	empty.setValue(cells272);
    empty.setValue(cells1);
    empty.setValue(cells2);
    empty.setValue(cells3);
    empty.setValue(cells4);
    empty.setValue(cells5);
    empty.setValue(cells6);
    empty.setValue(cells7);
    empty.setValue(cells8);
    empty.setValue(cells9);
    empty.setValue(cells10);
    empty.setValue(cells11);
    empty.setValue(cells12);
    empty.setValue(cells13);
    empty.setValue(cells14);
    
    empty.updatePossibilities();

    std::cout << "Original Board: " << std::endl;
    empty.print(std::cout);
    std::cout << std::endl;

    SudokuBoard solvedBoard = solve(empty);

    if (solvedBoard.rows_[0].cells_[0].getValue() != 100)   //if the solver succeeded
    {
        std::cout << "Solved Board: " << std::endl;
        solvedBoard.print(std::cout);
    }

}
*/
