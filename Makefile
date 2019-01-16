# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 11:11:17 by vlaroque          #+#    #+#              #
#    Updated: 2019/01/16 18:14:08 by vlaroque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I ./includes/
SRC = ft_printf.c ft_basics.c ft_parser.c ft_conversions.c \
		ft_procent.c ft_putc.c
SRC = ft_printf.c ft_putchar.c
SRCPATH = ./src/
OBJ = $(SRC:.c=.o)
OBJPATH = ./obj/
OBJS = $(addprefix $(OBJPATH), $(OBJ))
INCPATH = ./includes/

ifdef FLAGS
	ifeq ($(FLAGS), no)
		CFLAGS=
	endif
	ifeq ($(FLAGS), debug)
		CFLAGS= -Wall -Wextra -Werror -ansi -pedantic -g
	endif
else
	CFLAGS =	-Wall -Wextra -Werror
endif

all : $(NAME)

$(OBJPATH)%.o : $(SRCPATH)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(NAME) : $(OBJS) $(INCPATH)ft_printf.h
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	rm -Rf $(OBJS)

fclean : clean
	rm -Rf $(NAME)

test : all
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SRCPATH)main.c libftprintf.a



