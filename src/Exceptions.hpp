#include <iostream>
#include <stdexcept>

namespace abstract {
	struct AssertFailed : public std::runtime_error {
		AssertFailed(void) : std::runtime_error("Assertion failed") {};
	};
	struct UnknownInstruction : public std::runtime_error {
		UnknownInstruction(void) : std::runtime_error("Unknown instruction") {};
	};
	struct OperandOverflow : public std::overflow_error {
		OperandOverflow(void) : std::overflow_error("Operand overflow") {};
	};
	struct OperandUnderflow : public std::underflow_error {
		OperandUnderflow(void) : std::underflow_error("Operand underflow") {};
	};
	struct PopOnEmpty : public std::runtime_error {
		PopOnEmpty(void) : std::runtime_error("Pop on empty stack") {};
	};
	struct DivisionByZero : public std::range_error {
		DivisionByZero(void) : std::range_error("Division by zero") {};
	};
	struct TooFewOperands : public std::runtime_error {
		TooFewOperands(void) : std::runtime_error("Stack has too few operands for the operation") {};
	};
}
