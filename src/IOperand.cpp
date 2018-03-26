/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:02:25 by lkaser            #+#    #+#             */
/*   Updated: 2018/03/13 10:02:27 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IOperand.hpp"
#include "Operand.hpp"
#include "Exceptions.hpp"

const IOperand* IOperand::createOperand(eOperandType type, const std::string& value) {
	static const IOperand* (*dispatch[])(const std::string& value) = {
		&IOperand::createInt8,
		&IOperand::createInt16,
		&IOperand::createInt32,
		&IOperand::createFloat,
		&IOperand::createDouble
	};
	return (dispatch[(int)type - 1])(value);
}

const IOperand* IOperand::createInt8(const std::string& value) {
	int i = 0;
	try {
		i = std::stoi(value);
	}
	catch(const std::exception& e) {
		i = value[0] == '-' ? -128 : 128;
	}
	if (i < -127)
		throw abstract::OperandUnderflow();
	if (i > 127)
		throw abstract::OperandOverflow();
	return new Operand<int8_t>(i);
}

const IOperand* IOperand::createInt16(const std::string& value) {
	long l = 0;
	try {
		l = std::stol(value);
	}
	catch(const std::exception& e) {
		l = value[0] == '-' ? -32768 : 32768;
	}
	if (l < -32767)
		throw abstract::OperandUnderflow();
	if (l > 32767)
		throw abstract::OperandOverflow();
	return new Operand<int16_t>(l);
}

const IOperand* IOperand::createInt32(const std::string& value) {
	long long l = 0;
	try {
		l = std::stoll(value);
	}
	catch(const std::exception& e) {
		l = value[0] == '-' ? -2147483648 : 2147483648;
	}
	if (l < -2147483647)
		throw abstract::OperandUnderflow();
	if (l > 2147483647)
		throw abstract::OperandOverflow();
	return new Operand<int32_t>(l);
}

const IOperand* IOperand::createFloat(const std::string& value) {
	float f = 0.0f;
	try {
		f = std::stof(value);
	}
	catch(const std::exception& e) {
		if (value[0] == '-')
			throw abstract::OperandUnderflow();
		throw abstract::OperandOverflow();
	}
	return new Operand<float>(f);
}

const IOperand* IOperand::createDouble(const std::string& value) {
	double d = 0.0;
	try {
		d = std::stod(value);
	}
	catch(const std::exception& e) {
		if (value[0] == '-')
			throw abstract::OperandUnderflow();
		throw abstract::OperandOverflow();
	}
	return new Operand<double>(d);
}

std::ostream& operator<<(std::ostream& os, const IOperand& op) {
	return (os << op.toString());
}

std::ostream& operator<<(std::ostream& os, const IOperand* op) {
	return (os << op->toString());
}

std::ostream& operator<<(std::ostream& os, eOperandType type) {
	switch (type) {
		case eOperandType::Int8:
			return (os << "Int8");
		case eOperandType::Int16:
			return (os << "Int16");
		case eOperandType::Int32:
			return (os << "Int32");
		case eOperandType::Float:
			return (os << "Float");
		case eOperandType::Double:
			return (os << "Double");
	}
	return os;
}
