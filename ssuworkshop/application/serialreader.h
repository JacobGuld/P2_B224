#ifndef SERIALREADER_H
#define SERIALREADER_H

#include <QByteArray>
#include <QSerialPort>
#include <QtSerialPort/QSerialPort>

#include <QTextStream>
#include <QTimer>
#include <serialdecoder.h>

class SerialReader : public QObject
{
   Q_OBJECT

public:
    explicit SerialReader(QSerialPort *serialPort, QObject *parent = (QObject *)0);

private slots:
    void handleReadyRead();

private:
    QSerialPort *m_serialPort = (QSerialPort *)0;
    QByteArray m_readData;
    QTextStream m_standardOutput;
    SerialDecoder pp;

};




#endif // SERIALREADER_H
