#ifndef SOLVER_H
#define SOLVER_H
using namespace std;
#include "../Board.hpp"
#include<QObject>
#include<vector>
#include <QList>
class Solver : public QObject
{

        Q_OBJECT
public:
    explicit Solver(QObject *parent = 0);
    ~Solver() = default;


public slots:
    QList<int> solutionWrapper(QStringList values);


private:
    SudokuBoard solve(SudokuBoard board);
    SudokuBoard makeEmptyBoard();
    SudokuBoard addBoardValues(QStringList values, SudokuBoard emptyBoard);
    QList<int> getSolution(SudokuBoard solvedBoard);

};
#endif // SOLVER_H
