# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/16 10:34:13 by mcauchy           #+#    #+#              #
#    Updated: 2025/02/16 17:56:01 by mcauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	=	push_swap.c singleton.c parsing.c free.c insertion.c checks.c

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

all:		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C libft
			$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

debug:		$(OBJS)
			$(MAKE) -C libft
			$(CC) $(CFLAGS) $(DEBUG) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
			$(MAKE) -C libft clean
			$(RM) $(OBJ_DIR)

fclean:		clean
			$(MAKE) -C libft fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
