#ifndef MYDATETIMEEDIT_H
#define MYDATETIMEEDIT_H

#include <QDateTimeEdit>



class MyDateTimeEdit:public QDateTimeEdit
{
    Q_OBJECT
public:
    MyDateTimeEdit(QWidget *parent =0);
public slots:
    void selezionaDataOra();
signals:
    void inviaDataOra(QDateTime);
};

#endif // MYDATETIMEEDIT_H
