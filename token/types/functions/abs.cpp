#include "abs.h"

Abs::Abs(QObject* parent)
    : Function( QString("abs"), parent )
{}

double Abs::execute(double operand, bool *ok)
{
    return qFabs( operand );
}
