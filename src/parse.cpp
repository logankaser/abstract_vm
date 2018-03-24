#include "IOperand.hpp"
#include "Exceptions.hpp"
#include "abstract.hpp"

void	parse::push(const Expression* ex, std::vector<const IOperand*>& stack) {
	stack.push_back(ex->operand);
}


void	parse::assert(const Expression* ex, std::vector<const IOperand*>& stack) {
	if (*ex->operand != stack.back())
		throw abstract::AssertFailed();
}

void	parse::pop(std::vector<const IOperand*>& stack) {
	if (stack.empty())
		throw abstract::PopOnEmpty();
	stack.pop_back();
}


void	parse::dump(std::vector<const IOperand*>& stack) {
	if (!stack.empty())
		for (const IOperand* op : stack) {
			std::cout << op << std::endl;
		}
}

void	parse::print(std::vector<const IOperand*>& stack) {
	if (stack.empty())
		throw abstract::TooFewOperands();
	if (stack.back()->getType() != eOperandType::Int8)
		throw abstract::AssertFailed();
	std:: cout << static_cast<char>(std::stoi(stack.back()->toString()));
}

void	parse::add(std::vector<const IOperand*>& stack) {
	if (stack.size() < 2)
		throw abstract::TooFewOperands();
	const IOperand& r = *stack.back();
	stack.pop_back();
	const IOperand& l = *stack.back();
	stack.pop_back();
	stack.push_back(l + r);
}

void	parse::sub(std::vector<const IOperand*>& stack) {
	if (stack.size() < 2)
		throw abstract::TooFewOperands();
	const IOperand& r = *stack.back();
	stack.pop_back();
	const IOperand& l = *stack.back();
	stack.pop_back();
	stack.push_back(l - r);
}


void	parse::mul(std::vector<const IOperand*>& stack) {
	if (stack.size() < 2)
		throw abstract::TooFewOperands();
	const IOperand& r = *stack.back();
	stack.pop_back();
	const IOperand& l = *stack.back();
	stack.pop_back();
	stack.push_back(l * r);
}


void	parse::div(std::vector<const IOperand*>& stack) {
	if (stack.size() < 2)
		throw abstract::TooFewOperands();
	const IOperand& r = *stack.back();
	stack.pop_back();
	if (r.toString() == "0")
		throw abstract::DivisionByZero();
	const IOperand& l = *stack.back();
	stack.pop_back();
	stack.push_back(l / r);
}


void	parse::mod(std::vector<const IOperand*>& stack) {
	if (stack.size() < 2)
		throw abstract::TooFewOperands();
	const IOperand& r = *stack.back();
	stack.pop_back();
	if (r.toString() == "0")
		throw abstract::DivisionByZero();
	const IOperand& l = *stack.back();
	stack.pop_back();
	stack.push_back(l % r);
}
