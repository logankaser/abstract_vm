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
	parse(argv[1]);
	(void)argc;
	return (0);
}

/*
std::vector<std::string>::iterator line;
for (line = lines.begin();line != lines.end();++line) {
	std::cout << *line << std::endl;
}
*/
