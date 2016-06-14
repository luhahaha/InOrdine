#ifndef ORDINE_H
#define ORDINE_H

#include "contenitore.h"
#include "cliente.h"
#include <QDateTime>

class Ordine
{
private:
    Contenitore ordini;
    QDateTime data;
    Cliente cli;
public:
    Ordine(Contenitore =Contenitore(),QDateTime = QDateTime(),Cliente = Cliente());
    void inserisciOrdine(Prodotto*);
    QDateTime getData() const;
    Cliente getCliente()const;
    void setData(QDate);
    void setTime(QTime);
    void setDateTime(QDateTime);
    void setCognome(QString);
    void setNome(QString);
    void setNumero(QString);
    void eliminaOrdine(int);
    void aggiornaOrdine(int,Prodotto*);
    Prodotto *getOrdine(int) const;
    const Contenitore& getOrdini()const;
};

#endif // ORDINE_H
