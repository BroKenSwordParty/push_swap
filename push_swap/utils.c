/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:33:29 by jchamorr          #+#    #+#             */
/*   Updated: 2022/12/16 16:02:00 by jchamorr         ###   ########.fr       */
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
	while (head->next != NULL)
	{
		if (head->content > head->next->content)
		{
			i = 1;
			break;
		}
		head = head->next;
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
	new->content = nbr;
	new->next = NULL;
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
	new->content = nbr;
	new->next = NULL;
	copy = (*stack_a);
	while (copy->next)
		copy = copy->next;
	copy->next = new;
}

void	free_tmp(t_push *s)
{
	int	i;

	i = -1;
	while (s->tmp[++i])
		free(s->tmp[i]);
}

// Función que agrega un nuevo nodo al principio de la lista. ---------- Prob. ELIMINAR
void	ft_insert_first(t_push *s)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack)); //!!!!!HAY QUE SEGUIR POR AQUI !!!!!!!!!!!!!!!!!!!!!
	if (!new)
		return ;

}