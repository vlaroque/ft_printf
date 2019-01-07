# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 11:11:17 by vlaroque          #+#    #+#              #
#    Updated: 2019/01/07 19:56:07 by vlaroque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I ./includes/
SRC = ft_printf.c ft_basics.c ft_parser.c
SRCPATH = ./sources/
OBJ = $(SRC:.c=.o)
OBJPATH = ./objects/
OBJS = $(addprefix $(OBJPATH), $(OBJ))
INCPATH = ./includes/

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
	$(CC) $(FLAGS) $(CPPFLAGS) $(SRCPATH)main.c libftprintf.a



