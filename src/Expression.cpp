#include "Expression.hpp"
#include "IOperand.hpp"

Expression::Expression(void) : _type(ExType::exit), _operand(NULL) {};
Expression::~Expression(void) {}
Expression::Expression(ExType t, IOperand* op) : _type(t), _operand(op) {};
