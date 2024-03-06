#include "functionfabric.h"

Function *FunctionFabric::make(QString str, QObject* parent, bool* ok)
{
    if (str == "sin")
    {
        return new Sin(parent);
    }
    else if (str == "cos")
    {
        return new Cos(parent);
    }
    else if (str == "tan")
    {
        return new Tan(parent);
    }
    else if (str == "sqrt")
    {
        return new Sqrt(parent);
    }
    else if (str == "abs")
    {
        return new Abs(parent);
    }
    else
    {
        if(ok){*ok = false;}
        return nullptr;
    }
}
