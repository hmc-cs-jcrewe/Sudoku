/*
* \file sudoku-test.cpp
*
* \brief Tests a SudokuBoard and all related classes for correctness
*/

#include "testing-logger.hpp"
#include "Board.hpp"

#include <string>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include<cassert>
#include "signal.h"


//helper functions -- if necessary

//testing functions 

bool exampleTest()
{
	throw new exception();
}
//Cell Tests


bool cellDefaultConstuctorTest()
{
	throw new exception();
}

bool cellValueConstructorTest()
{
	throw new exception();
}

bool cellLocationConstructorTest()
{
	throw new exception();
}

bool cellCopyConstructorTest()
{
	throw new exception();
}

bool cellIsEmptyTest()
{
	throw new exception();
}

bool cellGetValueTest()
{
	throw new exception();
}

bool cellNumPossibilitiesTest()
{
	throw new exception();
}

//Row tests
bool rowDefaulConstructorTest()
{
	throw new exception();
}

bool rowListConstructorTest()
{
	throw new exception();
}

bool rowCopyConstructorTest()
{
	throw new exception();
}

bool rowIsCompleteTest()
{
	throw new exception();
}

bool rowGetPossibilitiesTest()
{
	throw new exception();
}

//Square tests
bool squareDefaultConstructorTest()
{
	throw new exception();
}

bool squareListConstructorTest()
{
	throw new exception();
}

bool squareCopyConstructorTest()
{
	throw new exception();
}

bool squareIsCompleteTest()
{
	throw new exception();
}

bool squareGetPossibilitiesTest()
{
	throw new exception();
}

//BoardTests
bool boardDefaultConstructorTest()
{
	throw new exception();
}

bool boardCellConstructorTest()
{
	throw new exception();
}

bool boardCopyConstructorTest()
{
	throw new exception();
}

bool boardGetRowTest()
{
	throw new exception();
}

bool boardGetColumnTest()
{
	throw new exception();
}

bool boardGetSquareTest()
{
	throw new exception();
}

bool boardMakeRowTest()
{
	throw new exception();
}

bool boardMakeSquareTest()
{
	throw new exception();
}

bool boardIsCompleteTest()
{
	throw new exception();
}

bool boardInValidSolutionTest()
{
	throw new exception();
}

bool boardUpdatePossibilitiesTest()
{
	throw new exception();
}



// --------------------------
//		Running the tests
// --------------------------

// Called if the tests run too long
// taken from 

int main(int argc, char** argv)
{
	//Initialize testing environment 

	TestingLogger alltests{ "All tests" };

	// Add all calls to tests here 
	affirm(exampleTest());   
	affirm(cellDefaultConstuctorTest());
	affirm(cellValueConstructorTest());
	affirm(cellLocationConstructorTest());
	affirm(cellCopyConstructorTest());
	affirm(cellIsEmptyTest());
	affirm(cellGetValueTest());
	affirm(cellNumPossibilitiesTest());
	affirm(rowDefaulConstructorTest());
	affirm(rowListConstructorTest());
	affirm(rowCopyConstructorTest());
	affirm(rowIsCompleteTest());
	affirm(rowGetPossibilitiesTest());
	affirm(squareDefaultConstructorTest());
	affirm(squareListConstructorTest());
	affirm(squareCopyConstructorTest());
	affirm(squareIsCompleteTest());
	affirm(squareGetPossibilitiesTest());
	affirm(boardDefaultConstructorTest());
	affirm(boardCellConstructorTest());
	affirm(boardCopyConstructorTest());
	affirm(boardGetRowTest());
	affirm(boardGetColumnTest());
	affirm(boardGetSquareTest());
	affirm(boardMakeRowTest());
	affirm(boardMakeSquareTest());
	affirm(boardIsCompleteTest());
	affirm(boardInValidSolutionTest());
	affirm(boardUpdatePossibilitiesTest());

	if (alltests.summarize(true))
	{
		return 0;	//exit code 0 = success
	}
	else
	{
		return 2;	// arbitratily chosen 
					// exit code of 2 means failure 
	}
}