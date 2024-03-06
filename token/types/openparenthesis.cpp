#include "openparenthesis.h"

OpenParenthesis::OpenParenthesis(QObject* parent)
    : Token( QString("("), parent )
{}

Token::Type OpenParenthesis::getType()
{
    return Token::Type::openParenthesis;
}
