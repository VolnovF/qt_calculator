#include "tokenizer.h"

void Tokenize(const QString& expression, QQueue<Token*>& tokens, QObject* parent, bool* ok)
{
    enum State
    {
        start,
        readNumber,
        negativeNumber,
        readOperation,
        readFunction,
        readOpenParenthesis,
        readCloseParenthesis
    };
    State lastState{ start };

    static auto error{ [] (bool* ptr)
    {
        if( ptr ){*ptr = false;}
    } };

    QString buffer;

    for(auto symbol : expression)
    {
        if(symbol == ' ')
        {
            continue;
        }
        switch ( lastState ) {
        case start:
            if( symbol.isDigit() )
            {
                buffer.append( symbol );
                lastState = readNumber;
            }
            else if ( symbol == '-' )
            {
                lastState = negativeNumber;
            }
            else if ( symbol.isLetter() )
            {
                buffer.append( symbol );
                lastState = readFunction;
            }
            else if ( Token::isOpenParenthesis(symbol) )
            {
                tokens.enqueue( new OpenParenthesis(parent) );
                lastState = readOpenParenthesis;
            }
            else
            {
                error( ok );
            }
            break;
        case readNumber:
            if( symbol.isDigit() || (symbol == '.') )
            {
                buffer.append( symbol );
            }
            else if( Token::isOperation(symbol) )
            {
                tokens.enqueue( new Number(buffer, parent) );
                buffer.clear();
                tokens.enqueue( new Operation(symbol, parent) );
                lastState = readOperation;
            }
            else if( Token::isOpenParenthesis(symbol) )
            {
                tokens.enqueue( new Number(buffer, parent) );
                buffer.clear();
                tokens.enqueue( new Operation(QString("*"), parent) );
                tokens.enqueue( new OpenParenthesis(parent) );
                lastState = readOpenParenthesis;
            }
            else if( Token::isCloseParenthesis(symbol) )
            {
                tokens.enqueue( new Number(buffer, parent) );
                buffer.clear();
                tokens.enqueue( new CloseParenthesis(parent) );
                lastState = readCloseParenthesis;
            }
            else
            {
                error( ok );
            }
            break;
        case negativeNumber:
            if( symbol.isDigit() )
            {
                buffer.append( "-" );
                buffer.append( symbol );
                lastState = readNumber;
            }
            else
            {
                error( ok );
            }
            break;
        case readOperation:
        {
            if( symbol.isDigit() )
            {
                buffer.append( symbol );
                lastState = readNumber;
            }
            else if ( symbol.isLetter() )
            {
                buffer.append( symbol );
                lastState = readFunction;
            }
            else if( Token::isOpenParenthesis(symbol) )
            {
                tokens.enqueue( new OpenParenthesis(parent) );
                lastState = readOpenParenthesis;
            }
            else
            {
                error( ok );
            }
            break;
        }
        case readFunction:
        {
            if( symbol.isLetterOrNumber() )
            {
                buffer.append( symbol );
            }
            else if( Token::isOpenParenthesis(symbol) )
            {
                tokens.enqueue( FunctionFabric::make(buffer, parent, ok) );
                buffer.clear();
                tokens.enqueue( new OpenParenthesis(parent) );
                lastState = readOpenParenthesis;
            }
            else
            {
                error( ok );
            }
            break;
        }
        case readOpenParenthesis:
            if( symbol.isDigit() )
            {
                buffer.append( symbol );
                lastState = readNumber;
            }
            else if ( symbol == '-' )
            {
                lastState = negativeNumber;
            }
            else if ( symbol.isLetter() )
            {
                buffer.append( symbol );
                lastState = readFunction;
            }
            else if( Token::isOpenParenthesis(symbol) )
            {
                tokens.enqueue( new OpenParenthesis(parent) );
            }
            else
            {
                error( ok );
            }
            break;
        case readCloseParenthesis:
            if( symbol.isDigit() )
            {
                tokens.enqueue( new Operation(QString("*"), parent) );
                buffer.append( symbol );
                lastState = readNumber;
            }
            else if( Token::isOperation(symbol) )
            {
                tokens.enqueue( new Operation(symbol, parent) );
                lastState = readOperation;
            }
            else if ( symbol.isLetter() )
            {
                tokens.enqueue( new Operation(QString("*"), parent) );
                buffer.append( symbol );
                lastState = readFunction;
            }
            else if( Token::isOpenParenthesis(symbol) )
            {
                tokens.enqueue( new Operation(QString("*"), parent) );
                tokens.enqueue( new OpenParenthesis(parent) );
                lastState = readOpenParenthesis;
            }
            else if( Token::isCloseParenthesis(symbol) )
            {
                tokens.enqueue( new CloseParenthesis(parent) );
            }
            else
            {
                error( ok );
            }
            break;
        default:
            error( ok );
            break;
        }
        if( ok && (*ok == false) )
        {
            return;
        }
    }

    if( lastState == readNumber )
    {
        tokens.enqueue( new Number(buffer, parent) );
        buffer.clear();
    }
}
