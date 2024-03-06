#include "cos.h"

Cos::Cos(QObject* parent)
    : Function( QString("cos"), parent )
{}

double Cos::execute(double operand, bool *ok)
{
    return qCos( operand );
}
