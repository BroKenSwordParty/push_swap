/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:54:25 by jchamorr          #+#    #+#             */
/*   Updated: 2022/12/19 20:37:53 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	stack = stack->next;
	stack->next = temp;
}

void	push(t_stack *stack_1, t_stack *stack_2)
{
	t_stack	*temp;

	temp = &(*stack_1); // dir de B
	stack_1 = &(*stack_1->next); // dir de B = NEXT
	temp->next = &(*stack_2);
	stack_2 = temp;
}

void	hardcoded_ordering(t_push *s)
{
	t_stack	*prueba;

	prueba = s->a;
	s->b = (t_stack *)malloc(sizeof(t_stack));
	if (!s->b)
		end_point(0);
	s->b->content = 0;
	s->b->next = NULL;
	printf("ANTES DE LOS MOVEMENTS PRIMER  NODO DE B %d\n", s->b->content);
	printf("ANTES DE LOS MOVEMENTS DIRECCION DE DE B %p\n", s->b->next);
	printf("--------------------------------\n");
	printf("AHORA SE MUESTRA LA LISTA 'A' ANTES DE SER MODIFICADA\n");
	printf("--------------------------------\n");
	while (prueba != NULL)
		{
			printf("CONTENT DE A EN WHILE %d\n", prueba->content);
			printf("POINTER DE A EN WHILE %p\n", prueba->next);
			prueba = prueba->next;
		}
	if (s->index == 2)
	{
		//swap_a(s->a);
		push_b(s->a, s->b);
		printf("DESPUES DE LOS MOVEMENTS PRIMER  NODO DE A %d\n", s->a->content);
		printf("DESPUES DE LOS MOVEMENTS SEGUNDO NODO DE A %d\n", s->a->next->content);
		printf("--------------------------------\n");
		printf("DESPUES DE LOS MOVEMENTS PRIMER  NODO DE B %d\n", s->b->content);
		printf("DESPUES DE LOS MOVEMENTS DIRECCION DE DE B %p\n", s->b->next);
		printf("--------------------------------\n");
		printf("AHORA SE MUESTRA LA LISTA 'A' DESPUES DE SER MODIFICADA\n");
		printf("--------------------------------\n");
		prueba = s->a;
		while (prueba->next != NULL)
		{
			printf("CONTENT DE A EN WHILE %d\n", prueba->content);
			printf("POINTER DE A EN WHILE %p\n", prueba->next);
			prueba = prueba->next;
		}
	}

	// if (s->index == 3)
	// 	order_three(s->a);
}