#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#include <QString>



class MyLineEdit:public QLineEdit
{
    Q_OBJECT
public:
    MyLineEdit(QString =QString(), QWidget* parent=0);
public slots:
    void selezionaCognome();
    void selezionaNumero();
    void selezionaNome();
    void selezionaPesoTorta();
    void selezionaPesoDolce();
    void selezionaGusto();
    void selezionaScritta();
    void selezionaPezzi();
    void selezionaPrezzo();
signals:
    void inviaCognome(QString);
    void inviaNumero(QString);
    void inviaNome(QString);
    void inviaPesoTorta(double);
    void inviaPesoDolce(double);
    void inviaGusto(QString);
    void inviaScritta(QString);
    void inviaPezzi(int);
    void inviaPrezzo(double);
};

#endif // MYLINEEDIT_H
