#include "mycheckbox.h"

MyCheckBox::MyCheckBox(QWidget *parent):QCheckBox(parent)
{

}

MyCheckBox::MyCheckBox(QString x, QWidget *parent):QCheckBox(x,parent)
{

}

void MyCheckBox::selezionaImmagine()
{
    emit inviaImmagine(isChecked());
}



