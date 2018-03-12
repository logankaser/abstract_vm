#include "IOperand.hpp"
#include "Operand.hpp"
#include <iostream>

int	main(void) {
	std::cout << "test" << std::endl;
	const IOperand* op = IOperand::createOperand(Float, "0.2");
	const IOperand* op2 = IOperand::createOperand(Float, "0.2");
	std::cout << (*op + *op2) << std::endl;
	return (0);
}
