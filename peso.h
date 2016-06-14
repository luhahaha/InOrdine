#ifndef PESO_H
#define PESO_H

#include<QString>

class Peso
{
public:
    double kg;
    Peso(double =0);
    Peso(const Peso &);
    void setPeso(Peso);
    QString toString() const;
};

#endif // PESO_H
