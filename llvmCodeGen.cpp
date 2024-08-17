//
// Created by bisan on 8/11/2024.
//

#include "llvmCodeGen.h"
#include "cg.hpp"
#include "types.h"
#include <iostream>
#include <sstream>
#include "symbol_table.h"
extern symbolTable *table;

using namespace std;
llvmCodeGen * cg= new llvmCodeGen;


void emitNum(Node* n){
    CodeBuffer &cb=CodeBuffer::instance();
    n->nodereg=cb.freshVar();
    cb.emit(n->nodereg + " = add i32 0, " + n->value);
}


void emitNumB(Node* n){
    CodeBuffer &cb=CodeBuffer::instance();
    n->nodereg=cb.freshVar();
    cb.emit(n->nodereg + " = add i8 0, " + n->value);
}

/*

void emitBool(Node* n){
    CodeBuffer &cb=CodeBuffer::instance();
    n->nodereg=cb.freshVar();
    cb.emit(n->nodereg + " = add i1 0, " + n->value);
}
*/


void checkForOverflow(Node* res){
    CodeBuffer &cb=CodeBuffer::instance();
    string temp=cb.freshVar();
    cb.emit(temp +"= zext i8 "+res->nodereg+" to i32");
    string temp2=cb.freshVar();
    cb.emit(temp2 +"= trunc i32 "+temp+" to i8");
    res->nodereg=temp2;
}

void emitBinop(Node* op1, Node* op2, Node* operation, Node* res){
    string op1Type=op1->name;
    string op2Type=op2->name;
    IDClass *to=dynamic_cast<IDClass*>(op1);
    IDClass *from=dynamic_cast<IDClass*>(op2);
    if(to){
        op1Type=table->getSymbol(op1->name)->type;
    }
    if(from){
        op2Type=table->getSymbol(op2->name)->type;
    }
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
        string tempForCheckingPurposes= op2->nodereg;
       // string llvmop2type;
        if(op2Type=="BYTE"){
             tempForCheckingPurposes=  cb.freshVar();
            cb.emit(tempForCheckingPurposes+" = zext i8 " + op2->nodereg+ " to i32");
        }
       // cb.emit(tempForCheckingPurposes+" = zext "+llvmop2type +" "+ op2->nodereg+ " to i32");
        cb.emit("call void @checkIfDivisionBy0(i32 "+tempForCheckingPurposes+")");
        if(res->name=="INT"){
            operationinllvm="sdiv";

        }
        else{
            operationinllvm="udiv";
        }
    }
    res->nodereg=cb.freshVar();
    if(op1Type == "BYTE" && op2Type== "BYTE"){
        cb.emit(res->nodereg + " = " + operationinllvm + " i8 " + op1->nodereg + ", " + op2->nodereg);
        checkForOverflow(res);
        return;
    }
    else{
        if(op1Type == "BYTE" && op2Type== "INT"){
            string newReg = cb.freshVar();
            cb.emit(newReg+ " = zext i8 " + op1->nodereg+ " to i32");
            cb.emit(res->nodereg + " = " + operationinllvm + " i32 " + newReg + ", " + op2->nodereg);
            return;
        }
        if(op2Type == "BYTE" && op1Type== "INT"){
            string newReg = cb.freshVar();
            cb.emit(newReg+ " = zext i8 " + op2->nodereg+ " to i32");
            cb.emit(res->nodereg + " = " + operationinllvm + " i32 " + op1->nodereg + ", " + newReg);
            return;
        }
        if(op2Type == "INT" && op1Type== "INT"){
            cb.emit(res->nodereg + " = " + operationinllvm + " i32 " + op1->nodereg  + ", " + op2->nodereg);
            return;
        }

    }
}
void closeMain(){
    CodeBuffer &cb=CodeBuffer::instance();
    cb.emit("ret i32 0");
    cb.emit("}");
}

void emitRelop(Node* op1, Node* op2, Node* operation, Node* res){
    CodeBuffer &cb=CodeBuffer::instance();
    string op1Type=op1->name;
    string op2Type=op2->name;
    IDClass *to=dynamic_cast<IDClass*>(op1);
    IDClass *from=dynamic_cast<IDClass*>(op2);
    if(to){
        op1Type=table->getSymbol(op1->name)->type;
    }
    if(from){
        op2Type=table->getSymbol(op2->name)->type;
    }
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
    if(op1Type == "BYTE" && op2Type== "BYTE"){
       // cb.emit(res->nodereg + " = " + operationinllvm + " i8 " + op1->nodereg + ", " + op2->nodereg);
        cb.emit(res->nodereg+"= icmp " +llvmrelop+" i8 "+op1->nodereg+", "+op2->nodereg);
       // checkForOverflow(res);
    }
    else{
        if(op1Type == "BYTE" && op2Type== "INT"){
            string newReg = cb.freshVar();
            cb.emit(newReg+ " = zext i8 " + op1->nodereg+ " to i32");
         //   cb.emit(res->nodereg + " = " + operationinllvm + " i32 " + newReg + ", " + op2->nodereg);
            cb.emit(res->nodereg+"= icmp " +llvmrelop+" i32 "+newReg+", "+op2->nodereg);

        }
        if(op2Type == "BYTE" && op1Type== "INT"){
            string newReg = cb.freshVar();
            cb.emit(newReg+ " = zext i8 " + op2->nodereg+ " to i32");
            cb.emit(res->nodereg+"= icmp " +llvmrelop+" i32 "+op1->nodereg+", "+newReg);

        }
        if(op2Type == "INT" && op1Type== "INT"){
            cb.emit(res->nodereg+"= icmp " +llvmrelop+" i32 "+op1->nodereg+", "+op2->nodereg);
        }

    }

    cb.emit("br i1 "+res->nodereg+", label %"+res->t_label+", label %"+res->f_label);
}
void emitLocalVar(Node* var, int offset){
    string varType=var->name;
    IDClass *to=dynamic_cast<IDClass*>(var);
    if(to){
        varType=table->getSymbol(var->name)->type;
    }
    CodeBuffer &cb=CodeBuffer::instance();
    string ptr=cb.freshVar();
    var->nodereg = cb.freshVar();
    cb.emit(ptr + " = getelementptr i32, i32* %array, i32 " + std::to_string(offset));
    cb.emit(var->nodereg+ " = load i32, i32* " + ptr);
    if(varType == "BYTE") {
        string fixedReg =cb.freshVar();
        cb.emit(fixedReg + " = trunc i32 " + var->nodereg+ " to i8");
        var->nodereg = fixedReg;
    }
    else if(varType == "BOOL") {
        string fixedReg =cb.freshVar();
        cb.emit(fixedReg + " = trunc i32 " + var->nodereg+ " to i1");
        var->nodereg = fixedReg;
    }
}
void emitStoreDefault(Node* var, int offset){
    CodeBuffer &cb=CodeBuffer::instance();
    string ptr=cb.freshVar();
    cb.emit(ptr + " = getelementptr i32, i32* %array, i32 " + std::to_string(offset));
    cb.emit("store i32 0, i32* "+ptr);
}

void  emitStore(Node* n,int offset){
    string varType=n->name;
    IDClass *to=dynamic_cast<IDClass*>(n);
    if(to){
        varType=table->getSymbol(n->name)->type;
    }
    CodeBuffer &cb=CodeBuffer::instance();
    string ptr=cb.freshVar();
    cb.emit(ptr + " = getelementptr i32, i32* %array, i32 " + std::to_string(offset));
    if(varType == "BYTE") {
        string fixedReg =cb.freshVar();
        cb.emit(fixedReg + " = zext i8 " +n->nodereg+ " to i32");
        cb.emit("store i32 "+fixedReg/*n->nodereg*/+", i32* " + ptr);

    }
    else if(varType == "BOOL") {
        string fixedReg =cb.freshVar();
        cb.emit(fixedReg + " = zext i1 " + n->nodereg+ " to i32");
      //  n->nodereg = fixedReg;
        cb.emit("store i32 "+fixedReg/*n->nodereg*/+", i32* " + ptr);
    }
    else{
        cb.emit("store i32 "+n->nodereg+", i32* " + ptr);

    }

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
    cb.emit(exp->nodereg+" = phi i1 [ 1, %"+exp->t_label+"], [ 0, %"+exp->f_label+"]");
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
    string varType=args->name;
    IDClass *to=dynamic_cast<IDClass*>(args);
    if(to){
        varType=table->getSymbol(args->name)->type;
    }
    CodeBuffer &cb=CodeBuffer::instance();
    res->nodereg = cb.freshVar();
    if(func->name == "print"){
        cb.emit("call void @" + func->name + "(i8* " + args->nodereg + ")");
    } else if (func->name == "printi") {
        if(varType == "BYTE") {
            string fixedReg =cb.freshVar();
            cb.emit(fixedReg + " = zext i8 " + args->nodereg+ " to i32");
            cb.emit("call void @" + func->name + "(i32 " + fixedReg + ")");
        }
        else{
            cb.emit("call void @" + func->name + "(i32 " + args->nodereg + ")");
        }

    } else {
        if(varType == "BYTE") {
            string fixedReg =cb.freshVar();
            cb.emit(fixedReg + " = zext i8 " + args->nodereg+ " to i32");
            cb.emit(res->nodereg+" = call i32 @" + func->name + "(i32 " + fixedReg + ")");

        }
        else{
            cb.emit(res->nodereg+"= call i32 @" + func->name + "(i32 " + args->nodereg + ")");
        }
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

void emitPrepForIf(){
    CodeBuffer &cb=CodeBuffer::instance();
    string ifLabel=cb.freshLabel();
    cb.emit("br label %"+ifLabel);
    cb.emit(ifLabel+":");
}


 void emitConversion(string resReg,Node* type ,Node* exp){
    CodeBuffer &cb=CodeBuffer::instance();
   // string llvmConvertFrom="";
    string llvmConvertTo="";
    if(type->name=="BYTE"){
        llvmConvertTo="i8";
     //   cb.emit(resReg+"= trunc i8 "+exp->nodereg+"to i32");
    }
     if(type->name=="INT"){
         llvmConvertTo="i32";
       //  cb.emit(exp->nodereg+"= trunc "+);
     }
     if(type->name=="BOOL"){
         llvmConvertTo="i1";
         //cb.emit(exp->nodereg+"= trunc "+);
     }
     string llvmConvertFrom=exp->name;
   //  cb.emit("exp type "+llvmConvertFrom);
     IDClass *to=dynamic_cast<IDClass*>(exp);
     if(to){
         llvmConvertFrom=table->getSymbol(exp->name)->type;
     }
     if(llvmConvertFrom=="BYTE"){
         llvmConvertFrom="i8";
         //   cb.emit(resReg+"= trunc i8 "+exp->nodereg+"to i32");
     }
     if(llvmConvertFrom=="INT"){
         llvmConvertFrom="i32";
         //  cb.emit(exp->nodereg+"= trunc "+);
     }
     if(llvmConvertFrom=="BOOL"){
         llvmConvertFrom="i1";
         //cb.emit(exp->nodereg+"= trunc "+);
     }
     cb.emit(resReg+"= trunc "+llvmConvertFrom+" "+exp->nodereg+" to "+llvmConvertTo );


 }


void emitPrepForBool(Node* id){
    CodeBuffer &cb=CodeBuffer::instance();
    cb.emit("br i1 "+id->nodereg+", label %"+id->t_label+", label %"+id->f_label);

}