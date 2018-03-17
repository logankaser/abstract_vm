#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <algorithm>
#include "Expression.hpp"
#include "abstract.hpp"

// Grammer definitions

static const std::regex INT("(?:int8|int16|int32)\\((-?[\\d]+)\\)");
static const std::regex FLOAT("(?:float|double)\\((-?[\\d]+.[\\d]+)\\)");
static const std::regex EXP("(pop|dump|add|sub|mul|div|mod|print|exit)");
static const std::regex EXP_LIT("(push|assert) (\\w+\\(\\S+\\))");
static const std::regex COMMENT(";([^;]+)");

void open_stream(char* filename, std::shared_ptr<std::istream>* source) {
	static char* std_in = (char*)"stdin";
	if (!filename) {
		filename = std_in;
		source->reset(&std::cin, [](...){});
	}
	else
		source->reset(new std::ifstream(filename));
	if (!(*source)->good()) {
		std::cout
			<< C_RED "File Error" C_RESET ",\n unable to open source file `"
			<< filename << "`" << std::endl;
		exit(1);
	}
}

Expression* make_expression(std::string op) {
	if (op == "pop")
		return new Expression(ExType::pop, NULL);
	else if (op == "dump")
		return new Expression(ExType::dump, NULL);
	else if (op == "add")
		return new Expression(ExType::add, NULL);
	else if (op == "sub")
		return new Expression(ExType::sub, NULL);
	else if (op == "mul")
		return new Expression(ExType::mul, NULL);
	else if (op == "div")
		return new Expression(ExType::div, NULL);
	else if (op == "mod")
		return new Expression(ExType::mod, NULL);
	else if (op == "print")
		return new Expression(ExType::print, NULL);
	else
		return new Expression(ExType::exit, NULL);
}


Expression* make_expression_and_literal(std::smatch lexed, unsigned* errors) {
	(void)lexed;
	(void)errors;
	return new Expression();
}

std::vector<Expression*> parse(char* filename) {
	std::shared_ptr<std::istream> source;
	std::string line;
	std::smatch sm;
	std::vector<Expression*> exps;
	unsigned line_number = 1;
	unsigned errors = 0;

	open_stream(filename, &source);
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
			exps.push_back(make_expression_and_literal(sm, &errors));
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
	if (errors) {
		std::cout << "-------------------------------------\n"
			<< errors << C_RED " Errors" C_RESET << std::endl;
		exit(1);
	}
	return exps;
}
