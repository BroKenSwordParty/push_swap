# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 11:34:38 by jchamorr          #+#    #+#              #
#    Updated: 2023/01/24 12:33:29 by jchamorr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main_fts/push_swap.c\
		main_fts/main_fts.c\
		main_fts/utils.c\
		main_fts/utils_2.c\
		arg_check/arg_checker.c\
		movements/order_fts.c\
		movements/order_fts_2.c\
		movements/stack_ft_calls.c\
		movements/rotate_fts.c\
		movements/reverse_rotate_fts.c\
		algorithm/algorithm_1.c\
		ft_print_stacks.c\

OBJS = $(SRC:.c=.o)

LIBFT = libft/libft.a

CC = gcc #-fsanitize=address -g3

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
