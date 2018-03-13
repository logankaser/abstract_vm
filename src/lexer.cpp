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

#include <fstream>
#include <string>

std::vector<std::string>	lex(char *filename) {
	std::ifstream source(filename, std::ifstream::in);
	std::vector<std::string> lines;
	while(std::geline(source, line))
		lines.push_back(line);
	source.close();
}
