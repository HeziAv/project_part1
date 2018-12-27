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



int main(int argc, char *argv[]) {
    Data *data = new Data();
    Interpeter *inn = Interpeter::getInstance(data);
    ifstream ourFile;
    list<string> ls;
    string buffer = "";
    ifstream ifs(argv[1]);
    if (!ifs) {
        throw "Failed Opening File";
    }
    // read each line in the file and build the flight
    while (!ifs.eof()) {
        ls = inn->lexer(ifs);
        inn->parser(ls);
    }
    inn->exit(data);
    ifs.close();
    return 0;
}
