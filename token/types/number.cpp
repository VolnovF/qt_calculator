#include "number.h"

Number::Number(QString c_str, QObject* parent)
    : Token(c_str, parent)
{}

Token::Type Number::getType()
{
    return Token::Type::number;
}
