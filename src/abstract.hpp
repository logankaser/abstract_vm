#ifndef ABSTRACT_HPP
#define ABSTRACT_HPP

#include <vector>
#include "Expression.hpp"

#define C_RED "\x1b[31m"
#define C_GREEN "\x1b[32m"
#define C_CYAN "\x1B[36m"
#define C_RESET "\x1b[0m"

std::vector<const Expression*> lex(const char* filename);

namespace parse {
	void 	push(std::vector<const IOperand*>& stack, const Expression* ex);
	void 	assert(std::vector<const IOperand*>& stack, const Expression* ex);
	void 	pop(std::vector<const IOperand*>& stack);
	void 	dump(std::vector<const IOperand*>& stack);
	void	print(std::vector<const IOperand*>& stack);
	void	add(std::vector<const IOperand*>& stack);
	void	sub(std::vector<const IOperand*>& stack);
	void	mul(std::vector<const IOperand*>& stack);
	void	div(std::vector<const IOperand*>& stack);
	void	mod(std::vector<const IOperand*>& stack);
	void	loop(std::vector<const IOperand*>& stack, const Expression* ex, unsigned* ins);
}

#endif
