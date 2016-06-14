#ifndef MYCHECKBOX_H
#define MYCHECKBOX_H

#include <QCheckBox>


class MyCheckBox:public QCheckBox
{
    Q_OBJECT
public:
    MyCheckBox(QWidget *parent =0);
    MyCheckBox(QString x,QWidget *parent =0);
public slots:
    void selezionaImmagine();
signals:
    void inviaImmagine(bool);
};

#endif // MYCHECKBOX_H
