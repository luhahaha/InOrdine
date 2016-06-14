#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class MyWidget:public QWidget
{
    Q_OBJECT
public:
    MyWidget(int,QWidget *parent =0);
    int ID;
public slots:
    void eliminaRiga();
    void aggiornaRiga();
signals:
    void inviaIDDel(int);
    void inviaIDMod(int);
};

#endif // MYWIDGET_H
