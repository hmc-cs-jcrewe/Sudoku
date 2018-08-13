#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include "../../../../../site/home/jcrewe/Sudoku-master/solver.h"
#include "fileio.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);    
    QGuiApplication app(argc, argv);
  //  qmlRegisterType<SudokuBoard>("board",1,0,"BoardItem");
  //  qmlRegisterType<Cell>("cell",1,0,"CellItem");
    QQmlApplicationEngine engine;
    qmlRegisterType<Solver>("solver.io",1,0,"SolverItem");
    qmlRegisterType<FileIO>("file.io",1,0,"FileController");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


    return app.exec();

}
