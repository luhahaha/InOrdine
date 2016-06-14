#ifndef DOLCE_H
#define DOLCE_H

#include <QVector>
#include <QString>
#include "prodotto.h"
#include "peso.h"

class Dolce:public Prodotto
{
private:
    Peso p;
    QString tipo;
    double prezzo;
public:
    Dolce(int,Peso =0,QString ="", double =0);
    ~Dolce();
    virtual double Preventivo()const;
    virtual bool isNull() const;
    void setPeso(Peso);
    void setTipo(QString);
    void setPrezzo(double);
    Peso getPeso() const;
    QString getTipo() const;
    double getPrezzo() const;
};


#endif // DOLCE_H
