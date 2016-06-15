#include "controllerordine.h"

//costruttore del controller che crea il model e la view
ControllerOrdine::ControllerOrdine(QWidget* parent):model(new Ordine()),view(new ViewOrdine(this,parent))
{
}

//metodo che imposta la data e l'ora nel model e che notifica la view di ciò
void ControllerOrdine::setDataOra(QDateTime x)
{
    model->setData(x.date());
    model->setTime(x.time());
    emit view->aggiornaDataora(x);
}

//metodo che imposta il cognome nel model e che notifica la view di ciò
void ControllerOrdine::setCognome(QString x)
{
    model->setCognome(x);
    emit view->aggiornaCognome(x);
}

//metodo che imposta il numero nel model e che notifica la view di ciò
void ControllerOrdine::setNumero(QString x)
{
    model->setNumero(x);
    emit view->aggiornaNumero(x);
}

//metodo che imposta il nome nel model e che notifica la view di ciò
void ControllerOrdine::setNome(QString x)
{
    model->setNome(x);
    emit view->aggiornaNome(x);
}

//metodo che crea il file e ci scrive i dati contenuti nel model per il salvataggio
void ControllerOrdine::saveOrdine(QString nomefile)
{
    QFile file(nomefile);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug() <<"Errore apertura file";
    else
    {
        QXmlStreamWriter stream(&file);
        stream.setAutoFormatting(true);
        stream.writeStartDocument();
        stream.writeStartElement("ordine");
        stream.writeTextElement("dataora",model->getData().toString("dd-MM-yy hh:mm"));
        stream.writeStartElement("prodotti");
        for(Contenitore::Iteratore it=model->getOrdini().begin();it!=model->getOrdini().end();++it){
             if(Torta* torta=dynamic_cast<Torta*>(model->getOrdini()[it]))
            {
                stream.writeStartElement("torta");
                stream.writeTextElement("peso",torta->getPeso().toString());
                stream.writeTextElement("gusto",torta->getGusto());
                stream.writeTextElement("immagine",QString::number(torta->getImmagine()));
                stream.writeTextElement("scritta",torta->getScritta());
                stream.writeEndElement();
            }
            else{
                if(Dolce* dolce=dynamic_cast<Dolce*>(model->getOrdini()[it])){
                    stream.writeStartElement("dolce");
                    stream.writeTextElement("peso",dolce->getPeso().toString());
                    stream.writeTextElement("tipo",dolce->getTipo());
                    stream.writeTextElement("prezzo",QString::number(dolce->getPrezzo()));
                    stream.writeEndElement();
                }
                else{
                    if(Salato* salato=dynamic_cast<Salato*>(model->getOrdini()[it]))
                    {
                        stream.writeStartElement("salato");
                        stream.writeTextElement("tipo",salato->getTipo());
                        stream.writeTextElement("pezzi",salato->getPezzi().toString());
                        stream.writeTextElement("prezzo",QString::number(salato->getPrezzo()));
                        stream.writeEndElement();
                    }
                }
            }
        }
        stream.writeEndElement();
        stream.writeStartElement("cliente");
        stream.writeTextElement("cognome",model->getCliente().getcognome());
        stream.writeTextElement("nome",model->getCliente().getnome());
        stream.writeTextElement("numero",model->getCliente().getnumero());
        stream.writeEndElement();
        stream.writeEndElement();
        stream.writeEndDocument();
        file.close();
    }
}

//metodo che setta i campi dati del model leggendoli dal file e notifica la view
void ControllerOrdine::caricaOrdine(QString nomefile)
{
    QFile file(nomefile);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() <<"Errore apertura file";
    else
    {
        QXmlStreamReader stream(&file);
        while (!stream.atEnd())
        {
            if (stream.readNextStartElement())
            {
                QString elemento=stream.name().toString();
                if(elemento=="dataora")
                {
                    model->setDateTime(QDateTime::fromString(stream.readElementText(),"dd-MM-yy hh:mm"));
                    emit view->aggiornaDataora(model->getData());
                }
                if(elemento=="cliente")
                {
                    stream.readNextStartElement();
                    model->setCognome(stream.readElementText());
                    emit view->aggiornaCognome(model->getCliente().getcognome());
                    stream.readNextStartElement();
                    model->setNome(stream.readElementText());
                    emit view->aggiornaNome(model->getCliente().getnome());
                    stream.readNextStartElement();
                    model->setNumero(stream.readElementText());
                    emit view->aggiornaNumero(model->getCliente().getnumero());
                }
                if(elemento=="torta")  
                {
                    creaTorta(view->n);
                    stream.readNextStartElement();
                    torta->setPeso(Peso(stream.readElementText().toDouble()));
                    stream.readNextStartElement();
                    torta->setGusto(stream.readElementText());
                    stream.readNextStartElement();
                    torta->setImmagine(bool(stream.readElementText().toInt()));
                    stream.readNextStartElement();
                    torta->setScritta(stream.readElementText());
                    aggiungiProdotto("Torta");
                }
                if(elemento=="dolce")
                {
                    creaDolce(view->n);
                    stream.readNextStartElement();
                    dolce->setPeso(Peso(stream.readElementText().toDouble()));
                    stream.readNextStartElement();
                    dolce->setTipo(stream.readElementText());
                    stream.readNextStartElement();
                    dolce->setPrezzo(stream.readElementText().toDouble());
                    aggiungiProdotto("Prodotto Dolce");
                }
                if(elemento=="salato")
                {
                    creaSalato(view->n);
                    stream.readNextStartElement();
                    salato->setTipo(stream.readElementText());
                    stream.readNextStartElement();
                    salato->setPezzi(Pezzi(stream.readElementText().toInt()));
                    stream.readNextStartElement();
                    salato->setPrezzo(stream.readElementText().toDouble());
                    aggiungiProdotto("Prodotto Salato");
                }
            }
        }
    }
}

//metodo che crea una torta nel controller per immagazzinare i dati della view e poi inserirla nel model
void ControllerOrdine::creaTorta(int n)
{
    torta=new Torta(n);
}
//metodo che crea un prod dolce nel controller per immagazzinare i dati della view e poi inserirla nel model
void ControllerOrdine::creaDolce(int n)
{
    dolce=new Dolce(n);
}

//metodo che crea un prod salato nel controller per immagazzinare i dati della view e poi inserirla nel model
void ControllerOrdine::creaSalato(int n)
{
    salato=new Salato(n);
}

//metodo che elimina dal model e dalla view un prodotto
void ControllerOrdine::eliminaProdotto(int n)
{
    model->eliminaOrdine(n);
    view->togliRigaProdotto(n);
    view->resize(50,50);
    view->setPreventivo(getPreventivo());
}

//metodo che crea il dialog per l'inserimento e la modifica di un prodotto
void ControllerOrdine::modificaProdotto(int n)
{
    Prodotto* aux=model->getOrdine(n);
    if(Torta*torta=dynamic_cast<Torta*>(aux)){
        creaTorta(view->n);
        QDialog* dialbutton=new QDialog(view);
        QHBoxLayout* layoutdialbutton=new QHBoxLayout(dialbutton);
        QLabel * peso=new QLabel("Peso(Kg):",dialbutton);
        MyLineEdit* pesoedit=new MyLineEdit(torta->getPeso().toString(),dialbutton);
        QLabel * gusto=new QLabel("Gusto:",dialbutton);
        MyComboBox* gustoedit=new MyComboBox(dialbutton);
        gustoedit->setEditable(true);
        gustoedit->addItem("Della casa");
        gustoedit->addItem("Pan di spagna con chantilly e fragole");
        gustoedit->addItem("Pan di spagna con crema al cioccolato");
        gustoedit->addItem("Mille foglie con crema chantilly");
        gustoedit->setEditText(torta->getGusto());
        MyCheckBox* immaginecheck=new MyCheckBox("Con immagine",dialbutton);
        if(torta->getImmagine())
            immaginecheck->setChecked(true);
        QLabel * scritta=new QLabel("Scritta di decorazione:",dialbutton);
        MyLineEdit* scrittaedit=new MyLineEdit(torta->getScritta(),dialbutton);
        QPushButton* ok=new QPushButton("Ok",dialbutton);
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
        QObject::connect(ok,SIGNAL(clicked(bool)),pesoedit,SLOT(selezionaPesoTorta()));
        QObject::connect(ok,SIGNAL(clicked(bool)),gustoedit,SLOT(selezionaScritta()));
        QObject::connect(ok,SIGNAL(clicked(bool)),immaginecheck,SLOT(selezionaImmagine()));
        QObject::connect(ok,SIGNAL(clicked(bool)),scrittaedit,SLOT(selezionaScritta()));
        QObject::connect(pesoedit,SIGNAL(inviaPesoTorta(double)),view,SLOT(impostaPesoTorta(double)));
        QObject::connect(gustoedit,SIGNAL(inviaScritta(QString)),view,SLOT(impostaGusto(QString)));
        QObject::connect(scrittaedit,SIGNAL(inviaScritta(QString)),view,SLOT(impostaScritta(QString)));
        QObject::connect(immaginecheck,SIGNAL(inviaImmagine(bool)),view,SLOT(impostaImmagine(bool)));
        QObject::connect(ok,SIGNAL(clicked(bool)),view,SLOT(aggiungiTorta()));
        QObject::connect(ok,SIGNAL(clicked(bool)),view->container[n],SLOT(eliminaRiga()));
        QObject::connect(ok,SIGNAL(clicked(bool)),dialbutton,SLOT(close()));
    }
    else{
        if(Dolce* dolce=dynamic_cast<Dolce*>(aux)){
            creaDolce(view->n);
            QDialog* dialbutton=new QDialog(view);
            QHBoxLayout* layoutdialbutton=new QHBoxLayout(dialbutton);
            QLabel * peso=new QLabel("Peso(Kg):",dialbutton);
            MyLineEdit* pesoedit=new MyLineEdit(dolce->getPeso().toString(),dialbutton);
            QLabel * tipo=new QLabel("Tipo:",dialbutton);
            MyComboBox* tipoedit=new MyComboBox(dialbutton);
            tipoedit->setEditable(true);
            tipoedit->addItem("Pasticcini");
            tipoedit->addItem("Biscotti");
            tipoedit->addItem("Colomba");
            tipoedit->addItem("Panettone");
            tipoedit->setEditText(dolce->getTipo());
            QLabel * prezzo=new QLabel("Prezzo al Kg:",dialbutton);
            MyLineEdit* prezzoedit=new MyLineEdit(QString::number(dolce->getPrezzo()),dialbutton);
            QPushButton* ok=new QPushButton("Ok",dialbutton);
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
            QObject::connect(ok,SIGNAL(clicked(bool)),pesoedit,SLOT(selezionaPesoDolce()));
            QObject::connect(ok,SIGNAL(clicked(bool)),tipoedit,SLOT(selezionaScritta()));
            QObject::connect(ok,SIGNAL(clicked(bool)),prezzoedit,SLOT(selezionaPrezzo()));
            QObject::connect(pesoedit,SIGNAL(inviaPesoDolce(double)),view,SLOT(impostaPesoDolce(double)));
            QObject::connect(tipoedit,SIGNAL(inviaScritta(QString)),view,SLOT(impostaTipo(QString)));
            QObject::connect(prezzoedit,SIGNAL(inviaPrezzo(double)),view,SLOT(impostaPrezzoDolce(double)));
            QObject::connect(ok,SIGNAL(clicked(bool)),view,SLOT(aggiungiDolce()));
            QObject::connect(ok,SIGNAL(clicked(bool)),view->container[n],SLOT(eliminaRiga()));
            QObject::connect(ok,SIGNAL(clicked(bool)),dialbutton,SLOT(close()));
        }
        else{
            if(Salato* salato=dynamic_cast<Salato*>(aux))
            {
                creaSalato(view->n);
                QDialog* dialbutton=new QDialog(view);
                QHBoxLayout* layoutdialbutton=new QHBoxLayout(dialbutton);
                QLabel * pezzi=new QLabel("Pezzi:",dialbutton);
                MyLineEdit* pezziedit=new MyLineEdit(salato->getPezzi().toString(),dialbutton);
                QLabel * tipo=new QLabel("Tipo:",dialbutton);
                MyComboBox* tipoedit=new MyComboBox(dialbutton);
                tipoedit->setEditable(true);
                tipoedit->addItem("Tramezzini");
                tipoedit->addItem("Salatini");
                tipoedit->addItem("Pizzette");
                tipoedit->setEditText(salato->getTipo());
                QLabel * prezzo=new QLabel("Prezzo al Pezzo:",dialbutton);
                MyLineEdit* prezzoedit=new MyLineEdit(QString::number(salato->getPrezzo()),dialbutton);
                QPushButton* ok=new QPushButton("Ok",dialbutton);
                layoutdialbutton->addWidget(pezzi);
                layoutdialbutton->addWidget(pezziedit);
                layoutdialbutton->addWidget(tipo);
                layoutdialbutton->addWidget(tipoedit);
                layoutdialbutton->addWidget(prezzo);
                layoutdialbutton->addWidget(prezzoedit);
                layoutdialbutton->addWidget(ok);
                dialbutton->setLayout(layoutdialbutton);
                dialbutton->setModal(true);
                dialbutton->show();
                QObject::connect(ok,SIGNAL(clicked(bool)),pezziedit,SLOT(selezionaPezzi()));
                QObject::connect(ok,SIGNAL(clicked(bool)),tipoedit,SLOT(selezionaScritta()));
                QObject::connect(ok,SIGNAL(clicked(bool)),prezzoedit,SLOT(selezionaPrezzo()));
                QObject::connect(pezziedit,SIGNAL(inviaPezzi(int)),view,SLOT(impostaPezzi(int)));
                QObject::connect(tipoedit,SIGNAL(inviaScritta(QString)),view,SLOT(impostaTipoSalato(QString)));
                QObject::connect(prezzoedit,SIGNAL(inviaPrezzo(double)),view,SLOT(impostaPrezzo(double)));
                QObject::connect(ok,SIGNAL(clicked(bool)),view,SLOT(aggiungiSalato()));
                QObject::connect(ok,SIGNAL(clicked(bool)),view->container[n],SLOT(eliminaRiga()));
                QObject::connect(ok,SIGNAL(clicked(bool)),dialbutton,SLOT(close()));
            }

        }

    }}

//metodo che calcola il preventivo dei prodotti salvati nel model
double ControllerOrdine::getPreventivo()
{
    double preventivo=0;
    for(Contenitore::Iteratore it=model->getOrdini().begin();it!=model->getOrdini().end();++it)
    {
        preventivo+=model->getOrdini()[it]->Preventivo();
    }
    return preventivo;
}

QString ControllerOrdine::getNome() const
{
    return model->getCliente().getnome();
}

QString ControllerOrdine::getCognome() const
{
    return model->getCliente().getcognome();
}

QString ControllerOrdine::getNumero() const
{
    return model->getCliente().getnumero();
}

QDate ControllerOrdine::getData() const
{
    return model->getData().date();
}

QTime ControllerOrdine::getOra() const
{
    return model->getData().time();
}

ControllerOrdine::~ControllerOrdine()
{
    delete model;
    delete view;
}

//metodo che inserisce un prodotto nel model e nella view e cambia il valore del preventivo
void ControllerOrdine::aggiungiProdotto(QString x)
{

    if(x=="Torta"){
        model->inserisciOrdine(torta);
        view->aggiungiRigaProdotto(torta);
        view->setPreventivo(getPreventivo());
    }
    else{
        if(x=="Prodotto Dolce"){
            model->inserisciOrdine(dolce);
            view->aggiungiRigaProdotto(dolce);
            view->setPreventivo(getPreventivo());
        }
        else{
            model->inserisciOrdine(salato);
            view->aggiungiRigaProdotto(salato);
            view->setPreventivo(getPreventivo());
        }
    }

}



