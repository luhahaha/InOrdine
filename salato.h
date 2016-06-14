#ifndef SALATO_H
#define SALATO_H

#include "prodotto.h"
#include "pezzi.h"
#include <QString>


class Salato:public Prodotto
{
private:
    QString tipo;
    Pezzi p;
    double prezzoPezzo;
public:
    Salato(int, QString ="", Pezzi =0, double=0);
    ~Salato();
    void setTipo(QString);
    void setPezzi(Pezzi);
    void setPrezzo(double);
    QString getTipo() const;
    Pezzi getPezzi() const;
    double getPrezzo() const;
    virtual double Preventivo()const;
    virtual bool isNull()const;
};


#endif // SALATO_H
