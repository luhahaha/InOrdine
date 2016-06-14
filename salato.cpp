#include "salato.h"

void Salato::setTipo(QString x)
{
    tipo=x;
}

void Salato::setPezzi(Pezzi x)
{
    p=x;
}

void Salato::setPrezzo(double x)
{
    prezzoPezzo=x;
}

QString Salato::getTipo() const
{
    return tipo;
}

Pezzi Salato::getPezzi() const
{
    return p;
}

double Salato::getPrezzo() const
{
    return prezzoPezzo;
}

Salato::Salato(int i,QString t, Pezzi x, double p):Prodotto(i),tipo(t),p(x),prezzoPezzo(p){}

Salato::~Salato()
{
}

double Salato::Preventivo()const{
    return p.numero*prezzoPezzo;
}

bool Salato::isNull() const
{
    return this==0;
}
