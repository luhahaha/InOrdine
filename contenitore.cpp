#include "contenitore.h"



Contenitore::Contenitore():primo(0)
{
}

Contenitore::~Contenitore()
{
    delete primo;
}

void Contenitore::inserisci(Prodotto * p)
{
    primo=new Nodo(p,primo);
}




Prodotto& Contenitore::Nodo::operator*()const
{
    return *prod;
}

Contenitore::Nodo::~Nodo()
{
    delete prod;
    delete next;
}

Prodotto *Contenitore::Nodo::operator->()const
{
    return prod;
}


Contenitore::Nodo::Nodo()
{
}

Contenitore::Nodo::Nodo(Prodotto * p, Nodo *n):prod(p),next(n)
{

}

Contenitore::Nodo::Nodo(const Contenitore::Nodo & x):prod(x.prod),next(x.next)
{

}

void Contenitore::togli(int i)
{
    Nodo* togliere;
    Nodo* aux=primo;
    if(primo->prod->ID==i){
        togliere=primo;
        primo=primo->next;
    }
    else{
    while(aux->next->prod->ID!=i && aux!=0){
        aux=aux->next;
    }
    if(aux==0)
        qDebug()<<"problema";
    else{
        togliere=aux->next;
        aux->next=aux->next->next;
        delete togliere;
    }
    }
}

Prodotto *Contenitore::getProdotto(int i) const
{
    Nodo* aux=primo;
    while(aux->prod->ID!=i)
        aux=aux->next;
    return aux->prod;
}

void Contenitore::aggiorna(int i, Prodotto * x)
{

    Nodo* aux=primo;
    if(primo->prod->ID==i){
        primo->prod=x;
        primo->next=aux->next;
    }
    else{
    while(aux->next->prod->ID!=i && aux!=0){
        aux=aux->next;
    }
    if(aux==0)
        qDebug()<<"problema";
    else{
        Nodo* aux2=aux->next->next;
        aux->next->prod=x;
        aux->next->next=aux2;
    }
    }
}

Prodotto *Contenitore::operator[](Contenitore::Iteratore i) const
{
    if(i.punt!=0)
        return (i.punt->prod);
    else
        return 0;
}

Contenitore::Iteratore Contenitore::begin() const
{
    Iteratore aux;
    aux.punt=primo;
    return aux;
}

Contenitore::Iteratore Contenitore::end() const
{
    Iteratore aux;
    aux.punt=0;
    return aux;
}

bool Contenitore::isEmpty() const
{
    return this==0;
}

bool Contenitore::Iteratore::operator ==(Iteratore i) const
{
    return this->punt==i.punt;
}

bool Contenitore::Iteratore::operator !=(Contenitore::Iteratore i) const
{
    return this->punt!=i.punt;
}

Contenitore::Iteratore &Contenitore::Iteratore::operator ++()
{
    if(punt)
        punt=punt->next;
    return *this;
}
