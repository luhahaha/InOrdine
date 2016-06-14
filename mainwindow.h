#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include "contenitore.h"
#include "controllerordine.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QLabel* title;
    QPushButton *newOrdine;
    QPushButton *loadOrdine;
    QVBoxLayout* mainlayout;
    QVBoxLayout *layoutButtons;
    void setTitle();
    void createButtons();
    ControllerOrdine *controller;
private slots:
    void newordine();
    void loadordine();
};

#endif // MAINWINDOW_H
