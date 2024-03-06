#include "token.h"

Token::Token(QObject* parent)
    : QObject(parent)
{
    str = "";
}

Token::Token(QString c_str, QObject* parent)
    : QObject(parent)
{
    str = c_str;
}

const QString& Token::getStr()
{
    return str;
}

Token::Type Token::getType()
{
    return Token::Type::maxTypes;
}

int Token::getPriority(bool* ok)
{
    if(ok){*ok = false;}
    return 0;
}

double Token::execute(double leftOperand, double rightOperand, bool* ok)
{
    if(ok){*ok = false;}
    return 0;
}

double Token::execute(double operand, bool *ok)
{
    if(ok){*ok = false;}
    return 0;
}

bool Token::isOperation(const QChar& symbol)
{
    static const QString operations{ "+-*/^" };
    return operations.contains(symbol);
}

bool Token::isOpenParenthesis(const QChar& symbol)
{
    return symbol == '(';
}

bool Token::isCloseParenthesis(const QChar& symbol)
{
    return symbol == ')';
}
