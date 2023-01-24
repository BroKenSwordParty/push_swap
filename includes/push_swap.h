/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:50:29 by jchamorr          #+#    #+#             */
/*   Updated: 2023/01/24 12:28:14 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define ARG_ERR "Error\n"
# define NUM_ERR "Error\n"
# define REP_ERR "Error\n"

typedef struct s_stack
{
	int				nb;
	int				size;
	int				index;
	struct s_stack	*nxt;
}	t_stack;

typedef struct s_push
{
	int			index;
	int			limits[2];
	char		*arg;
	char		**tmp;
	t_stack		*a;
	t_stack		*b;
}				t_push;

//------ MAIN FTS ----------//
void	end_point(int i);
void	check_args(t_push *s);
void	fill_stacks(t_push *s);
void	index_stack(t_push *s);
void	check_and_order(t_push *s);
int		negative_numbers(char *num);
void	join_args(t_push *s, char **av);
void	ft_insert_nbr(t_stack **stack_a, int nbr);
void	ft_insert_nbr_empty(t_stack **stack_a, int nbr, int ind);
//---- ALGORITHMS --------//
void	radix_sort(t_push *s);
//---- ORDER CALL FTS --------//
void	push_a(t_push *s);
void	push_b(t_push *s);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	rotate_a_b(t_stack **stack_a, t_stack **stack_b);
void	swap_a_swap_b(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_a_b(t_stack **stack_a, t_stack **stack_b);
//------ ORDER FTS ----------//
void	rotate(t_stack **stack);
void	swap_stack(t_stack **stack);
void	hardcoded_ordering(t_push *s);
void	reverse_rotate(t_stack **stack);
void	lets_order_this_numbers(t_push *s);
void	push(t_stack **stack_a, t_stack **stack_b);
//------ UTILS FTS ----------//
void	free_tmp(t_push *s);
int		lstsize(t_stack **s);
void	find_limits(t_push *s);
void	push_smaller(t_push *s);
int		get_max_bits(t_stack **stk);
void	push_smaller_to_a(t_push *s);
void	are_u_ordered_mr_stack(t_stack **stack);

#endif
