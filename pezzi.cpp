#include "pezzi.h"

Pezzi::Pezzi(int p):numero(p)
{

}

QString Pezzi::toString() const
{
    return QString::number(numero);
}

