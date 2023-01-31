/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:50:21 by jchamorr          #+#    #+#             */
/*   Updated: 2023/01/30 17:13:07 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	end_point(t_push *s, int i)
{
	if (i == 0)
		exit (0);
	if (i == 1)
		ft_putstr_fd(ARG_ERR, 1);
	if (i == 2)
		ft_putstr_fd(NUM_ERR, 1);
	if (i == 3)
		ft_putstr_fd(REP_ERR, 1);
	if (s->tmp)
		free_tmp(s);
	if (i == 5)
		return ;
	free_stack(&s->a);
	exit (1);
}

int	main(int ac, char **av)
{
	t_push	s;

	if (ac == 1)
		return (0);
	s.a = NULL;
	s.b = NULL;
	if (ac > 2)
		s.arg = join_args(&av[1]);
	if (ac == 2)
		s.arg = ft_strdup(av[1]);
	check_args(&s);
	if (s.index == 1)
		end_point(&s, 4);
	fill_stacks(&s);
	check_and_order(&s);
	free_stack(&s.a);
	end_point(&s, 5);
	return (0);
}
