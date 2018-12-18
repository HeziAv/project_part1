#include <iostream>
#include "Expression.h"
#include "BinaryExpression.h"
#include "Plus.h"
#include "Number.h"
#include "Mul.h"
#include "Div.h"

int main() {
//    Expression hezi = new BinaryExpression(5,7);
    std::cout << "Hello, World!" << std::endl;





    Expression* e= new Plus(new Number(3) , new Mul(new Number(2) , new Number(5)));
    e->calculate();

    return 0;
}


