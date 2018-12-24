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

    string open = "openDataServer 5400 100";

    string enter = "Enterc";

    string connect = "connect 127.0.0.1 5402";

    string bind = "var rudder = bind /controls/flight/rudder";

    string var = "rudder = 1";

    string print = "print rudder";


Interpeter* inn = new Interpeter(data);

    list<string> ls;
    ls = inn->lexer(open);
    inn->parser(ls);


    ls = inn->lexer(enter);
    inn->parser(ls);


    ls = inn->lexer(connect);
    inn->parser(ls);


    ls = inn->lexer(bind);
    inn->parser(ls);

    ls = inn->lexer(var);
    inn->parser(ls);

//    ls = inn->lexer(print);
//    inn->parser(ls);


    while (true){

    }
    return 0;
}


