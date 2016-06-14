#include "mywidget.h"

MyWidget::MyWidget(int i,QWidget *parent):ID(i),QWidget(parent)
{

}

void MyWidget::eliminaRiga()
{
    emit inviaIDDel(ID);
}

void MyWidget::aggiornaRiga()
{
    emit inviaIDMod(ID);
}

