#include <iostream>
#include <fstream>
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


    Data* data = new Data();
    Interpeter* inn = Interpeter::getInstance(data);
    ifstream ifs("data.txt");
    std::string line;
    list<string> ls;
    while (!ifs.eof()){

        ls = inn->lexer(ifs);
        inn->parser(ls);
    }




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

    /*ls = inn->lexer(hezi);
    inn->parser(ls);
    if(data->getFlag() == 1){
        // countinue reading until see "}"
    }*/






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


