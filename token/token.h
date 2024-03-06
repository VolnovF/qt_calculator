#ifndef TOKEN_H
#define TOKEN_H

#include <QString>
#include <QObject>

class Token : public QObject
{
    Q_OBJECT
public:
    enum class Type{
        number,
        operation,
        function,
        openParenthesis,
        closeParenthesis,
        maxTypes
    };

private:
    QString str;

public:
    Token(QObject* parent = nullptr);
    Token(QString c_str, QObject* parent = nullptr);

    const QString& getStr();
    virtual Token::Type getType();
    virtual int getPriority(bool* ok = nullptr);
    virtual double execute(double leftOperand, double rightOperand, bool* ok = nullptr);
    virtual double execute(double operand, bool* ok = nullptr);

    static bool isOperation(const QChar& symbol);
    static bool isOpenParenthesis(const QChar& symbol);
    static bool isCloseParenthesis(const QChar& symbol);

    virtual ~Token() {}
};

#endif // TOKEN_H
