#ifndef ABSTRACT_HPP
#define ABSTRACT_HPP

#include <vector>
#include "Expression.hpp"

std::vector<Expression*> parse(char* filename);

#define C_RED "\x1b[31m"
#define C_GREEN "\x1b[32m"
#define C_CYAN "\x1B[36m"
#define C_RESET "\x1b[0m"

#endif
