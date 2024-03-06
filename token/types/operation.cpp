#include "operation.h"

Operation::Operation(QString c_str, QObject* parent)
    : Token(c_str, parent)
{}

Token::Type Operation::getType()
{
    return Token::Type::operation;
}

int Operation::getPriority(bool *ok)
{
    static const QMap<QString, int> priorityMap
    {
        {"+", 1},
        {"-", 1},
        {"*", 2},
        {"/", 2},
        {"^", 3}
    };

    if( !priorityMap.contains(getStr()) )
    {
        if(ok){*ok = false;}
        return 0;
    }

    return priorityMap[getStr()];
}

double Operation::execute(double leftOperand, double rightOperand, bool *ok)
{
    switch ( (getStr().toStdString())[0] ) {
    case '+':
        return leftOperand + rightOperand;
    case '-':
        return leftOperand - rightOperand;
    case '*':
        return leftOperand * rightOperand;
    case '/':
        return leftOperand / rightOperand;
    case '^':
        return qPow(leftOperand, rightOperand);
    default:
        if(ok){*ok = false;}
        return 0;
    }
}
