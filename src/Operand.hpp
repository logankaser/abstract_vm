/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:02:43 by lkaser            #+#    #+#             */
/*   Updated: 2018/03/13 10:02:45 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <string>
#include <math.h>
#include "IOperand.hpp"

#define OPERATE_PRECISION(OP) \
if (getPrecision() < rhs.getPrecision()) {\
	return rhs OP *this;\
}\
double rhs_value = std::stod(rhs.toString());\

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
	bool operator==(const IOperand* rhs) const;
	bool operator!=(const IOperand* rhs) const;
};

template<class T> const IOperand* Operand<T>::operator+(const IOperand& rhs) const {
	OPERATE_PRECISION(+)
	return IOperand::createOperand(this->getType(), std::to_string(_value + rhs_value));
}


template<class T> const IOperand* Operand<T>::operator-(const IOperand& rhs) const {
	OPERATE_PRECISION(-)
	return IOperand::createOperand(this->getType(), std::to_string(_value - rhs_value));
}

template<class T> const IOperand* Operand<T>::operator*(const IOperand& rhs) const {
	OPERATE_PRECISION(*)
	return IOperand::createOperand(this->getType(), std::to_string(_value * rhs_value));
}

template<class T> const IOperand* Operand<T>::operator/(const IOperand& rhs) const {
	OPERATE_PRECISION(/)
	return IOperand::createOperand(this->getType(), std::to_string(_value / rhs_value));
}

template<class T> const IOperand* Operand<T>::operator%(const IOperand& rhs) const {
	OPERATE_PRECISION(%)
	return IOperand::createOperand(this->getType(), std::to_string(fmod(_value, rhs_value)));
}

template<class T> bool Operand<T>::operator==(const IOperand* rhs) const {
	if ((int)getType() != (int)rhs->getType())
		return false;
	if (rhs->getType() == eOperandType::Float)
		return _value == std::stof(rhs->toString());
	return _value == std::stod(rhs->toString());
}

template<class T> bool Operand<T>::operator!=(const IOperand* rhs) const {
	return !this->operator==(rhs);
}

#endif
