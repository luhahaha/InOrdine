#ifndef VIEWORDINE_H
#define VIEWORDINE_H

#include "controllerordine.h"
#include "mydatetimeedit.h"
#include "mylineedit.h"
#include "mycombobox.h"
#include "mycheckbox.h"
#include "mywidget.h"

#include <QLabel>
#include <QWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QDialogButtonBox>
#include <QTimeEdit>
#include <QLineEdit>
#include <QFileDialog>
#include <QVector>


class ControllerOrdine;

class ViewOrdine:public QDialog
{
    Q_OBJECT
private:
    QHBoxLayout* riga;
    QLabel *surnamelabel;
    QLabel *namelabel;
    QLabel *numberlabel;
    QLabel *datetimelabel;
    QLabel *estimatelabel;
    QLabel *eurolabel;
    QLabel *cashlabel;
    QLabel *title;
    QLabel *datetime;
    QLabel *name;
    QLabel *surname;
    QLabel *number;
    QLabel *product;
    QVBoxLayout *layout;
    QHBoxLayout *titlelayout;
    QHBoxLayout *surnamelayout;
    QHBoxLayout *namelayout;
    QHBoxLayout *numberlayout;
    QHBoxLayout *datetimelayout;
    QHBoxLayout *estimatelayout;
    QHBoxLayout *savelayout;
    QHBoxLayout *productlayout;
    QGridLayout *gridlayout;
    QVBoxLayout *listlayout;
    QPushButton *datetimebutt;
    QPushButton *namebutt;
    QPushButton *surnamebutt;
    QPushButton *numberbutt;
    QPushButton *productbutt;
    QPushButton *savebutt;
    MyComboBox *productcombo;
    void setTitle();
    void setDateTime();
    void setProduct();
    void setCustomer();
    void setButtons();
    void setEstimate();
    void addTorta();
    void addDolce();
    void addSalato();
    ControllerOrdine* controller;
    QDialog* dialbutton;
public:
    static int N;
    static int n;
    MyWidget* container[50];
    ViewOrdine(ControllerOrdine *p, QWidget *parent =0);
    void aggiungiRigaProdotto(Prodotto*);
    void setPreventivo(double);
    ~ViewOrdine();
public slots:
    void inserisciDataOra();
    void inserisciNome();
    void inserisciCognome();
    void inserisciNumero();
    void inserisciProdotto();
    void impostaDataOra(QDateTime);
    void impostaCognome(QString);
    void impostaNumero(QString);
    void impostaNome(QString);
    void impostaPesoTorta(double);
    void impostaPesoDolce(double);
    void impostaGusto(QString);
    void impostaScritta(QString);
    void impostaTipo(QString);
    void impostaTipoSalato(QString);
    void impostaPezzi(int);
    void impostaPrezzo(double);
    void impostaPrezzoDolce(double);
    void impostaImmagine(bool);
    void aggiornaCognome(QString);
    void aggiornaNome(QString);
    void aggiornaNumero(QString);
    void aggiornaDataora(QDateTime);
    void aggiungiTorta();
    void aggiungiDolce();
    void aggiungiSalato();
    void salvaordine();
    void eliminaRiga(int);
    void aggiornaRiga(int);
    void togliRigaProdotto(int);
};

#endif // VIEWORDINE_H
