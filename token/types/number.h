#ifndef NUMBER_H
#define NUMBER_H

#include "../token.h"


class Number : public Token
{
public:
    Number(QString c_str, QObject* parent = nullptr);

    Token::Type getType() override;
};

#endif // NUMBER_H
