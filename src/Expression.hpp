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
	Expression(ExType type, IOperand* operand);
	~Expression(void);
};

#endif
