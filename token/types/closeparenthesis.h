#ifndef CLOSEPARENTHESIS_H
#define CLOSEPARENTHESIS_H

#include "../token.h"

class CloseParenthesis : public Token
{
public:
    CloseParenthesis(QObject* parent = nullptr);

    Token::Type getType() override;
};

#endif // CLOSEPARENTHESIS_H
