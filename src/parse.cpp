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
static const std::regex OP("(pop|dump|add|sub|mul|div|mod|print|exit)");
static const std::regex OP_LIT("(push|assert) (\\w+\\(\\S+\\))");
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

Expression* make_expression(std::smatch lexed, unsigned* error) {
	(void)lexed;
	(void)error;
	return new Expression();
}

std::vector<Expression*> parse(char* filename) {
	std::shared_ptr<std::istream> source;
	std::string line;
	std::smatch sm;
	std::vector<Expression*> exps;
	unsigned line_number = 1;
	unsigned error = 0;

	open_stream(filename, &source);
	while(std::getline(*source, line)) {
		if (line == "")
			continue;
		if (regex_match(line, sm, COMMENT)) {
			std::cout << C_CYAN << sm[1] << C_RESET << std::endl;
		}
		else if (regex_match(line, sm, OP)) {
			exps.push_back(make_expression(sm, &error));
		}
		else if (regex_match(line, sm, OP_LIT)) {
			exps.push_back(make_expression(sm, &error));
		}
		else if (line == ";;") {
			break;
		}
		else {
			std::cout
				<< C_RED "Syntax Error" C_RESET ",\n "
				<< filename << ':' << line_number << ": "
				<< line << std::endl;
		}
		++line_number;
	}
	if (error)
		exit(1);
	return exps;
}

/*
	std::vector<std::string>::iterator line;
	for (line = lines.begin();line != lines.end();++line) {
		std::cout << *line << std::endl;
	}
}
*/
