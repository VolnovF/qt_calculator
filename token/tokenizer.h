#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <QQueue>
#include "types/number.h"
#include "types/operation.h"
#include "types/functionfabric.h"
#include "types/openparenthesis.h"
#include "types/closeparenthesis.h"

void Tokenize(const QString& expression, QQueue<Token*>& tokens, QObject* parent = nullptr, bool* ok = nullptr);

#endif // TOKENIZER_H
