/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:54:25 by jchamorr          #+#    #+#             */
/*   Updated: 2022/11/17 18:58:07 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//esta es la buena
void	check_args(t_push *s) //                                        1!
{
	int	i;
	int	j;

	s->tmp = ft_split(s->arg, ' '); // Aquí tengo el array de números
	if (!s->tmp)
		end_point(1);
	i = -1;
	while (s->tmp[++i])
		s->nb[i] = ft_atoi(s->tmp[i]);
	i = 0;
	while (ft_isdigit(s->nb[i]))
	{
		i++;
		if (!ft_isdigit(s->nb[i]))
			end_point(2);
	}
	i = 0;
	while (s->tmp[i] && s->tmp[i + 1] != NULL) // Checkeo y paso los args a array de ints.
	{
		if ( s->nb[i] > INT_MAX || s->nb[i] < INT_MIN) // Si no es un número o es mayor que MAXINT, out
			end_point (2);
		j = i + 1;
		if (s->nb[i] == s->nb[j]) // Si son iguales, ERROR.
			end_point (3);
		while (s->nb[i] != s->nb[j]) //Mientras sean diferentes, avanza
			j++;
		i++;
	}
	s->nbrs = i; // aprovecho que estoy avanzando en los numeros para contar el nº de numeros que hay.
}