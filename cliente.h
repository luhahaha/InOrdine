#ifndef CLIENTE_H
#define CLIENTE_H

#include <QString>

class Cliente
{
private:
    QString cognome,nome,numero;
public:
    Cliente(QString="",QString="",QString="");
    Cliente(const Cliente &);
    QString getcognome()const;
    QString getnome()const;
    QString getnumero()const;
    void setCognome(QString);
    void setNome(QString);
    void setNumero(QString);
};

#endif // CLIENTE_H
