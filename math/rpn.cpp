#include "rpn.h"

void ToRPN(QQueue<Token*>& infix, QQueue<Token*>& rpn , bool* ok)
{   
    QStack<Token*> buffer;

    static auto error{ [] (bool* ptr)
    {
        if( ptr )
        {
            *ptr = false;
        }
    } };

    Token* infixToken{};
    Token* bufferTop{};
    while ( !infix.empty() )
    {
        infixToken = infix.dequeue();
        switch ( infixToken->getType() )
        {
        case Token::Type::number:
            rpn.enqueue( infixToken );
            break;
        case Token::Type::operation:
            while ( !buffer.empty() )
            {
                bufferTop = buffer.top();
                if( bufferTop->getPriority() >= infixToken->getPriority() )
                {
                    rpn.enqueue( buffer.pop() );
                }
                else
                {
                    break;
                }
            }
            buffer.push( infixToken );
            break;
        case Token::Type::function:
            buffer.push( infixToken );
            break;
        case Token::Type::openParenthesis:
            buffer.push( infixToken );
            break;
        case Token::Type::closeParenthesis:
            while (true) {
                if( buffer.empty() )
                {
                    error(ok);
                    return;
                }
                bufferTop = buffer.top();
                if ( bufferTop->getType()==Token::Type::openParenthesis )
                {
                    buffer.pop();
                    bufferTop = buffer.top();
                    if ( bufferTop->getType()==Token::Type::function )
                    {
                        rpn.enqueue( buffer.pop() );
                    }
                    break;
                }
                else
                {
                    rpn.enqueue( buffer.pop() );
                }
            }
            break;
        default:
            error(ok);
            break;
        }

        if( ok && (*ok == false) )
        {
            return;
        }
    }

    while ( !buffer.empty() )
    {
        bufferTop = buffer.top();
        if( bufferTop->getType() == Token::Type::operation )
        {
            rpn.enqueue( buffer.pop() );
        }
        else
        {
            error(ok);
            return;
        }
    }
}
