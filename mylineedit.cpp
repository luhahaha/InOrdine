#include "mylineedit.h"

MyLineEdit::MyLineEdit(QString x,QWidget *parent):QLineEdit(x,parent)
{

}

MyLineEdit::MyLineEdit(QWidget *parent):QLineEdit(parent)
{

}

void MyLineEdit::selezionaCognome()
{
    emit inviaCognome(text());
}

void MyLineEdit::selezionaNumero()
{
    emit inviaNumero(text());
}

void MyLineEdit::selezionaNome()
{
    emit inviaNome(text());
}

void MyLineEdit::selezionaPesoTorta()
{
    emit inviaPesoTorta(text().toDouble());
}
void MyLineEdit::selezionaPesoDolce()
{
    emit inviaPesoDolce(text().toDouble());
}

void MyLineEdit::selezionaGusto()
{
    emit inviaGusto(text());
}

void MyLineEdit::selezionaScritta()
{
    emit inviaScritta(text());
}

void MyLineEdit::selezionaPezzi()
{
    emit inviaPezzi(text().toInt());
}

void MyLineEdit::selezionaPrezzo()
{
    emit inviaPrezzo(text().toDouble());
}

