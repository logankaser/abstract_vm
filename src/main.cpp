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
#include "abstract.hpp"

int	main(int argc, char **argv) {
	if (argc > 2) {
		std::cout
			<< C_RED "Argument Error" C_RESET ",\n too many arguments" << std::endl;
	}
	else {
		std::vector<const IOperand*> stack;
		std::vector<const Expression*> codes = parse(argc == 2 ? argv[1] : NULL);
		std::vector<const Expression*>::const_iterator code;
		for (code = codes.begin();code != codes.end();++code) {
			std::cout << *code << std::endl;
			if ((*code)->type == ExType::push) {
				stack.push_back((*code)->operand);
			}
		}
		std::cout << stack.back() << std::endl;
	}
	return (0);
}
