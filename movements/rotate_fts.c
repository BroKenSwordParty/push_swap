/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_fts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:14:49 by jchamorr          #+#    #+#             */
/*   Updated: 2023/01/17 13:57:53 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rotate_a_b(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
