#include "IOperand.hpp"
#include "Operand.hpp"
#include <iostream>

int	main(void) {
	const IOperand* op = IOperand::createOperand(eOperandType::Int8, "5");
	const IOperand* op2 = IOperand::createOperand(eOperandType::Float, "0.2");
	const IOperand* result = *op2 + *op;
	std::cout << result->getType() << std::endl;
	std::cout << result << std::endl;
	return (0);
}
