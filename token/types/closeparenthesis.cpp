#include "closeparenthesis.h"

CloseParenthesis::CloseParenthesis(QObject* parent)
    : Token( QString(")"), parent )
{}

Token::Type CloseParenthesis::getType()
{
    return Token::Type::closeParenthesis;
}
