#include "fileio.h"

FileIO::FileIO(QObject *parent) : QObject(parent)
{
}

bool FileIO::write (const QStringList data, const QString& fileName)
{
        QFile output(QDir::currentPath().append("/savedBoards/").append(fileName));

        if (output.open(QIODevice::ReadWrite)){
            QTextStream out(&output);
            for (int i = 0; i < data.length(); ++i){
                out << data[i];
                out << "\n";
            }

            return true;
        }
       // std::cout << "We couldn't write the file";
        return false;
}
QList<int> FileIO::read(QString fileName){
    fileName.remove(0,7);
    QFile output(fileName);

    if(!output.exists()){
       // std::cout<< "Please choose a file that exists";
        return QList<int>();
    }

    if (output.open(QIODevice::ReadWrite)){
        QList<int> outputList;
        QTextStream in(&output);
        QString line = in.readAll();
        QStringList lines = line.split("\n");
        for (int i = 0; i < lines.length(); ++i){
            for (int j = 0; j < lines[i].length(); ++j){
                if (lines[i][j] == " "){
                    outputList.append(0);
                } else {
                    outputList.append(lines[i][j].digitValue());
                }
            }
        }

        return outputList;

    }


    return QList<int>();
}


