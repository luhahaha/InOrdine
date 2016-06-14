#ifndef PEZZI_H
#define PEZZI_H

#include<QString>

class Pezzi
{
public:
    int numero;
    Pezzi(int =0);
    QString toString() const;
};

#endif // PEZZI_H
