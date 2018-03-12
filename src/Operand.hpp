#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <string>
#include <math.h>
#include "IOperand.hpp"

#define ORDER_PRECISION \
if (this->getPrecision() < rhs.getPrecision()) { \
	return rhs + *this; \
}

template <class T> class Operand : public IOperand {
	T _value;
	std::string _str;
public:
	Operand(void) : _value(0), _str("0") {};
	Operand(T v) : _value(v), _str(std::to_string(v)) {};
	const std::string& toString(void) const {return _str;}
	Operand(const Operand& obj);
	~Operand(void) {};
	int getPrecision(void) const;
	eOperandType getType(void) const;
	const IOperand* operator+(const IOperand& rhs) const;
	const IOperand* operator-(const IOperand& rhs) const;
	const IOperand* operator*(const IOperand& rhs) const;
	const IOperand* operator/(const IOperand& rhs) const;
	const IOperand* operator%(const IOperand& rhs) const;
};

template<class T> const IOperand* Operand<T>::operator+(const IOperand& rhs) const {
	ORDER_PRECISION
	T value = _value;
	T rhs_value = std::stod(rhs.toString());
	return IOperand::createOperand(this->getType(), std::to_string(value + rhs_value));
}

template<class T> const IOperand* Operand<T>::operator-(const IOperand& rhs) const {
	ORDER_PRECISION
	T value = _value;
	T rhs_value = std::stod(rhs.toString());
	return IOperand::createOperand(this->getType(), std::to_string(value - rhs_value));
}

template<class T> const IOperand* Operand<T>::operator*(const IOperand& rhs) const {
	ORDER_PRECISION
	T value = _value;
	T rhs_value = std::stod(rhs.toString());
	return IOperand::createOperand(this->getType(), std::to_string(value * rhs_value));
}

template<class T> const IOperand* Operand<T>::operator/(const IOperand& rhs) const {
	ORDER_PRECISION
	T value = _value;
	T rhs_value = std::stod(rhs.toString());
	return IOperand::createOperand(this->getType(), std::to_string(value / rhs_value));
}

template<class T> const IOperand* Operand<T>::operator%(const IOperand& rhs) const {
	ORDER_PRECISION
	T value = _value;
	T rhs_value = std::stod(rhs.toString());
	return IOperand::createOperand(this->getType(), std::to_string(fmod(value, rhs_value)));
}

#endif
