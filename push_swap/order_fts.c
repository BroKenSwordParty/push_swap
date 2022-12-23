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

void	lets_order_this_numbers(t_push **s)
{
	t_stack	*stk;

	printf("PASAMOS POR AQUI\n");
	stk = (*s)->a;
	if (stk->nb > stk->nxt->nb && stk->nb > stk->nxt->nxt->nb)
		rotate_a(&(*s)->a);
	else if (stk->nb > stk->nxt->nb && stk->nxt->nb < stk->nxt->nxt->nb)
		swap_a(&(*s)->a);
	else if (stk->nb > stk->nxt->nb && stk->nxt->nb > stk->nxt->nxt->nb)
	{
		swap_a(&(*s)->a);
		reverse_rotate_a(&(*s)->a);
	}
	else if (stk->nb < stk->nxt->nb && stk->nxt->nb > stk->nxt->nxt->nb)
	{
		swap_a(&(*s)->a);
		rotate_a(&(*s)->a);
	}
	else if (stk->nb < stk->nxt->nb && stk->nxt->nb > stk->nxt->nxt->nb)
		reverse_rotate_a(&(*s)->a);
	// TENGO QUE REVISAR LOS CASOS ESPECÍFICOS PARA SER MÁS EXACTO PORQUE PUEDEN LLEGAR A FALLAR
	// Y ENTRAR EN funciones que no son.
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
