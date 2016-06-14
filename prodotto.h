#ifndef PRODOTTO_H
#define PRODOTTO_H


class Prodotto
{
public:
    int ID;
    Prodotto(int);
    virtual ~Prodotto();
    virtual double Preventivo()const =0;//metodo virtuale puro
    virtual bool isNull()const =0;
};

#endif // PRODOTTO_H
