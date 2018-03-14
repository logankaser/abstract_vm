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
	const IOperand* op = IOperand::createOperand(eOperandType::Double, "0.234");
	const IOperand* op2 = IOperand::createOperand(eOperandType::Int8, "2");
	const IOperand* result = *op2 + *op;
	std::cout << result->getType() << std::endl;
	std::cout << result << std::endl;
	lex(argv[1]);
	(void)argc;
	return (0);
}
