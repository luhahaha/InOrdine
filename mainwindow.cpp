#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QWidget*wdg=new QWidget;
    setTitle();
    createButtons();
    mainlayout=new QVBoxLayout(wdg);
    mainlayout->addWidget(title);
    mainlayout->addLayout(layoutButtons);
    wdg->setLayout(mainlayout);
    setCentralWidget(wdg);
}

MainWindow::~MainWindow()
{}

void MainWindow::createButtons()
{
    newOrdine = new QPushButton("Nuovo Ordine",this);
    loadOrdine = new QPushButton("Carica Ordine",this);
    layoutButtons = new QVBoxLayout();
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
    QString nomefile=QFileDialog::getOpenFileName(this,tr("Salva ordine"),QDir::currentPath(),tr("XML (*.xml);; Tutti i files (*.*)"));
    if(!nomefile.isEmpty()){
        controller=new ControllerOrdine(this);
        controller->caricaOrdine(nomefile);
    }
}



void MainWindow::setTitle()
{
    title=new QLabel("In Ordine",this);
    title->setFont(QFont("courier",25,QFont::Bold));
    title->setAlignment(Qt::AlignCenter);
}
