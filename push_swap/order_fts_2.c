/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_fts_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:17:15 by jchamorr          #+#    #+#             */
/*   Updated: 2022/12/23 09:43:08 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **stack) // ESTE FUNCIONA
{
	t_stack	*temp;

	temp = (*stack);
	temp = temp->nxt;
	(*stack)->nxt = temp->nxt;
	temp->nxt = *stack;
	*stack = temp;
}

void	push(t_stack **stack_1, t_stack **stack_2) // ESTE FUNCIONA
{
	t_stack	*temp;

	if ((*stack_2) == NULL)
	{
		ft_insert_nbr_empty(stack_2, (*stack_1)->nb);
		(*stack_1) = (*stack_1)->nxt;
		return;
	}
	temp = (*stack_1);
	(*stack_1) = (*stack_1)->nxt;
	temp->nxt = (*stack_2);
	(*stack_2) = temp;
}

void	rotate(t_stack **stack) // ESTE FUNCIONA
{
	t_stack	*temp;
	t_stack	*head;

	head = (*stack);
	(*stack) = (*stack)->nxt;
	head->nxt = NULL;
	temp = (*stack);
	while (temp->nxt != NULL)
		temp = temp->nxt;
	temp->nxt = head;
}

void	reverse_rotate(t_stack **stack) // ESTE FUNCIONA
{
	t_stack	*head;

	head = (*stack);
	while (head->nxt->nxt != NULL)
		head = head->nxt;
	head->nxt->nxt = (*stack);
	(*stack) = head->nxt;
	head->nxt = NULL;
}

// reverse rotate a - desplaza hacia abajo todos los elementos del stack a una
// posición, de forma que el último elemento se convierte en el primero.
