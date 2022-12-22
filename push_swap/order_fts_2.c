/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_fts_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:17:15 by jchamorr          #+#    #+#             */
/*   Updated: 2022/12/22 16:36:19 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **stack)
{
	t_stack	*temp;

	temp = (*stack);
	temp = temp->nxt;
	(*stack)->nxt = temp->nxt;
	temp->nxt = *stack;
	*stack = temp;
}

void	push(t_stack **stack_1, t_stack **stack_2)
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

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*head;

	head = (*stack);
	temp = (*stack)->nxt;
	head->nxt = NULL;
	while ((*stack)->nxt != NULL)
		(*stack) = (*stack)->nxt;
	(*stack)->nxt = head;
	(*stack) = temp;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*head;

	head = (*stack);
	while (head->nxt->nxt != NULL)
		head = head->nxt;
	(*stack)->nxt->nxt = head;
	(*stack)->nxt = NULL;
	printf("NUMERO DE A EN WHILE %d\n", (*stack)->nb);
	*stack = head;
	printf("PRIMERO: %d\nSEGUNDO: %d\nTERCERO: %d\n", (*stack)->nb, (*stack)->nxt->nb, (*stack)->nxt->nxt->nb);
	// printf("ASKDFJASLKFJASKFJASLKFJASLKFJALSKFJALSKFJ TUS MUERTOS PISAOS\n");
	// printf("--------------------------------\n");
	// printf("LA LISTA DESPUÉS DE SER ORDENADA\n");
	// while (head != NULL)
	// {
	// 	printf("NUMERO DE A EN WHILE %d\n", head->nb);
	// 	printf("POINTER DE A EN WHILE %p\n", head->nxt);
	// 	head = head->nxt;
	// }
	exit(0);
}

// reverse rotate a - desplaza hacia abajo todos los elementos del stack a una
// posición, de forma que el último elemento se convierte en el primero.
