/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:33:29 by jchamorr          #+#    #+#             */
/*   Updated: 2022/12/22 13:02:56 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Miramos a ver i están ordenados
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
			break;
		}
		head = head->nxt;
	}
	if (i == 0)
		end_point(0);
}

// En caso de que la lista sea NULL, la inicializamos.
void	ft_insert_nbr_empty(t_stack **stack_a, int nbr)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->nb = nbr;
	new->nxt = NULL;
	*stack_a = new;
}

// Ésta ft es para crear un nodo y meter un int en la lista.
// Se hace una copia de stack_a para no perder la referencia de la cabeza.
void	ft_insert_nbr(t_stack **stack_a, int nbr)
{
	t_stack	*new;
	t_stack *copy;

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
