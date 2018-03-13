# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 10:03:24 by lkaser            #+#    #+#              #
#    Updated: 2018/03/13 10:03:26 by lkaser           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm
LIST = main IOperand Operand

SRC = $(addsuffix .cpp, $(addprefix src/, $(LIST)))
OBJ = $(addsuffix .o, $(addprefix src/, $(LIST)))

CPPFLAGS = -O3 -Wall -Wextra -Werror -std=c++11
LDFLAGS =

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32;1mLinking.. \033[0m"
	@clang++ $(CPPFLAGS) $(LDFLAGS) $(SRC) -o $(NAME)
	@echo "\033[32;1m"$(NAME)" created\033[0m"

clean:
	@echo "\033[31;1mCleaning..\033[0m"
	@rm -f $(OBJ)

fclean:
	@echo "\033[31;1mFull Cleaning..\033[0m"
	@rm -f $(OBJ)
	@rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean all re
