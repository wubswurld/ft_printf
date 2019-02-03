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

CFILES = ft_printf.c ft_extra.c main.c

EX = main.c

OFILES = *.o

CFLAGS = -Wall -Werror -Wextra

CC = gcc

HEADER = ft_printf.h

all: $(NAME)

$(OFILES):$(CFILES)
	@$(CC) $(CFLAGS) -I $(HEADER) -c $(CFILES)

$(NAME):$(OFILES)
	@ar rcs $(NAME) $(OFILES)

clean: 
	@rm -rf $(OFILES)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
	
.PHONY: clean fclean make re all
