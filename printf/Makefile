# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdeliere <vdeliere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 16:04:36 by vdeliere          #+#    #+#              #
#    Updated: 2024/11/22 15:51:03 by vdeliere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_print_char.c ft_printf.c ft_print_format.c ft_print_str.c ft_print_pnt.c ft_print_hexa.c ft_print_digit.c ft_print_unsign.c

OFILES = $(FILES:.c=.o)

DEP = $(OFILES:.O=.d)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all : $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

$(OFILES): $(FILES)
	# $^ == source $< == destination
	$(CC) -c $(CFLAGS) $^ $<

clean :
	rm -f $(OFILES) 

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean 
