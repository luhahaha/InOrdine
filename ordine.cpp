#include "ordine.h"


Ordine::Ordine(Contenitore cont,QDateTime d, Cliente c):ordini(cont),data(d),cli(c)
{}

Ordine::~Ordine()
{
}

void Ordine::inserisciOrdine(Prodotto * p)
{
    ordini.inserisci(p);
}

QDateTime Ordine::getData() const
{
    return data;
}

Cliente Ordine::getCliente() const
{
    return cli;
}


void Ordine::setData(QDate x)
{
    data.setDate(x);
}

void Ordine::setTime(QTime x)
{
    data.setTime(x);
}

void Ordine::setDateTime(QDateTime x)
{
    data=QDateTime(x);
}

void Ordine::setCognome(QString x)
{
    cli.setCognome(x);

}

void Ordine::setNome(QString x)
{
    cli.setNome(x);
}

void Ordine::setNumero(QString x)
{
    cli.setNumero(x);
}

void Ordine::eliminaOrdine(int n)
{
    ordini.togli(n);
}

void Ordine::aggiornaOrdine(int i, Prodotto * x)
{
    ordini.aggiorna(i,x);
}

Prodotto* Ordine::getOrdine(int n) const
{
    return ordini.getProdotto(n);
}

const Contenitore& Ordine::getOrdini() const
{
    return ordini;
}
