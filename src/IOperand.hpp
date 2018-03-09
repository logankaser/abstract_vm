#ifndef IOPERAND_HPP
#define IOPERAND_HPP

#include <string>

enum eOperandType {
		Int8 = 1,
		Int16,
		Int32,
		Float,
		Double
};

class IOperand {
	IOperand* createInt8(const std::string& value) const;
	IOperand* createInt16(const std::string& value) const;
	IOperand* createInt32(const std::string& value) const;
	IOperand* createFloat(const std::string& value) const;
	IOperand* createDouble(const std::string& value) const;
public:
	IOperand* createOperand(eOperandType type, const std::string& value) const;
	virtual int getPrecision(void) const = 0;
	virtual eOperandType getType(void) const = 0;
	virtual const IOperand* operator+(const IOperand &rhs) const = 0;
	virtual const IOperand* operator-(const IOperand &rhs) const = 0;
	virtual const IOperand* operator*(const IOperand &rhs) const = 0;
	virtual const IOperand* operator/(const IOperand &rhs) const = 0;
	virtual const IOperand* operator%(const IOperand &rhs) const = 0;
	virtual const std::string& toString(void) const = 0;
	virtual ~IOperand(void) {};
};

#endif
