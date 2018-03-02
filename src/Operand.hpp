#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <string>
#include "IOperand.hpp"

template <class T> class Operand {
	T _value;
public:
	Operand(void);
	Operand(T value);
	Operand(std::string str);
	Operand(const Operand& obj);
	~Operand(void);
	int getPrecision(void);
	eOperandType getType(void);
	const IOperand* operator+(const IOperand &rhs);
	const IOperand* operator-(const IOperand &rhs);
	const IOperand* operator*(const IOperand &rhs);
	const IOperand* operator/(const IOperand &rhs);
	const IOperand* operator%(const IOperand &rhs);
	const std::string& toString(void);
};

#endif
