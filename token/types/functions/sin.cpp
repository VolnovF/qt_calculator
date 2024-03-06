#include "sin.h"

Sin::Sin(QObject* parent)
    : Function( QString("sin"), parent )
{}

double Sin::execute(double operand, bool *ok)
{
    return qSin( operand );
}
