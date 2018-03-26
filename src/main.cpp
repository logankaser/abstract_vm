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

int	main(int argc, char **argv) {
	if (argc > 2) {
		std::cout
			<< C_RED "Argument Error" C_RESET ",\n too many arguments" << std::endl;
	}
	else {
		std::vector<const IOperand*> stack;
		std::vector<const Expression*> codes = lex(argc == 2 ? argv[1] : NULL);
		for (unsigned i = 0; i < codes.size(); ++i) {
			try {
				switch (codes[i]->type) {
					case ExType::push:
						parse::push(stack, codes[i]);break;
					case ExType::assert:
						parse::assert(stack, codes[i]);break;
					case ExType::pop:
						parse::pop(stack);break;
					case ExType::dump:
						parse::dump(stack);break;
					case ExType::add:
						parse::add(stack);break;
					case ExType::sub:
						parse::sub(stack);break;
					case ExType::mul:
						parse::mul(stack);break;
					case ExType::div:
						parse::div(stack);break;
					case ExType::mod:
						parse::mod(stack);break;
					case ExType::print:
						parse::print(stack);break;
					case ExType::loop:
						parse::loop(stack, codes[i], &i);break;
					case ExType::exit:
						exit(0);
				}
			}
			catch(const std::exception& e) {
				std::cout
					<< C_RED "Runtime Error" C_RESET ",\n "
					<< i + 1 << ": "
					<< e.what() << std::endl;
				exit(1);
			}
		}
	}
	return (0);
}
