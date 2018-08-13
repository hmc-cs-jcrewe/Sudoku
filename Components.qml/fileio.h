#ifndef FILEIO_H
#define FILEIO_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDir>

class FileIO : public QObject
{
    Q_OBJECT
public:
    explicit FileIO(QObject * parent = 0);

public slots:

    bool write (const QStringList data, const QString& fileName);
    QList<int> read(QString fileName);


};

#endif // FILEIO_H
