#include "mycombobox.h"

MyComboBox::MyComboBox(QWidget *parent):QComboBox(parent)
{

}

void MyComboBox::selezionaScritta()
{
    emit inviaScritta(this->currentText());
}

