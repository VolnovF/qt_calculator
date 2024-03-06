#ifndef SIN_H
#define SIN_H

#include "../function.h"

class Sin : public Function
{
public:
    Sin(QObject* parent = nullptr);
    double execute(double operand, bool* ok = nullptr) override;
};

#endif // SIN_H
