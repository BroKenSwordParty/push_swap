/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:24:36 by jchamorr          #+#    #+#             */
/*   Updated: 2023/01/09 17:29:58 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	fill_stacks(t_push *s)
{
	int	i;

	if (s->index == 1)
		end_point (0);
	i = 0;
	ft_insert_nbr_empty(&s->a, ft_atoi(s->tmp[i]));
	while (++i < s->index)
		ft_insert_nbr(&s->a, ft_atoi(s->tmp[i]));
	free_tmp(s);
}

void	check_and_order(t_push *s)
{
	are_u_ordered_mr_stack(&s->a);
	if (s->index <= 5)
		hardcoded_ordering(s);
	if (s->index < 5 && s->index > 100)
		algo_rhythm_1();
	// if (s->index <= 100)
		//algo_rhythm_2();
}