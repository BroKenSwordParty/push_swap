/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:50:29 by jchamorr          #+#    #+#             */
/*   Updated: 2023/01/09 16:42:20 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"

#define ARG_ERR "Something is wrong with the args"
#define NUM_ERR "Arg not an int"
#define REP_ERR "Repeated numbers"

typedef struct  s_stack
{
	int				nb; // number
	size_t			index;	// index
	struct s_stack	*nxt; // pointer
}	t_stack;

typedef struct s_push
{
	int			index; // nº of nbrs.
	int			limits[2]; // smaller and bigger nbrs
	char		*arg; // argumentos
	char		**tmp; // split del arg
	t_stack		*a; // linked - a
	t_stack		*b; // linked - b
}				t_push;

// HACERLO CON LINKED LIST ---- RADIX
// DONE -- Comprobar argumentos si son con comillas o no.
// DONE -- Hacer SPLIT a los números.
// DONE -- Una vez tenga el STACK A,
// DONE -- Cuantos nº me están entrando e indexarlos.
// DONE -- Si solo hay un número STOP.
// DONE -- Si hay 2 números ordenar
// DONE -- Si hay 3 números ordenar
// Si hay 4 númeors ordenar
// Si hay 5 números ordenar
// Si hay entre 5 y 100 hacer ALGORITMO_1
// Si hay entre 100 y 500 hacer ALGORITMO_2
// Buscar lo que hace & (Geeks4geeks, cuál es el bit mas importante seteado).

//------ MAIN FTS ----------//
void	end_point(int i);
void	check_args(t_push *s);
void	join_args(t_push *s, char **av);
void	fill_stacks(t_push *s);
int		negative_numbers(char *num);
void	ft_insert_nbr(t_stack **stack_a, int nbr);
void	ft_insert_nbr_empty(t_stack **stack_a, int nbr);
void	check_and_order(t_push *s);
//---- ORDER CALL FTS --------//
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_a_b(t_stack **stack_a, t_stack **stack_b);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_a_swap_b(t_stack **stack_a, t_stack **stack_b);
void	push_a(t_push *s);
void	push_b(t_push *s);
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack);
void	rotate_a_b(t_stack **stack_a, t_stack **stack_b);
//------ ORDER FTS ----------//
void	hardcoded_ordering(t_push *s);
void	rotate(t_stack **stack);
void	swap_stack(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	push(t_stack **stack_a, t_stack **stack_b);
//------ UTILS FTS ----------//
void	are_u_ordered_mr_stack(t_stack **stack);
void	push_smaller(t_push **s);
void	free_tmp(t_push *s);

#endif

// LO QUE TENGO HASTA AHORA:
// 1. Inicializo estructura y entro a checkear argumentos
// 2. Si hay 2 arg (nº entre comillas) lo paso por split y obtengo un bi-array con todos los ints.
// 3. Comparo esos números entre sí para ver si están repetidos
// 4. Strjoin si hay más de 2 args para convertirlo en uno y jugar con él.
// 5. Si los nº están ordenados no hace nada.
// 6. Si hay 3 números los ordena.