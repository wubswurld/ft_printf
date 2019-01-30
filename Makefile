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
CFILES = ft_printf.c adlfiles.c manip.c
OFILES = ft_printf.o adlfile.o  manip.o
CFLAGS = -Wall -Werror -Wextra
CC = gcc
HEADER = ft_printf.h

all: $(NAME)

$(NAME):$(OFILES)
	@ar rcs $(NAME) $(OFILES)

$(OFILES):$(CFILES)
	@$(CC) $(CFLAGS) -I $(HEADER) $(CFILES)

clean: 
	@rm -rf $(OFILES)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
	
.PHONY: clean fclean make re all
