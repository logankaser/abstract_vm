#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <string>
#include "IOperand.hpp"

template <class T> class Operand : public IOperand {
	T _value;
public:
	Operand(void);
	Operand(T value);
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

template <class T> Operand<T>::Operand(T value) {_value = value;}

template <class T> const IOperand* Operand<T>::operator+(const IOperand& rhs) {
}

template <class T> const IOperand* Operand<T>::operator-(const IOperand& rhs) {
}

template <class T> const IOperand* Operand<T>::operator*(const IOperand& rhs) {
}

template <class T> const IOperand* Operand<T>::operator/(const IOperand& rhs) {
}

template <class T> const IOperand* Operand<T>::operator%(const IOperand& rhs) {
}

// Specialization

template<> int Operand<int8_t>::getPrecision(void) {return Int8;}
template<> eOperandType Operand<int8_t>::getType(void) {return Int8;}

template<> int Operand<int16_t>::getPrecision(void) {return Int16;}
template<> eOperandType Operand<int16_t>::getType(void) {return Int16;}

template<> int Operand<int32_t>::getPrecision(void) {return Int32;}
template<> eOperandType Operand<int32_t>::getType(void) {return Int32;}

template<> int Operand<float>::getPrecision(void) {return Float;}
template<> eOperandType Operand<float>::getType(void) {return Float;}

template<> int Operand<double>::getPrecision(void) {return Double;}
template<> eOperandType Operand<double>::getType(void) {return Double;}

#endif
