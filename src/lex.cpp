#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <algorithm>
#include "Expression.hpp"
#include "abstract.hpp"

// Grammer definitions

static const std::regex VAL_INT("(int8|int16|int32)\\((-?[\\d]+)\\)");
static const std::regex VAL_FLOAT("(float|double)\\((-?[\\d]+.[\\d]+)\\)");
static const std::regex EXP("(pop|dump|add|sub|mul|div|mod|print|exit)(?: *;.+)?");
static const std::regex EXP_LIT("(push|assert) (\\w+\\(\\S+\\))(?: *;.+)?");
static const std::regex COMMENT(";([^;]+)");

void open_stream(char** filename, std::shared_ptr<std::istream>* source) {
	static char* std_in = (char*)"stdin";
	if (!*filename) {
		*filename = std_in;
		source->reset(&std::cin, [](...){});
	}
	else
		source->reset(new std::ifstream(*filename));
	if (!(*source)->good()) {
		std::cout
			<< C_RED "File Error" C_RESET ",\n unable to open source file `"
			<< *filename << "`" << std::endl;
		exit(1);
	}
}

const Expression* make_expression(std::string ins) {
	if (ins == "pop")
		return new Expression(ExType::pop, NULL);
	else if (ins == "dump")
		return new Expression(ExType::dump, NULL);
	else if (ins == "add")
		return new Expression(ExType::add, NULL);
	else if (ins == "sub")
		return new Expression(ExType::sub, NULL);
	else if (ins == "mul")
		return new Expression(ExType::mul, NULL);
	else if (ins == "div")
		return new Expression(ExType::div, NULL);
	else if (ins == "mod")
		return new Expression(ExType::mod, NULL);
	else if (ins == "print")
		return new Expression(ExType::print, NULL);
	else
		return new Expression(ExType::exit, NULL);
}

const Expression* make_expression_and_literal(std::string ins, std::string val, unsigned* errors) {
	const IOperand* lit = NULL;
	std::smatch sm;
	try {
		if (regex_match(val, sm, VAL_INT)) {
			if (sm[1] == "int8")
				lit = IOperand::createOperand(eOperandType::Int8, sm[2]);
			else if (sm[1] == "int16")
				lit = IOperand::createOperand(eOperandType::Int16, sm[2]);
			else
				lit = IOperand::createOperand(eOperandType::Int32, sm[2]);
		}
		else if (regex_match(val, sm, VAL_FLOAT)) {
			if (sm[1] == "float")
				lit = IOperand::createOperand(eOperandType::Float, sm[2]);
			else
				lit = IOperand::createOperand(eOperandType::Double, sm[2]);
		}
	}
	catch(const std::exception& e) {
		*errors += 1;
		std::cout
			<< C_RED "Value Error" C_RESET ",\n error constructing value, `"
			<< e.what() << "`" << std::endl;
		return new Expression();
	}
	if (ins == "push")
		return new Expression(ExType::push, lit);
	return new Expression(ExType::assert, lit);
}

std::vector<const Expression*> lex(char* filename) {
	std::shared_ptr<std::istream> source;
	std::string line;
	std::smatch sm;
	std::vector<const Expression*> exps;
	unsigned line_number = 1;
	unsigned errors = 0;

	open_stream(&filename, &source);
	while(std::getline(*source, line)) {
		if (line == "")
			continue;
		if (regex_match(line, sm, COMMENT)) {
			std::cout << C_CYAN << sm[1] << C_RESET << std::endl;
		}
		else if (regex_match(line, sm, EXP)) {
			exps.push_back(make_expression(sm[1]));
		}
		else if (regex_match(line, sm, EXP_LIT)) {
			exps.push_back(make_expression_and_literal(sm[1], sm[2], &errors));
		}
		else if (line == ";;") {
			break;
		}
		else {
			++errors;
			std::cout
				<< C_RED "Syntax Error" C_RESET ",\n "
				<< filename << ':' << line_number << ": "
				<< line << std::endl;
		}
		++line_number;
	}
	const Expression ex(ExType::exit, NULL);
	if(std::find_if(exps.begin(), exps.end(),
	[&ex](const Expression* exp) {return *exp == ex;}) == exps.end()) {
		std::cout << C_RED "Logic Error" C_RESET ",\n"
			<< " missing exit instruction" << std::endl;
		exit(1);
	}
	if (errors) {
		std::cout << "-------------------------------------\n"
			<< errors << C_RED " Errors" C_RESET << std::endl;
		exit(1);
	}
	return exps;
}
