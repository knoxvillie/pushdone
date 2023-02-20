# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 00:04:31 by kfaustin          #+#    #+#              #
#    Updated: 2023/02/20 15:24:51 by kfaustin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Mandatory --- #
# Executable file
BINARY	= push_swap

# Push_swap library
PSLIB	= push_swap.a

# My ft_printf
PDIR	= ./includes/ft_printf/
PLIB	= libftprintf.a

# Compiler and shell scripts
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

# Source files
SRCDIR	= ./src/
SRC		= check_args.c ft_split.c list_utils.c moves.c multiples_argv.c push_swap.c \
			pushswap3.c pushswap5.c pushswap100.c pushswap500.c single_argv.c \
			sort_stack.c sort_stack2.c str_to_number.c utils.c

# Object files
#OBJ		= $(SRCDIR)$(SRC:.c=.o)
OBJ		= $(addprefix $(SRCDIR), $(SRC:.c=.o))

# --- Bonus --- #
# Executable file
CHECKER	= checker

# My Get_next_line
GDIR	= ./includes/get_next_line/
GLIB	= get_next_line.a

SRC_G	= get_next_line.c get_next_line_utils.c

OBJ_G	= $(addprefix $(GDIR), $(SRC_G:.c=.o))

# Checker path
SRC_BONUS		= check_moves.c checker.c
SRC_BONUS_PATH	= ./srcbonus/
SRC_COMP		= $(addprefix $(SRC_BONUS_PATH), $(SRC_BONUS))

# Target and rules
all: $(PSLIB) $(PLIB)
		$(CC) $(CFLAGS) -g $(PSLIB) $(PLIB) -o $(BINARY)
#		make clean

$(PLIB):
		make -C $(PDIR)
		cp $(PDIR)$(PLIB) .

$(PSLIB): $(OBJ)
		$(AR) $(PSLIB) $(OBJ)

$(GLIB): all $(OBJ_G)
		$(AR) $(GLIB) $(OBJ_G)

#%.o:%.c
#		$(CC) $(CFLAGS) -c -o $@ $^

bonus: $(GLIB)
		$(CC) $(CFLAGS) -g $(SRC_COMP) $(GLIB) $(PLIB) $(PSLIB) -o $(CHECKER)

clean:
#		make -C $(PDIR) clean
		$(RM) $(OBJ)
		$(RM) $(PSLIB) $(PLIB)
		$(RM) $(OBJ_G) $(GLIB)

fclean: clean
		make -C $(PDIR) fclean
		$(RM) $(BINARY) $(CHECKER)

re: fclean all
