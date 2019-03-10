# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 11:11:17 by vlaroque          #+#    #+#              #
#    Updated: 2019/03/09 23:00:19 by vlaroque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

FLAGS=no

CPPFLAGS = -I ./includes/
SRC = ft_printf.c ft_putchar.c ft_conversions.c \
		ft_data_init.c ft_isdigit.c ft_parsing.c \
		ft_strlen.c ft_putstrcmpt.c ft_strdup.c \
		put_di.c ft_generic_int_fct.c put_u.c putnbr_base.c put_oxXp.c\
		getdata_varg.c put_cspc.c ft_meganbr.c ft_meganbr_maths.c\
		ft_meganbr_processing.c put_f.c put_bonus.c ft_color.c
SRCPATH = ./src/
OBJ = $(SRC:.c=.o)
OBJPATH = ./obj/
OBJS = $(addprefix $(OBJPATH), $(OBJ))
INCPATH = ./includes/

ifdef FLAGS
	ifeq ($(FLAGS), no)
		CFLAGS= -g
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
	ar rcs $(NAME) $(OBJS)

clean :
	rm -Rf $(OBJS)

fclean : clean
	rm -Rf $(NAME)

re : 
	$(MAKE) fclean
	$(MAKE) all

test : all
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SRCPATH)main.c libftprintf.a



