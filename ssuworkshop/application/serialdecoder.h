#ifndef SERIALDECODER_H
#define SERIALDECODER_H


#include <QByteArray>
#include <QTextStream>

class SerialDecoder
{
public:
    int payload(QByteArray *readData, QString *payload);
};

#endif // SERIALDECODER_H
