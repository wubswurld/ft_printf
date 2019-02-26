# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jawatter <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/24 15:47:11 by jawatter          #+#    #+#              #
#    Updated: 2019/01/25 18:25:57 by jawatter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CFILES = ft_printf.c ft_extra.c ex.c basic.c mostbasic.c bool.c width.c morefunctions.c octal.c check.c point.c binary.c prec.c

FLAGS = -Wall -Wextra -Werror

OBJS = *.o

EX = ft_printf

all: $(NAME)

$(NAME):
	@echo "\033[32mCompiling files . . .\033[0m"
	@gcc $(FLAGS) -c $(CFILES) 
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@echo "\033[32mCleaning .\033[0m"
	@rm -rf $(OBJS)

fclean: clean
	@echo "\033[32mClean more . .\033[0m"
	@rm -rf $(NAME)
	@rm -rf $(EX)

test: re

	@$(CC) $(FLAGS) main.c -L. -lftprintf -o $(EX)

re: fclean all