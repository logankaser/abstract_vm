#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP
#include "IOperand.hpp"

enum class ExType : int {
	push = 1,
	assert,
	pop,
	dump,
	add,
	sub,
	mul,
	div,
	mod,
	print,
	exit
};

class Expression {
public:
	Expression(void);
	const ExType _type;
	const IOperand* _operand;
	Expression(ExType type, const IOperand* operand);
	~Expression(void);
	friend std::ostream& operator<<(std::ostream& os, const Expression& ex);
	friend std::ostream& operator<<(std::ostream& os, const Expression* ex);
};

#endif
