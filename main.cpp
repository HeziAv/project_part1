#include <iostream>
#include <unistd.h>
#include "Expression.h"
#include "BinaryExpression.h"
#include "Plus.h"
#include "Number.h"
#include "Mul.h"
#include "Div.h"
#include "Neg.h"
#include "Var.h"
#include "Interpeter.h"

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
using namespace std;
#include <string.h>

int main() {
    std::cout << "Hello, World!" << std::endl;



    Data* data = new Data();

//    string z = "var rudder = bind /controls/flight/rudder";
//
//    string w = "connect 127.0.0.1 5402";
//
//    string q = "openDataServer 5400 100";
//
//    string zz = "rudder = 1";

    string hezi = "if x<=7 {";


Interpeter* inn = new Interpeter(data);

    list<string> ls;
//    ls = inn->lexer(q);
//    inn->parser(ls);
//
//    int i;
//    std::cout << "enter 1" << std::endl;
//    std::cin >> i ;
//    if (i==1){
//
//    ls = inn->lexer(w);
//    inn->parser(ls);
//    }
//    std::cout << "enter the var" << std::endl;
//    ls = inn->lexer(z);
//    inn->parser(ls);

//    ls = inn->lexer(zz);
//    inn->parser(ls);

    ls = inn->lexer(hezi);
    inn->parser(ls);






//    std::cout << "enter 1" << std::endl;
//    std::cin >> i ;
//    if (i==1){
//        string buffer = "set controls/flight/rudder -1";
//        int len = buffer.length();
//
//    }

    while (true){

    }
    return 0;
}


