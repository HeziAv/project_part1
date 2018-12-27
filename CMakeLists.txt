cmake_minimum_required(VERSION 3.12)
project(project_part1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(project_part1 main.cpp BinaryExpression.cpp BinaryExpression.h Number.cpp Number.h Expression.h Plus.cpp Plus.h Minus.cpp Minus.h Div.cpp Div.h Mul.cpp Mul.h UnaryExpression.cpp UnaryExpression.h Neg.cpp Neg.h Interpeter.cpp Interpeter.h Var.cpp Var.h Command.h ExpressionCommand.cpp ExpressionCommand.h OpenServerCommand.cpp OpenServerCommand.h ShuntingYard.cpp ShuntingYard.h connectCommand.cpp connectCommand.h Data.cpp Data.h EqualCommand.cpp EqualCommand.h PrintCommand.cpp PrintCommand.h EnterCCommand.h EnterCCommand.cpp ifCommand.cpp ifCommand.h ConditionCommand.cpp ConditionCommand.h WhileCommand.cpp WhileCommand.h SleepCommand.cpp SleepCommand.h Variable.cpp Variable.h varCommand.cpp varCommand.h)