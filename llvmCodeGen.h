//
// Created by bisan on 8/11/2024.
//

#ifndef COMPI5WOO_LLVMCODEGEN_H
#define COMPI5WOO_LLVMCODEGEN_H

#include <string>
#include "types.h"
#include <vector>
class llvmCodeGen {
public:
    std::vector<WhileLabels*> whiles;
};

void emitNum(Node* n);
void closeMain();
void emitBinop(Node* op1, Node* op2, Node* operation, Node* res);
void checkForOverflow(Node* res);
void emitRelop(Node* op1, Node* op2, Node* operation, Node* res);
void emitLocalVar(Node* var, int offset);
void emitStoreDefault(Node* var, int offset);
void  emitStore(Node* n,int offset);
void emitPhiVal(Node* exp);
void emitEndOfWhile();
void editLabelsOfWhile(Node* exp);
void emitPrepForWhile();
void emitFunctionCall(Node *res,Node *func, Node* args);
void emitString(Node* res);
#endif //COMPI5WOO_LLVMCODEGEN_H
