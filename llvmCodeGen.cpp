//
// Created by bisan on 8/11/2024.
//

#include "llvmCodeGen.h"
#include "cg.hpp"
#include "types.h"
#include <iostream>
#include <sstream>

using namespace std;
llvmCodeGen * cg= new llvmCodeGen;


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
        cb.emit(fixedReg + " = trunc i32 " + var->nodereg+ " to i8");
        var->nodereg = fixedReg;
    }
    else if(var->name == "BOOL") {
        string fixedReg =cb.freshVar();
        cb.emit(fixedReg + " = trunc i32 " + var->nodereg+ " to i1");
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
        cb.emit(fixedReg + " = trunc i32 " + n->nodereg+ " to i8");
        n->nodereg = fixedReg;
    }
    else if(n->name == "BOOL") {
        string fixedReg =cb.freshVar();
        cb.emit(fixedReg + " = trunc i32 " + n->nodereg+ " to i1");
        n->nodereg = fixedReg;
    }
    cb.emit("store i32 "+n->nodereg+", i32* " + ptr);
}

void emitPhiVal(Node* exp){
    CodeBuffer &cb=CodeBuffer::instance();
    string phi_label=cb.freshLabel();
    exp->nodereg=cb.freshVar();
    cb.emit(exp->t_label+":");
    cb.emit("br label %"+phi_label);
    cb.emit(exp->f_label+":");
    cb.emit("br label %"+phi_label);
    cb.emit(phi_label+":");
    cb.emit(exp->nodereg+" = phi i32 [ 1, %"+exp->t_label+"], [ 0, %"+exp->f_label+"]");
}

void emitPrepForWhile(){
    CodeBuffer &cb=CodeBuffer::instance();
    string whileLabel=cb.freshLabel();
    WhileLabels* wl= new WhileLabels(whileLabel,"");
    cg->whiles.push_back(wl);
    cb.emit("br label %"+whileLabel);
    cb.emit(whileLabel+":");

}

void emitEndOfWhile(){
    CodeBuffer &cb=CodeBuffer::instance();
    cb.emit("br label %" + cg->whiles.back()->t_label);
    cb.emit(cg->whiles.back()->f_label + ":");
    cg->whiles.pop_back();
}

void editLabelsOfWhile(Node* exp){
    CodeBuffer &cb=CodeBuffer::instance();
    cg->whiles.back()->f_label = exp->f_label;
    cb.emit(exp->t_label + ":");
}

void emitFunctionCall(Node *res,Node *func,Node* args ){
    CodeBuffer &cb=CodeBuffer::instance();
    res->nodereg = cb.freshVar();
    if(func->name == "print"){
        cb.emit(res->nodereg + " = call void @" + func->name + "(i8* " + args->nodereg + ")");
    } else if (func->name == "printi") {
        cb.emit("call void @" + func->value + "(i32 " + args->nodereg + ")");
    } else {
        cb.emit("call i32 @" + func->value + "(i32 " + args->nodereg + ")");
    }
}
void emitString(Node* res){
    CodeBuffer &cb=CodeBuffer::instance();
    res->nodereg=cb.freshVar();
    res->value.erase(0,1);
    res->value.erase(res->value.size()-1,1);
    string strNameInLLVM=cb.freshLabel();
    cb.emitGlobal("@." + strNameInLLVM+ " = constant [" + std::to_string(res->value.size()+1)+ " x i8] c\"" + res->value + "\\00\"");
    cb.emit(res->nodereg + " = getelementptr [" + std::to_string(res->value.size()+1) + " x i8], [" + std::to_string(res->value.size()+1) + " x i8]* @." + strNameInLLVM + ", i32 0, i32 0");
}
