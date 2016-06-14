#ifndef CONTENITORE_H
#define CONTENITORE_H

#include "prodotto.h"
#include <QString>
#include <QDebug>

class Contenitore
{
    friend class Iteratore;
private:
    class Nodo{
    public:
        Nodo();
        Nodo(Prodotto *,Nodo *);
        Nodo(const Nodo &);
        Prodotto* prod;
        Nodo* next;
        Prodotto* operator->()const;
        Prodotto&operator*()const;
        ~Nodo();
    };

    Nodo* primo;
public:
    Contenitore();
    ~Contenitore();
    void inserisci(Prodotto *);
    void togli(int);
    Prodotto* getProdotto(int) const;
    void aggiorna(int,Prodotto*);
    class Iteratore
    {
        friend class Contenitore;
    private:
        Contenitore::Nodo* punt;
    public:
        bool operator ==(Iteratore) const;
        bool operator !=(Iteratore) const;
        Iteratore &operator ++();
    };
    Prodotto *operator[](Iteratore) const;
    Iteratore begin() const;
    Iteratore end() const;
    bool isEmpty() const;
};


#endif // CONTENITORE_H
