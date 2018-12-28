//
// Created by gad on 12/19/18.
//

#include "ExpressionCommand.h"

ExpressionCommand ::ExpressionCommand(Command* command) {
    this->command=command;
}


double ExpressionCommand::calculate(Data* data) {
    command->doCommand(data);
    return 2;
}