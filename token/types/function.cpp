#include "function.h"

Function::Function(QString c_str, QObject* parent)
    : Token(c_str, parent)
{}

Token::Type Function::getType()
{
    return Token::Type::function;
}

double Function::execute(double operand, bool *ok)
{
    if(ok){*ok = false;}
    return 0;
}
