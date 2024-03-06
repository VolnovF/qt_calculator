#ifndef OPENPARENTHESIS_H
#define OPENPARENTHESIS_H

#include "../token.h"

class OpenParenthesis : public Token
{
public:
    OpenParenthesis(QObject* parent = nullptr);

    Token::Type getType() override;
};

#endif // OPENPARENTHESIS_H
