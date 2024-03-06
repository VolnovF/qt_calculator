#ifndef COS_H
#define COS_H

#include "../function.h"

class Cos : public Function
{
public:
    Cos(QObject* parent = nullptr);
    double execute(double operand, bool* ok = nullptr) override;
};

#endif // COS_H
