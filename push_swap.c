/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:50:21 by jchamorr          #+#    #+#             */
/*   Updated: 2023/01/09 17:59:34 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	end_point(int i)
{
	if (i == 0)
	 	exit (0);
	if (i == 1)
		ft_putstr_fd(ARG_ERR, 1);
	if (i == 2)
		ft_putstr_fd(NUM_ERR, 1);
	if (i == 3)
		ft_putstr_fd(REP_ERR, 1);
	exit (1);
}

int	main(int ac, char **av)
{
	t_push	s;

	s.a = NULL;
	s.b = NULL;
	if (ac > 2)
		join_args(&s, &av[1]);
	if (ac == 2)
		s.arg = av[1];
	check_args(&s);
	fill_stacks(&s);
	check_and_order(&s);
	//printf("Me he pasado el juego\n");
	return (0);
}
//  -2147483648 , 2147483647