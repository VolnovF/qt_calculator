#ifndef EXECUTERPN_H
#define EXECUTERPN_H

#include <QQueue>
#include <QStack>
#include "../token/token.h"

double executeRPN(QQueue<Token*>& rpn, bool* ok = nullptr);

#endif // EXECUTERPN_H
