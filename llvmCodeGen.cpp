//
// Created by bisan on 8/11/2024.
//

#include "llvmCodeGen.h"
#include "cg.hpp"
#include "types.h"
#include <iostream>
#include <sstream>

using namespace std;

void emitNum(Node* n){
    CodeBuffer &cb=CodeBuffer::instance();
    n->nodereg=cb.freshVar();
    cb.emit(n->nodereg + " = add i32 0, " + n->value);
}


void checkForOverflow(Node* res){
    CodeBuffer &cb=CodeBuffer::instance();
    string temp=cb.freshVar();
    cb.emit(temp +"= zext i8"+res->nodereg+" to i32");
    res->nodereg=temp;
}

void emitBinop(Node* op1, Node* op2, Node* operation, Node* res){
    CodeBuffer &cb=CodeBuffer::instance();
    string operationinllvm="";
    if(operation->name=="+"){
        operationinllvm="add";
    }
    if(operation->name=="-"){
        operationinllvm="sub";
    }
    if(operation->name=="*"){
        operationinllvm="mul";
    }
    if(operation->name=="/"){
        cb.emit("call void @checkIfDivisionBy0(i32 "+op2->nodereg+")");
        if(res->name=="INT"){
            operationinllvm="sdiv";

        }
        else{
            operationinllvm="udiv";
        }
    }
    res->nodereg=cb.freshVar();
    cb.emit(res->nodereg + " = " + operationinllvm + " i32 " + op1->nodereg + ", " + op2->nodereg);
    if(res->name=="BYTE"){
        checkForOverflow(res);
    }
}
void closeMain(){
    CodeBuffer &cb=CodeBuffer::instance();
    cb.emit("ret i32 0");
    cb.emit("}");
}

void emitRelop(Node* op1, Node* op2, Node* operation, Node* res){
    CodeBuffer &cb=CodeBuffer::instance();
    string llvmrelop;
    string opsize;
    if(operation->name=="=="){
        llvmrelop="eq";
    }
    if(operation->name=="!="){
        llvmrelop="ne";
    }
    if(operation->name==">"){
        if(res->name=="INT")
           llvmrelop="sgt";
        else{
            llvmrelop="ugt";
        }
    }
    if(operation->name=="<"){
        if(res->name=="INT")
            llvmrelop="slt";
        else{
            llvmrelop="ult";
        }
    }
    if(operation->name==">="){
        if(res->name=="INT")
            llvmrelop="sge";
        else{
            llvmrelop="uge";
        }
    }
    if(operation->name=="<="){
        if(res->name=="INT")
            llvmrelop="sle";
        else{
            llvmrelop="ule";
        }
    }
    cb.emit(res->nodereg+"= icmp " +llvmrelop+"i32 "+op1->nodereg+", "+op2->nodereg);

}
