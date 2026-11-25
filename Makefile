# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jagrund <jagrund@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/25 18:48:13 by jagrund           #+#    #+#              #
#    Updated: 2026/11/25 19:42:30 by jagrund          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = adaptive.c complex.c disorder.c error_utils.c\
ft_strcmp.c main.c medium.c node_utils.c push_command.c\
push_swap_commands.c push_swap_init.c rev_rotate_command.c\
rotate_command.c simple.c split.c stack_init.c swap_command.c\
tiny_sort.c

OBJS	= $(SRCS:.c=.o)
all:	$(NAME)
$(NAME):	$(OBJS)
	$(CC) $(FLAGS) $(OBJS)	-o	$(NAME)

clean:
	rm -f $(OBJS)
fclean:
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re




