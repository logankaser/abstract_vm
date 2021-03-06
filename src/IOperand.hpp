/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:02:31 by lkaser            #+#    #+#             */
/*   Updated: 2018/03/13 10:02:33 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
#define IOPERAND_HPP

#include <string>
#include <iostream>

enum class eOperandType : int {
		Int8 = 1,
		Int16,
		Int32,
		Float,
		Double
};

std::ostream& operator<<(std::ostream& os, eOperandType type);

class IOperand {
	static const IOperand* createInt8(const std::string& value);
	static const IOperand* createInt16(const std::string& value);
	static const IOperand* createInt32(const std::string& value);
	static const IOperand* createFloat(const std::string& value);
	static const IOperand* createDouble(const std::string& value);
public:
	static const IOperand* createOperand(eOperandType type, const std::string& value);
	virtual int getPrecision(void) const = 0;
	virtual eOperandType getType(void) const = 0;
	virtual const IOperand* operator+(const IOperand &rhs) const = 0;
	virtual const IOperand* operator-(const IOperand &rhs) const = 0;
	virtual const IOperand* operator*(const IOperand &rhs) const = 0;
	virtual const IOperand* operator/(const IOperand &rhs) const = 0;
	virtual const IOperand* operator%(const IOperand &rhs) const = 0;
	virtual bool operator==(const IOperand* rhs) const = 0;
	virtual bool operator!=(const IOperand* rhs) const = 0;
	virtual const std::string& toString(void) const = 0;
	virtual ~IOperand(void) {};
	friend std::ostream& operator<<(std::ostream& os, const IOperand& op);
	friend std::ostream& operator<<(std::ostream& os, const IOperand* op);
};

#endif
