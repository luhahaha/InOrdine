#include "cliente.h"

Cliente::Cliente(QString c, QString n, QString num):cognome(c),nome(n),numero(num)
{}

Cliente::Cliente(const Cliente & x):cognome(x.cognome),nome(x.nome),numero(x.numero)
{}

QString Cliente::getcognome() const
{
    return cognome;
}

QString Cliente::getnome() const
{
    return nome;
}

QString Cliente::getnumero() const
{
    return numero;
}

void Cliente::setCognome(QString x)
{
    cognome=x;
}

void Cliente::setNome(QString x)
{
    nome=x;
}

void Cliente::setNumero(QString x)
{
    numero=x;
}
