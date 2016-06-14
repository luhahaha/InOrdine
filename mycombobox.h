#ifndef MYCOMBOBOX_H
#define MYCOMBOBOX_H

#include <QComboBox>

class MyComboBox:public QComboBox
{
    Q_OBJECT
public:
    MyComboBox(QWidget *parent =0);
public slots:
    void selezionaScritta();
signals:
    void inviaScritta(QString);
};

#endif // MYCOMBOBOX_H
