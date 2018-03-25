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
	long long l = std::stoll(value);
	if (l < -128)
		throw abstract::OperandUnderflow();
	if (l > 127)
		throw abstract::OperandOverflow();
	return new Operand<int8_t>(l);
}

const IOperand* IOperand::createInt16(const std::string& value) {
	long long l = std::stoll(value);
	if (l < -32768)
		throw abstract::OperandUnderflow();
	if (l > 32767)
		throw abstract::OperandOverflow();
	return new Operand<int16_t>(l);
}

const IOperand* IOperand::createInt32(const std::string& value) {
	long long l = std::stoll(value);
	if (l < -2147483647)
		throw abstract::OperandUnderflow();
	if (l > 2147483647)
		throw abstract::OperandOverflow();
	return new Operand<int32_t>(l);
}

const IOperand* IOperand::createFloat(const std::string& value) {
	return new Operand<float>(std::stof(value));
}

const IOperand* IOperand::createDouble(const std::string& value) {
	return new Operand<double>(std::stod(value));
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
