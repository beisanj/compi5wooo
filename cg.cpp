#include "cg.hpp"
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

CodeBuffer::CodeBuffer() : buffer(), globalDefs() {


}


void emitInitial(){
    CodeBuffer& cb=CodeBuffer::instance();
    cb.emit("declare void @exit(i32)");
    cb.emit("declare i32 @printf(i8*, ...)");
    cb.emit("declare i32 @scanf(i8*, ...)");
    cb.emit("@.int_specifier_scan = constant [3 x i8] c\"%d\\00\"");
    cb.emit("@.int_specifier = constant [4 x i8] c\"%d\\0A\\00\"");
    cb.emit("@.str_specifier = constant [4 x i8] c\"%s\\0A\\00\"");
    cb.emit("define i32 @readi(i32) {");
    cb.emit("    %ret_val = alloca i32");
    cb.emit("    %spec_ptr = getelementptr [3 x i8], [3 x i8]* @.int_specifier_scan, i32 0, i32 0");
    cb.emit("    call i32 (i8*, ...) @scanf(i8* %spec_ptr, i32* %ret_val)");
    cb.emit("    %val = load i32, i32* %ret_val");
    cb.emit("    ret i32 %val");
    cb.emit("}");
    cb.emit("define void @printi(i32) {");
    cb.emit("    %spec_ptr = getelementptr [4 x i8], [4 x i8]* @.int_specifier, i32 0, i32 0");
    cb.emit("    call i32 (i8*, ...) @printf(i8* %spec_ptr, i32 %0)");
    cb.emit("    ret void");
    cb.emit("}");
    cb.emit("define void @print(i8*) {");
    cb.emit("    %spec_ptr = getelementptr [4 x i8], [4 x i8]* @.str_specifier, i32 0, i32 0");
    cb.emit("    call i32 (i8*, ...) @printf(i8* %spec_ptr, i8* %0)");
    cb.emit("    ret void");
    cb.emit("}");
    cb.emit("@.MessageDivError = constant[23 x i8] c\"Error division by zero\\00\"");
    cb.emit("define void @checkIfDivisionBy0(i32) {");
    string resOfComp= cb.freshVar();
    cb.emit(resOfComp+"= icmp eq i32 %0,0");
    cb.emit("br i1 "+resOfComp+",label %zeroLabel,label %notZero");
    cb.emit("zeroLabel:");
    string argument=cb.freshVar();
    cb.emit(argument+"= getelementptr [23 x i8], [23 x i8]* @.MessageDivError, i32 0, i32 0");
    cb.emit("call void @print(i8* "+argument+")");
    cb.emit("call void @exit(i32 0)");
    cb.emit("ret void");
    cb.emit("notZero:");
    cb.emit("ret void");
    cb.emit("}");
    cb.emit("define i32 @main() {");
    string arrSize=cb.freshVar();
    cb.emit(arrSize+"= add i32 50,0");
    string array= cb.freshVar();
    cb.emit(array+"= alloca i32, i32 "+arrSize);
}


CodeBuffer &CodeBuffer::instance() {
	static CodeBuffer inst;//only instance
	return inst;
}

string CodeBuffer::freshLabel(){
	std::stringstream label;
	label << "label_" << ++labels_num;
	return label.str();
}
string CodeBuffer::freshVar(){
    std::stringstream var;
    var << "%t" << ++curReg;
    return var.str();
}

int CodeBuffer::emit(const string &s){
    buffer.push_back(s);
	return buffer.size() - 1;
}

void CodeBuffer::printCodeBuffer(){
	for (std::vector<string>::const_iterator it = buffer.begin(); it != buffer.end(); ++it) 
	{
		cout << *it << endl;
    }
}

// ******** Methods to handle the global section ********** //
void CodeBuffer::emitGlobal(const std::string& dataLine) 
{
	globalDefs.push_back(dataLine);


}

void CodeBuffer::printGlobalBuffer()
{
	for (vector<string>::const_iterator it = globalDefs.begin(); it != globalDefs.end(); ++it)
	{
		cout << *it << endl;
	}
}
