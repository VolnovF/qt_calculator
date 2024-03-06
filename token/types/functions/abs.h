#ifndef ABS_H
#define ABS_H

#include "../function.h"

class Abs : public Function
{
public:
    Abs(QObject* parent = nullptr);
    double execute(double operand, bool* ok = nullptr) override;
};

#endif // ABS_H
