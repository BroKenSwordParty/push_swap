/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:33:29 by jchamorr          #+#    #+#             */
/*   Updated: 2023/01/24 12:01:31 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	are_u_ordered_mr_stack(t_stack **stack)
{
	t_stack	*head;
	int		i;

	head = (*stack);
	i = 0;
	while (head->nxt != NULL)
	{
		if (head->nb > head->nxt->nb)
		{
			i = 1;
			break ;
		}
		head = head->nxt;
	}
	if (i == 0)
		end_point(0);
}

void	ft_insert_nbr_empty(t_stack **stack_a, int nbr, int ind)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->nb = nbr;
	new->index = ind;
	new->nxt = NULL;
	*stack_a = new;
}

void	ft_insert_nbr(t_stack **stack_a, int nbr)
{
	t_stack	*new;
	t_stack	*copy;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->nb = nbr;
	new->nxt = NULL;
	copy = (*stack_a);
	while (copy->nxt)
		copy = copy->nxt;
	copy->nxt = new;
}

void	free_tmp(t_push *s)
{
	int	i;

	i = -1;
	while (s->tmp[++i])
		free(s->tmp[i]);
}
