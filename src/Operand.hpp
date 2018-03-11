#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <string>
#include "IOperand.hpp"

template <class T> class Operand : public IOperand {
protected:
	T _value;
public:
	Operand(void);
	Operand(T value);
	Operand(const Operand& obj);
	~Operand(void);
	int getPrecision(void) const;
	eOperandType getType(void) const;
	const IOperand* operator+(const IOperand &rhs) const;
	const IOperand* operator-(const IOperand &rhs) const;
	const IOperand* operator*(const IOperand &rhs) const;
	const IOperand* operator/(const IOperand &rhs) const;
	const IOperand* operator%(const IOperand &rhs) const;
	const std::string& toString(void) const;
};

template <class T> Operand<T>::Operand(T value) {_value = value;}

template <class T> const IOperand* Operand<T>::operator+(const IOperand& rhs) const {
	if (this->getPrecision() < rhs.getPrecision()) {
		return rhs + *this; // Make sure higher precision type is the result;
	}
	T value = _value;
	T rhs_value = std::stod(rhs.toString());
	// check for overflows
	return IOperand::createOperand(this->getType(), std::to_string(value + rhs_value));
}

template <class T> const IOperand* Operand<T>::operator-(const IOperand& rhs) const {
}

template <class T> const IOperand* Operand<T>::operator*(const IOperand& rhs) const {
}

template <class T> const IOperand* Operand<T>::operator/(const IOperand& rhs) const {
}

template <class T> const IOperand* Operand<T>::operator%(const IOperand& rhs) const {
}

// Specialization

template<> int Operand<int8_t>::getPrecision(void) const {return Int8;}
template<> eOperandType Operand<int8_t>::getType(void) const {return Int8;}

template<> int Operand<int16_t>::getPrecision(void) const {return Int16;}
template<> eOperandType Operand<int16_t>::getType(void) const {return Int16;}

template<> int Operand<int32_t>::getPrecision(void) const {return Int32;}
template<> eOperandType Operand<int32_t>::getType(void) const {return Int32;}

template<> int Operand<float>::getPrecision(void) const {return Float;}
template<> eOperandType Operand<float>::getType(void) const {return Float;}

template<> int Operand<double>::getPrecision(void) const {return Double;}
template<> eOperandType Operand<double>::getType(void) const {return Double;}

#endif
