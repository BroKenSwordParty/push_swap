/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ft_calls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:51:30 by jchamorr          #+#    #+#             */
/*   Updated: 2023/01/09 12:31:17 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack **stack)
{
	swap_stack(stack);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **stack)
{
	swap_stack(stack);
	write(1, "sb\n", 3);
}

void	swap_a_swap_b(t_stack **stack_a, t_stack **stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	write(1, "ss\n", 3);
}

void	push_b(t_push *s)
{
	push(&s->a, &s->b);
	write(1, "pb\n", 3);
}

void	push_a(t_push *s)
{
	push(&s->b, &s->a);
	write(1, "pa\n", 3);
}
