#ifndef OPERATION_H
#define OPERATION_H

#include <QMap>
#include <QtMath>
#include "../token.h"

class Operation : public Token
{
public:
    Operation(QString c_str, QObject* parent = nullptr);

    Token::Type getType() override;
    int getPriority(bool* ok = nullptr) override;
    double execute(double leftOperand, double rightOperand, bool* ok = nullptr) override;
};

#endif // OPERATION_H
