#ifndef RPN_H
#define RPN_H

#include <QQueue>
#include <QStack>
#include "../token/token.h"

void ToRPN(QQueue<Token*>& infix, QQueue<Token*>& rpn , bool* ok = nullptr);

#endif // RPN_H
