/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:31:08 by jchamorr          #+#    #+#             */
/*   Updated: 2023/01/24 12:11:59 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	lstsize(t_stack **stk)
{
	t_stack	*head;
	int		i;

	i = 0;
	head = *stk;
	if (head == NULL)
		return (0);
	while (head != NULL)
	{
		head = head->nxt;
		i++;
	}
	return (i);
}

int	lastnum(t_push *s)
{
	t_stack	*stk;

	stk = s->a;
	while (stk->nxt != NULL)
		stk = stk->nxt;
	return (stk->index);
}

void	index_stack(t_push *s)
{
	t_stack	*stk;
	int		nbr;
	int		index;

	index = 0;
	while (index < s->index)
	{
		stk = s->a;
		nbr = 2147483647;
		while (stk != NULL)
		{
			if (nbr >= stk->nb && stk->index == -1)
				nbr = stk->nb;
			stk = stk->nxt;
		}
		stk = s->a;
		while (stk != NULL)
		{
			if (nbr == stk->nb && stk->index < 0)
				stk->index = index;
			stk = stk->nxt;
		}
		index++;
	}
}
