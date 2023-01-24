/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:41:15 by jchamorr          #+#    #+#             */
/*   Updated: 2023/01/17 14:17:33 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_args(t_push *s)
{
	int	i;
	int	j;

	i = 0;
	s->tmp = ft_split(s->arg, ' ');
	if (!s->tmp)
		end_point(1);
	while (s->tmp[i])
	{
		if (!negative_numbers(s->tmp[i]))
			end_point(1);
		if (s->tmp[i + 1] == NULL)
			break ;
		j = i + 1;
		while (s->tmp[j])
		{
			if (ft_strcmp(s->tmp[i], s->tmp[j]) == 0)
				end_point (3);
			j++;
		}
		i++;
	}
	s->index = i + 1;
}

int	negative_numbers(char *num)
{
	int		i;

	i = 0;
	if (ft_strcmp(ft_itoa(ft_atoi(num)), num) != 0)
		return (0);
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	join_args(t_push *s, char **av)
{
	int		i;
	char	*tmp;

	i = 0;
	s->arg = ft_strdup("");
	while (av[i])
	{
		tmp = ft_strjoin(&av[i][0], " ");
		s->arg = ft_strjoin(s->arg, tmp);
		i++;
	}
	free (tmp);
}
