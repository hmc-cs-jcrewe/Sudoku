#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "solver.h"
#include "../Components.qml/fileio.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<Solver>("solver.io",1,0,"SolverItem");
    qmlRegisterType<FileIO>("file.io",1,0,"FileController");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
