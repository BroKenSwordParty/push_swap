/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_fts.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:17:23 by jchamorr          #+#    #+#             */
/*   Updated: 2023/01/10 12:38:02 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate_a(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_a_b(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
