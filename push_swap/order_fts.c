/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:54:25 by jchamorr          #+#    #+#             */
/*   Updated: 2022/12/23 09:48:02 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	lets_order_this_numbers(t_push **s)
{
	int		n[3];

	n[0] = (*s)->a->nb;
	n[1] = (*s)->a->nxt->nb;
	n[2] = (*s)->a->nxt->nxt->nb;
	printf("PASAMOS POR AQUI\n");
	if (n[0] > n[1] && n[1] < n[2] && n[0] < n[2])
		rotate_a(&(*s)->a);
	else if (n[0] > n[1] && n[1] > n[2])
		swap_a(&(*s)->a);
	else if (n[0] > n[1] && n[1] < n[2] && n[0] > n[2])
	{
		swap_a(&(*s)->a);
		reverse_rotate_a(&(*s)->a);
	}
	else if (n[0] < n[1] && n[1] > n[2] && n[0] < n[2])
	{
		swap_a(&(*s)->a);
		rotate_a(&(*s)->a);
	}
	else if (n[0] < n[1] && n[1] > n[2] && n[0] > n[2])
		reverse_rotate_a(&(*s)->a);
	// TENGO QUE REVISAR LOS CASOS ESPECÍFICOS PARA SER MÁS EXACTO PORQUE PUEDEN LLEGAR A FALLAR
	// Y ENTRAR EN funciones que no son.
}

void	find_limits(t_push *s)
{
	
}



void	hardcoded_ordering(t_push *s)
{
	t_stack	*prueba;

	prueba = s->a;
	printf("LA LISTA ANTES DE SER ORDENADA\n");
	printf("------------------------------\n");
	while (prueba != NULL)
	{
		printf("NUMERO DE A EN WHILE %d\n", prueba->nb);
		printf("POINTER DE A EN WHILE %p\n", prueba->nxt);
		prueba = prueba->nxt;
	}
	if (s->index == 2)
		swap_a(&s->a);
	if (s->index == 3)
		lets_order_this_numbers(&s);
	if (s->index == 5)
		find_limits(&s);
	// Voy a hacer 2 ft que busquen el numero más grande y el más pequeño (o una).
	// Para hacer que ordene los de 5, pero teóricamente, ya que no hace make.
	prueba = s->a;
	printf("--------------------------------\n");
	printf("LA LISTA DESPUÉS DE SER ORDENADA\n");
	while (prueba != NULL)
	{
		printf("NUMERO DE A EN WHILE %d\n", prueba->nb);
		printf("POINTER DE A EN WHILE %p\n", prueba->nxt);
		prueba = prueba->nxt;
	}
}
