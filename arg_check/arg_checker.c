/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:41:15 by jchamorr          #+#    #+#             */
/*   Updated: 2023/01/27 19:47:14 by jchamorr         ###   ########.fr       */
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
		end_point(s, 1);
	free(s->arg);
	while (s->tmp[i])
	{
		if (!negative_numbers(s->tmp[i]))
			end_point(s, 1);
		if (s->tmp[i + 1] == NULL)
			break ;
		j = i + 1;
		while (s->tmp[j])
		{
			if (ft_strcmp(s->tmp[i], s->tmp[j]) == 0)
				end_point(s, 3);
			j++;
		}
		i++;
	}
	s->index = i + 1;
}

int	negative_numbers(char *num)
{
	int		i;
	char	*holder;

	i = 0;
	holder = ft_itoa(ft_atoi(num));
	if (ft_strcmp(holder, num) != 0)
	{
		free(holder);
		return (0);
	}
	free(holder);
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

char	*join_args(char **av)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*holder;

	i = 0;
	holder = ft_strdup("");
	while (av[i])
	{
		tmp2 = ft_strdup(holder);
		free(holder);
		tmp = ft_strjoin(&av[i][0], " ");
		holder = ft_strjoin(tmp2, tmp);
		free(tmp2);
		i++;
		free(tmp);
	}
	return (holder);
}
