# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfaustin <kfaustin@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 13:52:57 by kfaustin          #+#    #+#              #
#    Updated: 2023/02/11 00:57:53 by kfaustin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	ft_checkspecifier.c \
		ft_printf.c \
		ft_printfc.c \
		ft_printfd.c \
		ft_printfp.c \
		ft_printfs.c \
		ft_printfu.c \
		ft_printfx.c

SRC_OBJ = $(SRC:.c=.o)

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = ar rcs
RM = rm -f

all : $(NAME) clean

$(NAME): $(SRC_OBJ)
		$(LIB) $(NAME) $(SRC_OBJ)

clean:
		$(RM) $(SRC_OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all
