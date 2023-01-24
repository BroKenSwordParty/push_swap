/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:54:25 by jchamorr          #+#    #+#             */
/*   Updated: 2023/01/24 12:05:38 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	lets_order_this_numbers(t_push *s)
{
	int		n[3];

	n[0] = s->a->nb;
	n[1] = s->a->nxt->nb;
	n[2] = s->a->nxt->nxt->nb;
	if (n[0] > n[1] && n[1] < n[2] && n[0] < n[2])
		swap_a(&s->a);
	else if (n[0] > n[1] && n[1] < n[2] && n[0] > n[2])
		rotate_a(&s->a);
	else if (n[0] > n[1] && n[1] > n[2])
	{
		swap_a(&s->a);
		reverse_rotate_a(&s->a);
	}
	else if (n[0] < n[1] && n[1] > n[2] && n[0] < n[2])
	{
		swap_a(&s->a);
		rotate_a(&s->a);
	}
	else if (n[0] < n[1] && n[1] > n[2] && n[0] > n[2])
		reverse_rotate_a(&s->a);
}

void	push_smaller(t_push *s)
{
	t_stack	*stk;
	int		i;

	stk = s->a;
	find_limits(s);
	if (s->a->nb == s->limits[0])
	{
		push_b(s);
		return ;
	}
	i = -1;
	while (stk->nb != s->limits[0] && ++i < lstsize(&s->a))
		stk = stk->nxt;
	if (i >= lstsize(&s->a) / 2)
	{
		while (s->a->nb != s->limits[0])
			reverse_rotate_a(&s->a);
	}
	else
	{
		while (s->a->nb != s->limits[0])
			rotate_a(&s->a);
	}
	push_b(s);
}

void	find_limits(t_push *s)
{
	t_stack	*stk;

	stk = s->a;
	s->limits[0] = stk->nb;
	s->limits[1] = stk->nb;
	while (stk != NULL)
	{
		if (s->limits[0] > stk->nb)
			s->limits[0] = stk->nb;
		if (s->limits[1] < stk->nb)
			s->limits[1] = stk->nb;
		stk = stk->nxt;
	}
}

void	hardcoded_ordering(t_push *s)
{
	if (s->index == 2)
		swap_a(&s->a);
	if (s->index == 3)
		lets_order_this_numbers(s);
	find_limits(s);
	if (s->index == 4)
	{
		push_smaller(s);
		lets_order_this_numbers(s);
		push_a(s);
	}
	if (s->index == 5)
	{
		push_smaller(s);
		find_limits(s);
		push_smaller(s);
		lets_order_this_numbers(s);
		push_a(s);
		push_a(s);
	}
}
