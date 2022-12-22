# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 11:34:38 by jchamorr          #+#    #+#              #
#    Updated: 2022/12/22 13:57:40 by jchamorr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c\
		main_fts.c\
		arg_checker.c\
		order_fts.c\
		order_fts_2.c\
		stack_ft_calls.c\
		rotate_fts.c\
		reverse_rotate_fts.c\
		utils.c\

OBJS = $(SRC:.c=.o)

LIBFT = libft/libft.a

CC = gcc -fsanitize=address -g3

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

%.o: %.c
	@$(CC) -c $< -o $@

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(FLAGS) $(LIBFT) $^ -o $@
	@echo "Done. "

%.o : %.c push_swap.h
	@$(CC) $(FLAGS) -c $< -o $@


clean:
	@echo "Cleaning... "
	@$(RM) $(OBJS)
	@make clean -C libft/

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY:	all clean fclean re
