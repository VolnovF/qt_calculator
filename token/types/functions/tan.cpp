#include "tan.h"

Tan::Tan(QObject *parent)
    : Function( QString("tan"), parent )
{}

double Tan::execute(double operand, bool *ok)
{
    return qTan( operand );
}
