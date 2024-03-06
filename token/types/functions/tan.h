#ifndef TAN_H
#define TAN_H

#include "../function.h"

class Tan : public Function
{
public:
    Tan(QObject* parent = nullptr);
    double execute(double operand, bool* ok = nullptr) override;
};

#endif // TAN_H
