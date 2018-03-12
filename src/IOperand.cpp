#include "IOperand.hpp"
#include "Operand.hpp"

const IOperand* IOperand::createOperand(eOperandType type, const std::string& value) {
	static const IOperand* (*dispatch[])(const std::string& value) = {
		&IOperand::createInt8,
		&IOperand::createInt16,
		&IOperand::createInt32,
		&IOperand::createFloat,
		&IOperand::createDouble
	};
	return (dispatch[type - 1])(value);
}

const IOperand* IOperand::createInt8(const std::string& value) {
	return new Operand<int8_t>(std::stoi(value));
}

const IOperand* IOperand::createInt16(const std::string& value) {
	return new Operand<int16_t>(std::stoi(value));
}

const IOperand* IOperand::createInt32(const std::string& value) {
	return new Operand<int32_t>(std::stoi(value));
}

const IOperand* IOperand::createFloat(const std::string& value) {
	return new Operand<float>(std::stof(value));
}

const IOperand* IOperand::createDouble(const std::string& value) {
	return new Operand<double>(std::stod(value));
}

std::ostream& operator<<(std::ostream& os, const IOperand& op) {
	os << op.toString();
	return os;
}

std::ostream& operator<<(std::ostream& os, const IOperand* op) {
	os << op->toString();
	return os;
}
