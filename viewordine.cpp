#include "viewordine.h"

int ViewOrdine::N=10;
int ViewOrdine::n=0;

//costruttore della view
ViewOrdine::ViewOrdine(ControllerOrdine * p, QWidget *parent):QDialog(parent),controller(p)
{
    layout=new QVBoxLayout;
    gridlayout=new QGridLayout;
    setTitle();
    setDateTime();
    setProduct();
    setCustomer();
    setEstimate();
    setButtons();
    layout->addLayout(titlelayout);
    layout->addLayout(datetimelayout);
    layout->addLayout(productlayout);
    layout->addLayout(listlayout);
    layout->addLayout(gridlayout);
    layout->addLayout(estimatelayout);
    layout->addLayout(savelayout);
    setLayout(layout);
    this->setModal(true);
    this->show();
}

//metodo per aggiungere alla view una nuova riga contenente un prodotto
void ViewOrdine::aggiungiRigaProdotto(Prodotto * prod)
{
    if(n<N)
    {
        container[n]=new MyWidget(n,this);
        riga=new QHBoxLayout();
        if(Torta* torta=dynamic_cast<Torta*>(prod)){
            QLabel* tipoprodottolabel=new QLabel("Torta:");
            riga->addWidget(tipoprodottolabel);
            QLabel* pesolabel=new QLabel("Peso(Kg): ",container[n]);
            riga->addWidget(pesolabel);
            QLabel* peso=new QLabel(torta->getPeso().toString(),container[n]);
            peso->setFont(QFont("helvetica",-1,QFont::Bold));
            riga->addWidget(peso);
            QLabel* gustolabel=new QLabel("Gusto: ",container[n]);
            riga->addWidget(gustolabel);
            QLabel* gusto=new QLabel(torta->getGusto(),container[n]);
            gusto->setFont(QFont("helvetica",-1,QFont::Bold));
            riga->addWidget(gusto);
            QLabel* immaginelabel=new QLabel("Immagine: ",container[n]);
            riga->addWidget(immaginelabel);
            QCheckBox* immaginecheck=new QCheckBox(container[n]);
            immaginecheck->setChecked(torta->getImmagine());
            immaginecheck->setEnabled(false);
            riga->addWidget(immaginecheck);
            QLabel* scrittalabel=new QLabel("Scritta: ",container[n]);
            riga->addWidget(scrittalabel);
            QLabel* scritta=new QLabel(torta->getScritta(),container[n]);
            scritta->setFont(QFont("helvetica",-1,QFont::Bold));
            riga->addWidget(scritta);
            QPushButton* modificabutt=new QPushButton("Modifica",container[n]);
            riga->addWidget(modificabutt);
            QPushButton* eliminariga=new QPushButton("Elimina",container[n]);
            riga->addWidget(eliminariga);
            connect(modificabutt,SIGNAL(clicked(bool)),container[n],SLOT(aggiornaRiga()));
            connect(eliminariga,SIGNAL(clicked(bool)),container[n],SLOT(eliminaRiga()));
            connect(container[n],SIGNAL(inviaIDDel(int)),this,SLOT(eliminaRiga(int)));
            connect(container[n],SIGNAL(inviaIDMod(int)),this,SLOT(aggiornaRiga(int)));
        }
        else{
            if(Dolce* dolce=dynamic_cast<Dolce*>(prod))
            {
                QLabel* tipoprodottolabel=new QLabel("Prodotto Dolce:");
                riga->addWidget(tipoprodottolabel);
                QLabel* pesolabel=new QLabel("Peso(Kg): ",container[n]);
                riga->addWidget(pesolabel);
                QLabel* peso=new QLabel(dolce->getPeso().toString(),container[n]);
                peso->setFont(QFont("helvetica",-1,QFont::Bold));
                riga->addWidget(peso);
                QLabel* tipolabel=new QLabel("Tipo: ",container[n]);
                riga->addWidget(tipolabel);
                QLabel* tipo=new QLabel(dolce->getTipo(),container[n]);
                tipo->setFont(QFont("helvetica",-1,QFont::Bold));
                riga->addWidget(tipo);
                QLabel* prezzolabel=new QLabel("Prezzo al Kg(€): ",container[n]);
                riga->addWidget(prezzolabel);
                QLabel* prezzo=new QLabel(QString::number(dolce->getPrezzo()),container[n]);
                prezzo->setFont(QFont("helvetica",-1,QFont::Bold));
                riga->addWidget(prezzo);
                QPushButton* modificabutt=new QPushButton("Modifica",container[n]);
                riga->addWidget(modificabutt);
                QPushButton* eliminariga=new QPushButton("Elimina",container[n]);
                riga->addWidget(eliminariga);
                connect(eliminariga,SIGNAL(clicked(bool)),container[n],SLOT(eliminaRiga()));
                connect(modificabutt,SIGNAL(clicked(bool)),container[n],SLOT(aggiornaRiga()));
                connect(container[n],SIGNAL(inviaIDMod(int)),this,SLOT(aggiornaRiga(int)));
                connect(container[n],SIGNAL(inviaIDDel(int)),this,SLOT(eliminaRiga(int)));
        }
            else{
                if(Salato* salato=dynamic_cast<Salato*>(prod))
                {
                    QLabel* tipoprodottolabel=new QLabel("Prodotto Salato:");
                    riga->addWidget(tipoprodottolabel);
                    QLabel* pezzilabel=new QLabel("Pezzi: ",container[n]);
                    riga->addWidget(pezzilabel);
                    QLabel* pezzi=new QLabel(salato->getPezzi().toString(),container[n]);
                    pezzi->setFont(QFont("helvetica",-1,QFont::Bold));
                    riga->addWidget(pezzi);
                    QLabel* tipolabel=new QLabel("Tipo: ",container[n]);
                    riga->addWidget(tipolabel);
                    QLabel* tipo=new QLabel(salato->getTipo(),container[n]);
                    tipo->setFont(QFont("helvetica",-1,QFont::Bold));
                    riga->addWidget(tipo);
                    QLabel* prezzolabel=new QLabel("Prezzo per pezzo(€): ",container[n]);
                    riga->addWidget(prezzolabel);
                    QLabel* prezzo=new QLabel(QString::number(salato->getPrezzo()),container[n]);
                    prezzo->setFont(QFont("helvetica",-1,QFont::Bold));
                    riga->addWidget(prezzo);
                    QPushButton* modificabutt=new QPushButton("Modifica",container[n]);
                    riga->addWidget(modificabutt);
                    QPushButton* eliminariga=new QPushButton("Elimina",container[n]);
                    riga->addWidget(eliminariga);
                    connect(modificabutt,SIGNAL(clicked(bool)),container[n],SLOT(aggiornaRiga()));
                    connect(eliminariga,SIGNAL(clicked(bool)),container[n],SLOT(eliminaRiga()));
                    connect(container[n],SIGNAL(inviaIDDel(int)),this,SLOT(eliminaRiga(int)));
                    connect(container[n],SIGNAL(inviaIDMod(int)),this,SLOT(aggiornaRiga(int)));
                }
            }
        }
        container[n]->setLayout(riga);
        listlayout->addWidget(container[n]);
        n++;
    }
}

//distruttore standard della view
ViewOrdine::~ViewOrdine()
{
}

//metodoo che crea un dialog per l'inserimento dalla data e dell'ora
void ViewOrdine::inserisciDataOra()
{
    dialbutton=new QDialog();
    QVBoxLayout* layoutdialbutton=new QVBoxLayout();
    MyDateTimeEdit* datetimeedit=new MyDateTimeEdit();
    datetimeedit->setMinimumDate(QDate::currentDate());
    datetimeedit->setMinimumTime(QTime(6,30));
    datetimeedit->setTime(controller->getOra());
    datetimeedit->setDate(controller->getData());
    QPushButton* ok=new QPushButton("Ok");
    layoutdialbutton->addWidget(datetimeedit);
    layoutdialbutton->addWidget(ok);
    dialbutton->setLayout(layoutdialbutton);
    dialbutton->setModal(true);
    dialbutton->show();
    connect(ok,SIGNAL(clicked(bool)),datetimeedit,SLOT(selezionaDataOra()));
    connect(datetimeedit,SIGNAL(inviaDataOra(QDateTime)),this,SLOT(impostaDataOra(QDateTime)));
    connect(ok,SIGNAL(clicked(bool)),dialbutton,SLOT(close()));

}

//metodoo che crea un dialog per l'inserimento dal nome del cliente
void ViewOrdine::inserisciNome()
{
    dialbutton=new QDialog();
    QVBoxLayout* layoutdialbutton=new QVBoxLayout();
    MyLineEdit* nameedit=new MyLineEdit();
    nameedit->setPlaceholderText("Nome");
    nameedit->setText(controller->getNome());
    QPushButton* ok=new QPushButton("Ok");
    layoutdialbutton->addWidget(nameedit);
    layoutdialbutton->addWidget(ok);
    dialbutton->setLayout(layoutdialbutton);
    dialbutton->setModal(true);
    dialbutton->show();
    connect(ok,SIGNAL(clicked(bool)),nameedit,SLOT(selezionaNome()));
    connect(nameedit,SIGNAL(inviaNome(QString)),this,SLOT(impostaNome(QString)));
    connect(ok,SIGNAL(clicked(bool)),dialbutton,SLOT(close()));
}

//metodoo che crea un dialog per l'inserimento del cognome del cliente
void ViewOrdine::inserisciCognome()
{
    dialbutton=new QDialog();
    QVBoxLayout* layoutdialbutton=new QVBoxLayout();
    MyLineEdit* surnameedit=new MyLineEdit();
    surnameedit->setPlaceholderText("Cognome");
    surnameedit->setText(controller->getCognome());
    QPushButton* ok=new QPushButton("Ok");
    layoutdialbutton->addWidget(surnameedit);
    layoutdialbutton->addWidget(ok);
    dialbutton->setLayout(layoutdialbutton);
    dialbutton->setModal(true);
    dialbutton->show();
    connect(ok,SIGNAL(clicked(bool)),surnameedit,SLOT(selezionaCognome()));
    connect(surnameedit,SIGNAL(inviaCognome(QString)),this,SLOT(impostaCognome(QString)));
    connect(ok,SIGNAL(clicked(bool)),dialbutton,SLOT(close()));
}

//metodoo che crea un dialog per l'inserimento del numero del cliente
void ViewOrdine::inserisciNumero()
{
    dialbutton=new QDialog();
    QVBoxLayout* layoutdialbutton=new QVBoxLayout();
    MyLineEdit* numberedit=new MyLineEdit();
    numberedit->setValidator(new QRegExpValidator(QRegExp("[0-9]{5,10}")));
    numberedit->setPlaceholderText("Telefono");
    numberedit->setText(controller->getNumero());
    QPushButton* ok=new QPushButton("Ok");
    layoutdialbutton->addWidget(numberedit);
    layoutdialbutton->addWidget(ok);
    dialbutton->setLayout(layoutdialbutton);
    dialbutton->setModal(true);
    dialbutton->show();
    connect(ok,SIGNAL(clicked(bool)),numberedit,SLOT(selezionaNumero()));
    connect(numberedit,SIGNAL(inviaNumero(QString)),this,SLOT(impostaNumero(QString)));
    connect(ok,SIGNAL(clicked(bool)),dialbutton,SLOT(close()));
}

//metodo che seleziona il valore dal combobox e chiama il metodo appropriato per il prodotto scelto
void ViewOrdine::inserisciProdotto()
{
    QString tipo=productcombo->currentText();
    if(tipo=="Torta"){
        controller->creaTorta(n);
        addTorta();
    }
    else{
        if(tipo=="Prodotto Dolce"){
            controller->creaDolce(n);
            addDolce();
        }
        else{
            if(tipo=="Prodotto Salato"){
                controller->creaSalato(n);
                addSalato();
            }
        }
    }
}

//metodo che chiama il metodo del controller per settare nel model la data e l'ora
void ViewOrdine::impostaDataOra(QDateTime x)
{
    controller->setDataOra(x);
}

//metodo che chiama il metodo del controller per settare nel model il cognome
void ViewOrdine::impostaCognome(QString x)
{
    controller->setCognome(x);
}

//metodo che chiama il metodo del controller per settare nel model il numero
void ViewOrdine::impostaNumero(QString x)
{
    controller->setNumero(x);
}

//metodo che chiama il metodo del controller per settare nel model il nome
void ViewOrdine::impostaNome(QString x)
{
    controller->setNome(x);
}

//metodo che chiama il metodo del controller per settare il peso di una torta
void ViewOrdine::impostaPesoTorta(double x)
{
    controller->torta->setPeso(Peso(x));
}

//metodo che chiama il metodo del controller per settare il peso di un prod dolce
void ViewOrdine::impostaPesoDolce(double x)
{
    controller->dolce->setPeso(Peso(x));
}

//metodo che chiama il metodo del controller per settare il gusto di una torta
void ViewOrdine::impostaGusto(QString x)
{
    controller->torta->setGusto(x);
}

//metodo che chiama il metodo del controller per settare se una torta è decorata con un'immagine o no
void ViewOrdine::impostaImmagine(bool x)
{
    controller->torta->setImmagine(x);
}

//metodo che chiama il metodo del controller per settare la scritta di decorazione di una torta
void ViewOrdine::impostaScritta(QString x)
{
    controller->torta->setScritta(x);
}

//metodo che chiama il metodo del controller per settare il tipo di un prod dolce
void ViewOrdine::impostaTipo(QString x)
{
    controller->dolce->setTipo(x);
}


//metodo che chiama il metodo del controller per settare il tipo di un prod salato
void ViewOrdine::impostaTipoSalato(QString x)
{
    controller->salato->setTipo(x);
}

//metodo che chiama il metodo del controller per settare il numero di pezzi di un prod dolce
void ViewOrdine::impostaPezzi(int x)
{
    controller->salato->setPezzi(Pezzi(x));
}

//metodo che chiama il metodo del controller per settare il prezzo per pezzo di un prod salato
void ViewOrdine::impostaPrezzo(double x)
{
    controller->salato->setPrezzo(x);
}

//metodo che chiama il metodo del controller per settare il prezzo al Kg di un prod dolce
void ViewOrdine::impostaPrezzoDolce(double x)
{
    controller->dolce->setPrezzo(x);
}

//metodo che apre il dialog per selezionare il nome con cui salvare l'ordine
void ViewOrdine::salvaordine()
{
    QString nomefile=QFileDialog::getSaveFileName(this,tr("Salva ordine"),QDir::currentPath(),tr("Ordine (*.xml)"));
    controller->saveOrdine(nomefile);
}

//metodo che passa al controller l'indice della riga del prodotto da eliminare
void ViewOrdine::eliminaRiga(int n)
{
    controller->eliminaProdotto(n);
}

//metodo che passa al controller l'indice della riga del prodotto da modificare
void ViewOrdine::aggiornaRiga(int n)
{
    controller->modificaProdotto(n);
}

//metodo che elimina la riga del prodotto desiderato dalla view
void ViewOrdine::togliRigaProdotto(int i)
{
    listlayout->removeWidget(container[i]);
    delete container[i];
    N++;
}

//metodo che imposta la label con la data e l'ora selezionata e trasforma il bottone "inserisci" in "modifica"
void ViewOrdine::aggiornaDataora(QDateTime x)
{
    datetimelabel->setText(x.toString("dd-MM-yy hh:mm"));
    datetimebutt->setText("Modifica");
    datetimelabel->setFont(QFont("helvetica",-1,QFont::Bold));
    datetimelayout->removeWidget(datetimebutt);
    datetimelayout->addWidget(datetimelabel);
    datetimelayout->addWidget(datetimebutt,0,Qt::AlignLeft);
}

//metodo che imposta la label con il cognome inserito e trasforma il bottone "inserisci" in "modifica"
void ViewOrdine::aggiornaCognome(QString x)
{
    surnamelabel->setText(x);
    surnamebutt->setText("Modifica");
    surnamelabel->setFont(QFont("helvetica",-1,QFont::Bold));
    surnamelayout=new QHBoxLayout;
    surnamelayout->addWidget(surnamelabel);
    surnamelayout->addWidget(surnamebutt);
    gridlayout->addLayout(surnamelayout,3,1);
}

//metodo che imposta la label con il nome inserito e trasforma il bottone "inserisci" in "modifica"
void ViewOrdine::aggiornaNome(QString x)
{
    namebutt->setText("Modifica");
    namelabel->setText(x);
    namelabel->setFont(QFont("helvetica",-1,QFont::Bold));
    namelayout=new QHBoxLayout;
    namelayout->addWidget(namelabel);
    namelayout->addWidget(namebutt);
    gridlayout->addLayout(namelayout,3,3);
}


//metodo che imposta la label con il numero inserito e trasforma il bottone "inserisci" in "modifica"
void ViewOrdine::aggiornaNumero(QString x)
{
    numberbutt->setText("Modifica");
    numberlabel->setText(x);
    numberlabel->setFont(QFont("helvetica",-1,QFont::Bold));
    numberlayout=new QHBoxLayout;
    numberlayout->addWidget(numberlabel);
    numberlayout->addWidget(numberbutt);
    gridlayout->addLayout(numberlayout,3,5);
}

//metodo che imposta il titolo della view
void ViewOrdine::setTitle()
{
    titlelayout=new QHBoxLayout;
    title=new QLabel("In Ordine");
    title->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    title->setFont(QFont("courier",25,QFont::Bold));
    title->setAlignment(Qt::AlignCenter);
    titlelayout->addWidget(title);
}

//metodo che imposta la label della data e dell'ora
void ViewOrdine::setDateTime()
{
    datetime=new QLabel("Data e ora:");
    datetimelabel=new QLabel();
    datetimelayout=new QHBoxLayout;
    datetimelayout->addWidget(datetime,0,Qt::AlignRight);
}

//metodo che imposta la label e il combobox dei prodotti
void ViewOrdine::setProduct()
{
    product=new QLabel("Prodotti:");
    productcombo=new MyComboBox();
    productcombo->addItem("Torta");
    productcombo->addItem("Prodotto Dolce");
    productcombo->addItem("Prodotto Salato");
    productbutt=new QPushButton("Inserisci prodotto");
    productlayout=new QHBoxLayout;
    productlayout->addWidget(product,0,Qt::AlignLeft);
    productlayout->addWidget(productcombo,0,Qt::AlignLeft);
    productlayout->addWidget(productbutt,0,Qt::AlignLeft);
    listlayout=new QVBoxLayout;
}

//metodo che imposta le label dei clienti
void ViewOrdine::setCustomer()
{
    surname=new QLabel("Cognome:");
    name=new QLabel("Nome:");
    number=new QLabel("Telefono:");
    surnamelabel=new QLabel();
    namelabel=new QLabel();
    numberlabel=new QLabel();
    gridlayout->addWidget(surname,3,0);
    gridlayout->addWidget(name,3,2);
    gridlayout->addWidget(number,3,4);
}

//metodo che imposta le label dei preventivo
void ViewOrdine::setEstimate()
{
    estimatelayout=new QHBoxLayout;
    estimatelabel= new QLabel("Preventivo:  €");
    cashlabel= new QLabel("0");
    estimatelayout->addWidget(estimatelabel,0,Qt::AlignRight);
    estimatelayout->addWidget(cashlabel,0,Qt::AlignLeft);
}

//metodo che imposta i bottoni della view
void ViewOrdine::setButtons()
{
    datetimebutt=new QPushButton("Inserisci data e ora");
    datetimebutt->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    namebutt=new QPushButton("Inserisci nome");
    namebutt->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    surnamebutt=new QPushButton("Inserisci cognome");
    surnamebutt->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    numberbutt=new QPushButton("Inserisci telefono");
    numberbutt->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    savebutt=new QPushButton("Salva");
    savebutt->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    savelayout=new QHBoxLayout;
    connect(datetimebutt,SIGNAL(clicked(bool)),this,SLOT(inserisciDataOra()));
    connect(numberbutt,SIGNAL(clicked(bool)),this,SLOT(inserisciNumero()));
    connect(surnamebutt,SIGNAL(clicked(bool)),this,SLOT(inserisciCognome()));
    connect(namebutt,SIGNAL(clicked(bool)),this,SLOT(inserisciNome()));
    connect(productbutt,SIGNAL(clicked(bool)),this,SLOT(inserisciProdotto()));
    connect(savebutt,SIGNAL(clicked(bool)),this,SLOT(salvaordine()));
    datetimelayout->addWidget(datetimebutt,0,Qt::AlignLeft);
    gridlayout->addWidget(productbutt,2,2);
    gridlayout->addWidget(surnamebutt,3,1);
    gridlayout->addWidget(namebutt,3,3);
    gridlayout->addWidget(numberbutt,3,5);
    savelayout->addWidget(savebutt);

}

//metodo per settare la label del preventivo con il giusto valore
void ViewOrdine::setPreventivo(double x)
{
    cashlabel->setText(QString::number(x));
}

//metodo che crea il dialog per l'inserimento di una torta
void ViewOrdine::addTorta()
{
    dialbutton=new QDialog();
    QHBoxLayout* layoutdialbutton=new QHBoxLayout();
    QLabel * peso=new QLabel("Peso(Kg):");
    MyLineEdit* pesoedit=new MyLineEdit();
    pesoedit->setValidator(new QDoubleValidator(0,10,2));
    pesoedit->setPlaceholderText("in Kg");
    QLabel * gusto=new QLabel("Gusto:");
    MyComboBox* gustoedit=new MyComboBox();
    gustoedit->setEditable(true);
    gustoedit->addItem("Della casa");
    gustoedit->addItem("Pan di spagna con chantilly e fragole");
    MyCheckBox* immaginecheck=new MyCheckBox("Con immagine");
    QLabel * scritta=new QLabel("Scritta di decorazione:");
    MyLineEdit* scrittaedit=new MyLineEdit();
    QPushButton* ok=new QPushButton("Ok");
    layoutdialbutton->addWidget(peso);
    layoutdialbutton->addWidget(pesoedit);
    layoutdialbutton->addWidget(gusto);
    layoutdialbutton->addWidget(gustoedit);
    layoutdialbutton->addWidget(immaginecheck);
    layoutdialbutton->addWidget(scritta);
    layoutdialbutton->addWidget(scrittaedit);
    layoutdialbutton->addWidget(ok);
    dialbutton->setLayout(layoutdialbutton);
    dialbutton->setModal(true);
    dialbutton->show();
    connect(ok,SIGNAL(clicked(bool)),pesoedit,SLOT(selezionaPesoTorta()));
    connect(ok,SIGNAL(clicked(bool)),gustoedit,SLOT(selezionaScritta()));
    connect(ok,SIGNAL(clicked(bool)),immaginecheck,SLOT(selezionaImmagine()));
    connect(ok,SIGNAL(clicked(bool)),scrittaedit,SLOT(selezionaScritta()));
    connect(pesoedit,SIGNAL(inviaPesoTorta(double)),this,SLOT(impostaPesoTorta(double)));
    connect(gustoedit,SIGNAL(inviaScritta(QString)),this,SLOT(impostaGusto(QString)));
    connect(scrittaedit,SIGNAL(inviaScritta(QString)),this,SLOT(impostaScritta(QString)));
    connect(immaginecheck,SIGNAL(inviaImmagine(bool)),this,SLOT(impostaImmagine(bool)));
    connect(ok,SIGNAL(clicked(bool)),this,SLOT(aggiungiTorta()));
    connect(ok,SIGNAL(clicked(bool)),dialbutton,SLOT(close()));
}

//metodo che crea il dialog per l'inserimento di un prod dolce
void ViewOrdine::addDolce()
{
    dialbutton=new QDialog();
    QHBoxLayout* layoutdialbutton=new QHBoxLayout();
    QLabel * peso=new QLabel("Peso(Kg):");
    MyLineEdit* pesoedit=new MyLineEdit();
    pesoedit->setValidator(new QDoubleValidator(0,10,2));
    pesoedit->setPlaceholderText("in Kg");
    QLabel * tipo=new QLabel("Tipo:");
    MyComboBox* tipoedit=new MyComboBox();
    tipoedit->setEditable(true);
    tipoedit->addItem("Pasticcini");
    tipoedit->addItem("Biscotti");
    tipoedit->addItem("Colomba");
    QLabel * prezzo=new QLabel("Prezzo al Kg:");
    MyLineEdit* prezzoedit=new MyLineEdit();
    prezzoedit->setValidator(new QDoubleValidator(0,50,2));
    prezzoedit->setPlaceholderText("in Euro");
    QPushButton* ok=new QPushButton("Ok");
    layoutdialbutton->addWidget(peso);
    layoutdialbutton->addWidget(pesoedit);
    layoutdialbutton->addWidget(tipo);
    layoutdialbutton->addWidget(tipoedit);
    layoutdialbutton->addWidget(prezzo);
    layoutdialbutton->addWidget(prezzoedit);
    layoutdialbutton->addWidget(ok);
    dialbutton->setLayout(layoutdialbutton);
    dialbutton->setModal(true);
    dialbutton->show();

    connect(ok,SIGNAL(clicked(bool)),pesoedit,SLOT(selezionaPesoDolce()));
    connect(ok,SIGNAL(clicked(bool)),tipoedit,SLOT(selezionaScritta()));
    connect(ok,SIGNAL(clicked(bool)),prezzoedit,SLOT(selezionaPrezzo()));
    connect(pesoedit,SIGNAL(inviaPesoDolce(double)),this,SLOT(impostaPesoDolce(double)));
    connect(tipoedit,SIGNAL(inviaScritta(QString)),this,SLOT(impostaTipo(QString)));
    connect(prezzoedit,SIGNAL(inviaPrezzo(double)),this,SLOT(impostaPrezzoDolce(double)));
    connect(ok,SIGNAL(clicked(bool)),this,SLOT(aggiungiDolce()));
    connect(ok,SIGNAL(clicked(bool)),dialbutton,SLOT(close()));
}

//metodo che crea il dialog per l'inserimento di un prod salato
void ViewOrdine::addSalato()
{
    dialbutton=new QDialog();
    QHBoxLayout* layoutdialbutton=new QHBoxLayout();
    QLabel * pezzi=new QLabel("Pezzi:");
    MyLineEdit* pezziedit=new MyLineEdit();
    pezziedit->setValidator(new QIntValidator(0,300));
    QLabel * tipo=new QLabel("Tipo:");
    MyComboBox* tipoedit=new MyComboBox();
    tipoedit->setEditable(true);
    tipoedit->addItem("Tramezzini");
    tipoedit->addItem("Salatini");
    tipoedit->addItem("Pizzette");
    QLabel * prezzo=new QLabel("Prezzo al Pezzo:");
    MyLineEdit* prezzoedit=new MyLineEdit();
    prezzoedit->setValidator(new QDoubleValidator(0,50,2));
    prezzoedit->setPlaceholderText("in Euro");
    QPushButton* ok=new QPushButton("Ok");
    layoutdialbutton->addWidget(pezzi);
    layoutdialbutton->addWidget(pezziedit);
    layoutdialbutton->addWidget(tipo);
    layoutdialbutton->addWidget(tipoedit);
    layoutdialbutton->addWidget(prezzo);
    layoutdialbutton->addWidget(prezzoedit);
    layoutdialbutton->addWidget(ok);
    dialbutton->setLayout(layoutdialbutton);
    dialbutton->setModal(true);
    dialbutton->setModal(true);
    dialbutton->show();
    connect(ok,SIGNAL(clicked(bool)),pezziedit,SLOT(selezionaPezzi()));
    connect(ok,SIGNAL(clicked(bool)),tipoedit,SLOT(selezionaScritta()));
    connect(ok,SIGNAL(clicked(bool)),prezzoedit,SLOT(selezionaPrezzo()));
    connect(pezziedit,SIGNAL(inviaPezzi(int)),this,SLOT(impostaPezzi(int)));
    connect(tipoedit,SIGNAL(inviaScritta(QString)),this,SLOT(impostaTipoSalato(QString)));
    connect(prezzoedit,SIGNAL(inviaPrezzo(double)),this,SLOT(impostaPrezzo(double)));
    connect(ok,SIGNAL(clicked(bool)),this,SLOT(aggiungiSalato()));
    connect(ok,SIGNAL(clicked(bool)),dialbutton,SLOT(close()));
}

//metodo che passa fa inserire al controller la torta nel model
void ViewOrdine::aggiungiTorta()
{
    controller->aggiungiProdotto("Torta");
}

//metodo che passa fa inserire al controller il prodotto dolce nel model
void ViewOrdine::aggiungiDolce()
{
    controller->aggiungiProdotto("Prodotto Dolce");
}

//metodo che passa fa inserire al controller il prodotto salato nel model
void ViewOrdine::aggiungiSalato()
{
    controller->aggiungiProdotto("Prodotto Salato");
}
