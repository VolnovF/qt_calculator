#ifndef FUNCTIONFABRIC_H
#define FUNCTIONFABRIC_H

#include "functions/sin.h"
#include "functions/cos.h"
#include "functions/tan.h"
#include "functions/sqrt.h"
#include "functions/abs.h"

class FunctionFabric
{
public:
    static Function* make(QString str, QObject* parent = nullptr, bool* ok = nullptr);
};

#endif // FUNCTIONFABRIC_H
