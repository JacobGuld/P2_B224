#include "vejrmaster1000.h"
#include <QApplication>
#include <QCoreApplication>
#include <QSerialPort>
#include <QStringList>
#include <QTextStream>
#include <serialreader.h>


int main(int argc, char *argv[])
{
    QSerialPort serialPort;
    const QString SerialPortName = "COM10";
    serialPort.setPortName(SerialPortName);
    serialPort.setBaudRate(9600);
    SerialReader serialPortReader(&serialPort);


    QApplication a(argc, argv);
    VejrMaster1000 w;
    w.show();

    return a.exec();
}
