/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:24:36 by jchamorr          #+#    #+#             */
/*   Updated: 2023/01/30 16:59:55 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fill_stacks(t_push *s)
{
	t_stack	*stk;
	int		i;

	if (s->index == 1)
		exit (1);
	i = 0;
	ft_insert_nbr_empty(&s->a, ft_atoi(s->tmp[i]), -1);
	while (++i < s->index)
		ft_insert_nbr(&s->a, ft_atoi(s->tmp[i]));
	free_tmp(s);
	stk = s->a;
	while (stk != NULL)
	{
		stk->index = -1;
		stk = stk->nxt;
	}
}

void	check_and_order(t_push *s)
{
	s->a->size = lstsize(&s->a);
	are_u_ordered_mr_stack(&s->a);
	fix_something_you_btrd(s);
	index_stack(s);
	if (s->index <= 5 && s->index > 1)
		hardcoded_ordering(s);
	if (s->index > 5)
		radix_sort(s);
}
