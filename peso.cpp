#include "peso.h"

Peso::Peso(double g):kg(g)
{
}

Peso::Peso(const Peso & x):kg(x.kg)
{

}

void Peso::setPeso(Peso x)
{
    kg=x.kg;
}

QString Peso::toString() const
{
    return QString::number(kg);
}

