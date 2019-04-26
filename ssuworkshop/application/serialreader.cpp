#include "serialreader.h"

#include <iomanip>      // std::setprecision
#include <QCoreApplication>
#include <stdlib.h>     /* atof */
#include <iostream>
#include <stdio.h>

SerialReader::SerialReader(QSerialPort *serialPort, QObject *parent) :
    QObject(parent),
    m_serialPort(serialPort),
    m_standardOutput(stdout)
{
    connect(m_serialPort, &QSerialPort::readyRead, this, &SerialReader::handleReadyRead);
}



void SerialReader::handleReadyRead()
{
    m_readData.append(m_serialPort->readAll());
    double value=0.0;
    QString payload;

    if (pp.payload(&m_readData,&payload))
    {
        value= payload.toDouble();
        std::cout << "Value from Arduino: " << value << std::endl;
    }
}
