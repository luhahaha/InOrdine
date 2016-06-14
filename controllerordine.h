#ifndef CONTROLLERORDINE_H
#define CONTROLLERORDINE_H

#include "ordine.h"
#include "viewordine.h"
#include <QFile>
#include <QWidget>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QDebug>
#include "torta.h"
#include "dolce.h"
#include "salato.h"
#include "mycheckbox.h"
#include "mycombobox.h"
#include "mylineedit.h"
#include "mywidget.h"


class ViewOrdine;

class ControllerOrdine
{
public:
    Torta* torta;
    Dolce* dolce;
    Salato* salato;
    ControllerOrdine(QWidget *);
    void setDataOra(QDateTime);
    void setCognome(QString);
    void setNumero(QString);
    void setNome(QString);
    void saveOrdine(QString);
    void caricaOrdine(QString);
    void aggiungiProdotto(QString x);
    void creaTorta(int);
    void creaDolce(int);
    void creaSalato(int);
    void eliminaProdotto(int);
    void modificaProdotto(int);
    double getPreventivo();
    QString getNome() const;
    QString getCognome() const;
    QString getNumero() const;
    QDate getData() const;
    QTime getOra() const;
    ~ControllerOrdine();
private:
    Ordine *model;
    ViewOrdine *view;
public slots:
    void aggiornaProdotto();
};

#endif // CONTROLLERORDINE_H
