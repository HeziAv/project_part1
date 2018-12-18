#include <iostream>
#include "Expression.h"
#include "BinaryExpression.h"
#include "Plus.h"
#include "Number.h"
#include "Mul.h"
#include "Div.h"
#include "Neg.h"
#include "Var.h"


int main() {
//    Expression hezi = new BinaryExpression(5,7);
    std::cout << "Hello, World!" << std::endl;




    Expression* e=new Neg(new Plus(new Var("x") , new Mul( new Div(new Number(4), new Number(2)) , new Number(5))));

    double a=0;


    map <string, double> mp;

    mp.insert({"x",3});


    a = e->calculate(mp);
    std::cout << a << std::endl;


    return 0;
}


