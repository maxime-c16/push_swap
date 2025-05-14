# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/16 10:34:13 by mcauchy           #+#    #+#              #
#    Updated: 2025/05/14 13:03:14 by macauchy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	=	push_swap.c singleton.c parsing.c free.c insertion.c checks.c \
			radix.c movements.c mov_utils.c radix_utils.c radix_utils2.c \

SRC_DIR	=	srcs

SRCS	=	$(addprefix $(SRC_DIR)/, $(FILES))

OBJ_DIR	=	.objs

OBJS	=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

NAME	=	push_swap

CC		=	gcc

CFLAGS	=	-g3

DEBUG	=	-fsanitize=address

RM		=	/bin/rm -rf

LDFLAGS	=	-Llibft -lft

HEADER	=	include/push_swap.h

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADER)
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo "Compiling $(notdir $<)..."

debug:		$(OBJS)
			@make -C libft -j > /dev/null
			$(CC) $(CFLAGS) $(DEBUG) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
			@make -C libft clean > /dev/null
			@$(RM) $(OBJ_DIR)
			@echo "Cleaning $(OBJ_DIR)/ ..."

fclean:		clean
			@make -C libft fclean > /dev/null
			@$(RM) $(NAME)
			@echo "Cleaning $(NAME) ..."

re:			fclean all

.PHONY:		all clean fclean re
