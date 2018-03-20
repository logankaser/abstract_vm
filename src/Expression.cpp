#include "Expression.hpp"
#include "IOperand.hpp"

Expression::Expression(void) : type(ExType::exit), operand(NULL) {};
Expression::~Expression(void) {}
Expression::Expression(ExType t, const IOperand* op) : type(t), operand(op) {};

std::ostream& operator<<(std::ostream& os, const Expression* ex) {
	switch (ex->type) {
		case ExType::push:
			return (os << "push: " << ex->operand);
		case ExType::assert:
			return (os << "assert: " << ex->operand);
		case ExType::pop:
			return (os << "pop");
		case ExType::dump:
			return (os << "dump");
		case ExType::add:
			return (os << "add");
		case ExType::sub:
			return (os << "sub");
		case ExType::mul:
			return (os << "mul");
		case ExType::div:
			return (os << "div");
		case ExType::mod:
			return (os << "mod");
		case ExType::print:
			return (os << "print");
		case ExType::exit:
			return (os << "exit");
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const Expression& ex) {
	return os << &ex;
}
