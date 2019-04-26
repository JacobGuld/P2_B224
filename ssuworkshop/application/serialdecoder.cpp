#include "serialdecoder.h"
#include <QCoreApplication>
#include <QTextStream>
#include <iostream>

int SerialDecoder::payload(QByteArray *readData, QString *payload)
{
    bool start= false;
    int startIndex= 0; int length=0;
    for (int i=0; i< readData->size(); i++)
    {
        if ((readData->at(i)=='#') || start)
        {
            if (!start) startIndex= i;
            start= true;
            if (readData->at(i)=='!')
            {
                length= i-startIndex-1;
                for (int l=0; l< length;l++) payload->append(readData->at(startIndex+l+1));
                readData->remove(0,i);
                return length;
            }
        }
    }
    return length;

}
