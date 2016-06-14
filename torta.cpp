#include "torta.h"

double Torta::prezzoKg=24.00;


Torta::Torta(int n):Prodotto(n)
{

}

Torta::~Torta()
{
}

Torta::Torta(int i, Peso x, QString g, bool im, QString s):Prodotto(i),p(x),gusto(g),immagine(im),scritta(s){}

void Torta::setPeso(Peso x)
{
    p.setPeso(x);
}

void Torta::setGusto(QString x)
{
    gusto=x;
}

void Torta::setImmagine(bool x)
{
    immagine=x;
}

void Torta::setScritta(QString x)
{
    scritta=x;
}

Peso Torta::getPeso() const
{
    return p;
}

QString Torta::getGusto() const
{
    return gusto;
}

QString Torta::getScritta() const
{
    return scritta;
}

bool Torta::getImmagine() const
{
    return immagine;
}

double Torta::Preventivo() const
{
    return p.kg*prezzoKg;
}

bool Torta::isNull() const
{
    return this==0;
}

