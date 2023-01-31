/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:18:30 by jchamorr          #+#    #+#             */
/*   Updated: 2023/01/25 20:54:27 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max_bits(t_stack **stk)
{
	t_stack	*head;
	int		max;
	int		max_bits;

	head = *stk;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->nxt;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_push *s)
{
	t_stack	*head;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head = s->a;
	size = lstsize(&head);
	max_bits = get_max_bits(&s->a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head = s->a;
			if (((head->index >> i) & 1) == 1)
				rotate_a(&s->a);
			else
				push_b(s);
		}
		while (lstsize(&s->b) != 0)
			push_a(s);
		i++;
	}
}
