/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_fts_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:17:15 by jchamorr          #+#    #+#             */
/*   Updated: 2023/01/19 17:16:17 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		ft_insert_nbr_empty(stack_2, (*stack_1)->nb, (*stack_1)->index);
		(*stack_1) = (*stack_1)->nxt;
		return ;
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
	(*stack) = (*stack)->nxt;
	head->nxt = NULL;
	temp = (*stack);
	while (temp->nxt != NULL)
		temp = temp->nxt;
	temp->nxt = head;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*head;

	head = (*stack);
	while (head->nxt->nxt != NULL)
		head = head->nxt;
	head->nxt->nxt = (*stack);
	(*stack) = head->nxt;
	head->nxt = NULL;
}
