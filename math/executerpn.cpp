#include "executerpn.h"

double executeRPN(QQueue<Token*> &rpn, bool *ok)
{
    QStack<double> buffer{};

    static auto error{ [] (bool* ptr)
    {
        if( ptr )
        {
            *ptr = false;
        }
    } };

    Token* token{};
    double leftOperand;
    double rightOperand;

    while ( !rpn.empty() )
    {
        token = rpn.dequeue();
        switch ( token->getType() ) {
        case Token::Type::number:
            buffer.push( token->getStr().toDouble(ok) );
            break;
        case Token::Type::operation:
            if( buffer.size() >= 2 )
            {
                rightOperand = buffer.pop();
                leftOperand = buffer.pop();
                buffer.push( token->execute(leftOperand, rightOperand, ok) );
            }
            else
            {
                error(ok);
                return 0;
            }
            break;
        case Token::Type::function:
            if( !buffer.isEmpty() )
            {
                rightOperand = buffer.pop();
                buffer.push( token->execute(rightOperand, ok) );
            }
            else
            {
                error(ok);
                return 0;;
            }
            break;
        default:
            error(ok);
            break;
        };
        if( ok && (*ok == false) )
        {
            return 0;
        }
    }

    if( buffer.size() == 1 )
    {
        return buffer.pop();
    }
    else
    {
        error(ok);
        return 0;
    }
}
