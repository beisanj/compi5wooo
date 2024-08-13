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

        if(op1->name =="INT" || op2->name=="INT")
           llvmrelop="sgt";
        else{
            llvmrelop="ugt";
        }
    }
    if(operation->name=="<"){
        if(op1->name =="INT" || op2->name=="INT")
            llvmrelop="slt";
        else{
            llvmrelop="ult";
        }
    }
    if(operation->name==">="){
        if(op1->name =="INT" || op2->name=="INT")
            llvmrelop="sge";
        else{
            llvmrelop="uge";
        }
    }
    if(operation->name=="<="){
        if(op1->name =="INT" || op2->name=="INT")
            llvmrelop="sle";
        else{
            llvmrelop="ule";
        }
    }
    cb.emit(res->nodereg+"= icmp " +llvmrelop+" i32 "+op1->nodereg+", "+op2->nodereg);
    cb.emit("br i1 "+res->nodereg+", label "+res->t_label+", label "+res->f_label);
}
void emitLocalVar(Node* var, int offset){
    CodeBuffer &cb=CodeBuffer::instance();
    string ptr=cb.freshVar();
    var->nodereg = cb.freshVar();
    cb.emit(ptr + " = getelementptr i32, i32* %array, i32 " + std::to_string(offset));
    cb.emit(var->nodereg+ " = load i32, i32* " + ptr);
    if(var->name == "BYTE") {
        string fixedReg =cb.freshVar();
        cb.emit(fixedReg + " = trunc i32 " + ptr+ " to i8");
        var->nodereg = fixedReg;
    }
    else if(var->name == "BOOL") {
        string fixedReg =cb.freshVar();
        cb.emit(fixedReg + " = trunc i32 " + ptr+ " to i1");
        var->nodereg = fixedReg;
    }
}
void emitStoreDefault(Node* var, int offset){
    CodeBuffer &cb=CodeBuffer::instance();
    string ptr=cb.freshVar();
    cb.emit(ptr + " = getelementptr i32, i32* %array, i32 " + std::to_string(offset));
    cb.emit("store i32 0, i32* %ptr");
}

void  emitStore(Node* n,int offset){
    CodeBuffer &cb=CodeBuffer::instance();
    string ptr=cb.freshVar();
    cb.emit(ptr + " = getelementptr i32, i32* %array, i32 " + std::to_string(offset));
    if(n->name == "BYTE") {
        string fixedReg =cb.freshVar();
        cb.emit(fixedReg + " = trunc i32 " + ptr+ " to i8");
        n->nodereg = fixedReg;
    }
    else if(n->name == "BOOL") {
        string fixedReg =cb.freshVar();
        cb.emit(fixedReg + " = trunc i32 " + ptr+ " to i1");
        n->nodereg = fixedReg;
    }
    cb.emit("store i32"+n->nodereg+", i32* " + ptr);
}