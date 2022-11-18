/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:33:29 by jchamorr          #+#    #+#             */
/*   Updated: 2022/11/17 17:41:08 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// En caso de que la lista sea NULL, la inicializamos. (Ésta función sólo se ejecuta una vez).
void	ft_insert_nbr_empty(t_list **stack_a, int nbr)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ;
	new->content = nbr;
	new->next = NULL;
	*stack_a = new;
}

// Ésta ft es para crear un nodo y meter un int en la lista.
void	ft_insert_nbr(t_push *s)
{
	t_list	*new;
	static int	i = 0;

	if (s->a == NULL)
		ft_insert_nbr_empty(s->a, ft_atoi(s->tmp[i]));
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ;
}

// Función que agrega un nuevo nodo al principio de la lista.
void	ft_insert_first(t_push *s)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list)); //!!!!!HAY QUE SEGUIR POR AQUI !!!!!!!!!!!!!!!!!!!!!
	if (!new)
		return ;
}