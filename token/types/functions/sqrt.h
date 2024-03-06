#ifndef SQRT_H
#define SQRT_H

#include "../function.h"

class Sqrt : public Function
{
public:
    Sqrt(QObject* parent = nullptr);
    double execute(double operand, bool* ok = nullptr) override;
};

#endif // SQRT_H
