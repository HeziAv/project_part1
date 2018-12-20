#include <iostream>
#include "Expression.h"
#include "BinaryExpression.h"
#include "Plus.h"
#include "Number.h"
#include "Mul.h"
#include "Div.h"
#include "Neg.h"
#include "Var.h"
#include "Interpeter.h"


int main() {
    std::cout << "Hello, World!" << std::endl;



    Data* data = new Data();

//    string q ="var a = 100";

//    string w = "connect 127.0.0.1 5402";

    string q = "openDataServer 5400 100";


Interpeter* inn = new Interpeter(data);

    list<string> ls;
    ls = inn->lexer(q);
    inn->parser(ls);

//    int i;
//    std::cout << "enter 1" << std::endl;
//    std::cin >> i ;
//    if (i==1){
//
//    ls = inn->lexer(w);
//    inn->parser(ls);
//    }
    std::cout << "Hello, World!" << std::endl;


    while (true){

    }
    return 0;
}


