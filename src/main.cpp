/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:02:16 by lkaser            #+#    #+#             */
/*   Updated: 2018/03/13 10:02:17 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IOperand.hpp"
#include "Operand.hpp"
#include "Exceptions.hpp"
#include "abstract.hpp"

void	push(const Expression* ex, std::vector<const IOperand*>& stack) {
	stack.push_back(ex->operand);
}


void	assert(const Expression* ex, std::vector<const IOperand*>& stack) {
	if (*ex->operand != stack.back())
		throw except::AssertFailed();
}

void	pop(std::vector<const IOperand*>& stack) {
	if (stack.empty())
		throw except::PopOnEmpty();
	stack.pop_back();
}


void	dump(std::vector<const IOperand*>& stack) {
	if (!stack.empty())
		for (const IOperand* op : stack) {
			std::cout << op << std::endl;
		}
}

void	print(std::vector<const IOperand*>& stack) {
	if (stack.empty())
		throw except::TooFewOperands();
	if (stack.back()->getType() != eOperandType::Int8)
		throw except::AssertFailed();
	std:: cout << static_cast<char>(std::stoi(stack.back()->toString()));
}

int	main(int argc, char **argv) {
	if (argc > 2) {
		std::cout
			<< C_RED "Argument Error" C_RESET ",\n too many arguments" << std::endl;
	}
	else {
		std::vector<const IOperand*> stack;
		std::vector<const Expression*> codes = parse(argc == 2 ? argv[1] : NULL);
		for (unsigned i = 0; i < codes.size(); ++i) {
			try {
				switch (codes[i]->type) {
					case ExType::push:
						push(codes[i], stack);break;
					case ExType::assert:
						assert(codes[i], stack);break;
					case ExType::pop:
						pop(stack);break;
					case ExType::dump:
						dump(stack);break;
					case ExType::add:
						break;
					case ExType::sub:
						break;
					case ExType::mul:
						break;
					case ExType::div:
						break;
					case ExType::mod:
						break;
					case ExType::print:
						print(stack);break;
					case ExType::exit:
						break;
				}
			}
			catch(std::exception& e) {
				std::cout
					<< C_RED "Runtime Error" C_RESET ",\n "
					<< i << ": "
					<< e.what() << std::endl;
				exit(1);
			}
		}
	}
	return (0);
}
