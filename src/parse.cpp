#include "IOperand.hpp"
#include "Exceptions.hpp"
#include "abstract.hpp"

namespace parse {

void	push(std::vector<const IOperand*>& stack, const Expression* ex) {
	stack.push_back(ex->operand);
}


void	assert(std::vector<const IOperand*>& stack, const Expression* ex) {
	if (*ex->operand != stack.back())
		throw abstract::AssertFailed();
}

void	pop(std::vector<const IOperand*>& stack) {
	if (stack.empty())
		throw abstract::PopOnEmpty();
	stack.pop_back();
}


void	dump(std::vector<const IOperand*>& stack) {
	if (!stack.empty())
		for (const IOperand* op : stack) {
			std::cout << op << std::endl;
		}
}

void	print(std::vector<const IOperand*>& stack) {
	if (stack.empty())
		throw abstract::TooFewOperands();
	if (stack.back()->getType() != eOperandType::Int8)
		throw abstract::AssertFailed();
	std:: cout << static_cast<char>(std::stoi(stack.back()->toString()));
}

void	add(std::vector<const IOperand*>& stack) {
	if (stack.size() < 2)
		throw abstract::TooFewOperands();
	const IOperand& r = *stack.back();
	stack.pop_back();
	const IOperand& l = *stack.back();
	stack.pop_back();
	stack.push_back(l + r);
}

void	sub(std::vector<const IOperand*>& stack) {
	if (stack.size() < 2)
		throw abstract::TooFewOperands();
	const IOperand& r = *stack.back();
	stack.pop_back();
	const IOperand& l = *stack.back();
	stack.pop_back();
	stack.push_back(l - r);
}


void	mul(std::vector<const IOperand*>& stack) {
	if (stack.size() < 2)
		throw abstract::TooFewOperands();
	const IOperand& r = *stack.back();
	stack.pop_back();
	const IOperand& l = *stack.back();
	stack.pop_back();
	stack.push_back(l * r);
}


void	div(std::vector<const IOperand*>& stack) {
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


void	mod(std::vector<const IOperand*>& stack) {
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

void	loop(std::vector<const IOperand*>& stack, const Expression* ex, unsigned* ins) {
	if (std::stod(stack.back()->toString()) > 0.0) {
		*ins = std::stoi(ex->operand->toString()) - 2;
	}
}

}
