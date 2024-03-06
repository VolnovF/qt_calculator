#ifndef FUNCTION_H
#define FUNCTION_H

//#include <QMap>
#include <QtMath>
#include "../token.h"

class Function : public Token
{
public:
    Function(QString c_str, QObject* parent = nullptr);

    Token::Type getType() override;
    double execute(double operand, bool* ok = nullptr) override;
};

#endif // FUNCTION_H
