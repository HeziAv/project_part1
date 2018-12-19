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

    string q = "openDataServer 5400 100";

    Interpeter* inn = new Interpeter();

    list<string> ls;
    ls = inn->lexer(q);

    inn->parser(ls);

//    list<string>::iterator it;
//    for (it = ls.begin();it != ls.end();++it) {
//        cout << *it << '\n';
//    }



    //Expression* e=new Neg(new Plus(new Var("x") , new Mul( new Div(new Number(4), new Number(2)) , new Number(5))));

//    double a=0;
//
//
//    map <string, double> mp;
//
//    mp.insert({"x",3});
//
//
//    a = e->calculate(mp);
//    std::cout << a << std::endl;




    return 0;
}


