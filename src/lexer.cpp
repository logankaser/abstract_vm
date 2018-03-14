/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:02:04 by lkaser            #+#    #+#             */
/*   Updated: 2018/03/13 10:19:15 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <stdlib.h>
#include "abstract.hpp"

// Grammer definitions

static std::regex INT("(?:int8|int16|int32)\\((-?[\\d]+)\\)");
static std::regex FLOAT("(?:float|double)\\((-?[\\d]+.[\\d]+)\\)");
static std::regex OP("(pop|dump|add|sub|mul|div|mod|print|exit)");
static std::regex OP_LIT("(push|assert) (\\w+\\(\\S+\\))");
static std::regex COMMENT(";([^;]+)");

void lex(const char *filename) {
	std::ifstream source(filename);
	std::string line;
	std::smatch sm;
	unsigned line_number = 1;

	if (!source.is_open()) {
		std::cout << C_RED "File Error" C_RESET ", unable to open source file `"
			<< filename << "`"
		<< std::endl;
		exit(1);
	}
	while(std::getline(source, line)) {
		if (regex_match(line, sm, COMMENT)) {
			std::cout << sm[1] << std::endl;
		}
		else if (regex_match(line, sm, OP)) {
			std::cout << sm[1] << std::endl;
		}
		else if (regex_match(line, sm, OP_LIT)) {
			std::cout << sm[1] << " arg, " << sm[2] << std::endl;
		}
		else if (line == ";;") {
			break;
		}
		else {
			std::cout << C_RED "Syntax Error" C_RESET ",\n "
				<< filename << ':' << line_number << ": " << line
			<< std::endl;
		}
		++line_number;
	}
}
/*	source.close();
	std::vector<std::string>::iterator line;
	for (line = lines.begin();line != lines.end();++line) {
		std::cout << *line << std::endl;
	}
}
*/
