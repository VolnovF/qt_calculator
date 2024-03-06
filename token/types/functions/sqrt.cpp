#include "sqrt.h"

Sqrt::Sqrt(QObject* parent)
    : Function( QString("sqrt"), parent )
{}

double Sqrt::execute(double operand, bool *ok)
{
    return qSqrt( operand );
}
