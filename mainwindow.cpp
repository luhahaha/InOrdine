#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QWidget*wdg=new QWidget;
    setTitle();
    createButtons();
    QVBoxLayout* mainlayout=new QVBoxLayout;
    mainlayout->addWidget(title);
    mainlayout->addLayout(layoutButtons);
    wdg->setLayout(mainlayout);
    setCentralWidget(wdg);
}

MainWindow::~MainWindow()
{}

void MainWindow::createButtons()
{
    newOrdine = new QPushButton("Nuovo Ordine");
    loadOrdine = new QPushButton("Carica Ordine");
    layoutButtons = new QVBoxLayout;
    layoutButtons->addWidget(newOrdine);
    layoutButtons->addWidget(loadOrdine);
    connect(newOrdine,SIGNAL(clicked(bool)),this,SLOT(newordine()));
    connect(loadOrdine,SIGNAL(clicked(bool)),SLOT(loadordine()));
}

void MainWindow::newordine()
{
    controller=new ControllerOrdine(this);
}

void MainWindow::loadordine()
{
    QString nomefile=QFileDialog::getOpenFileName(this,tr("Salva ordine"),QDir::currentPath(),tr("Ordine (*.xml)"));
    if(!nomefile.isEmpty()){
        controller=new ControllerOrdine(this);
        controller->caricaOrdine(nomefile);
    }
}



void MainWindow::setTitle()
{
    title=new QLabel("In Ordine");
    title->setFont(QFont("courier",25,QFont::Bold));
    title->setAlignment(Qt::AlignCenter);
}
