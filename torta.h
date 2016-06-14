#ifndef TORTA_H
#define TORTA_H

#include <QString>
#include "prodotto.h"
#include "peso.h"

class Torta:public Prodotto
{
private:
    Peso p;
    QString gusto;
    bool immagine;
    QString scritta;
    static double prezzoKg;
public:
    Torta(int);
    ~Torta();
    Torta(int, Peso, QString, bool, QString);
    void setPeso(Peso);
    void setGusto(QString);
    void setImmagine(bool);
    void setScritta(QString);
    Peso getPeso() const;
    QString getGusto() const;
    QString getScritta() const;
    bool getImmagine() const;
    virtual double Preventivo()const;
    virtual bool isNull() const;
};

#endif // TORTA_H
