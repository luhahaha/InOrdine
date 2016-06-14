#include "mydatetimeedit.h"

MyDateTimeEdit::MyDateTimeEdit(QWidget *parent):QDateTimeEdit(parent)
{
}

void MyDateTimeEdit::selezionaDataOra()
{
    emit inviaDataOra(dateTime());
}


