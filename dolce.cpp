#include "dolce.h"


Dolce::Dolce(int i, Peso q, QString t, double p):Prodotto(i),p(q),tipo(t),prezzo(p)
{
}

Dolce::~Dolce()
{
}

double Dolce::Preventivo() const
{
    return p.kg*prezzo;
}

bool Dolce::isNull() const
{
    return this==0;
}

void Dolce::setPeso(Peso x)
{
    p=x;
}

void Dolce::setTipo(QString x)
{
    tipo=x;
}

void Dolce::setPrezzo(double x)
{
    prezzo=x;
}

Peso Dolce::getPeso() const
{
    return p;
}

QString Dolce::getTipo() const
{
    return tipo;
}

double Dolce::getPrezzo() const
{
    return prezzo;
}
