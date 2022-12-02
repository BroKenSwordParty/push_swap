/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:50:29 by jchamorr          #+#    #+#             */
/*   Updated: 2022/12/02 14:25:21 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

#define ARG_ERR "Something is wrong with the args"
#define NUM_ERR "Arg not an int"
#define REP_ERR "Repeated numbers"

typedef struct  s_stack
{
	int				content; // number
	struct t_stack	*next; // pointer
}	t_stack;

typedef struct s_push
{
	int			index; // nº of nbrs.
	int			*nb; // tmp pero de números.
	char		*arg; // argumentos
	char		**tmp; // split del arg
	t_stack		*a; // linked - a
	t_stack		*b; // linked - b
}	t_push;

//Ordenar los números pequeños.
//	Si hay 1 nº lo muestro.
//	si hay menos de 5 nº los ordeno y muestro

// HACERLO CON LINKED LIST ---- RADIX
// Comprobar argumentos si son con comillas o no. ------------------------ DONE
// DONE -- Hacer SPLIT a los números.
// Al comprobar que es un INT Se pasa al stack B
// Una vez tenga el STACK A,
// Necesito que todos los números sean POSITIVOS
// Cuantos nº me están entrando
// Añadir un índice para eliminar los nº negativos.
// Buscar lo que hace & (Geeks4geeks, cuál es el bit mas importante seteado).

void	check_args(t_push *s);
void	end_point(int i);
void	join_args(t_push *s, char **av);
int		negative_numbers(char *num);

#endif

// LO QUE TENGO HASTA AHORA:
// 1. Inicializo estructura y entro a checkear argumentos
// 2. Si hay 2 arg (nº entre comillas) lo paso por split y obtengo un bi-array con todos los ints.
// 3. Comparo esos números entre sí para ver si están repetidos
// 4. Strjoin si hay más de 2 args para convertirlo en uno y jugar con él.
// 5.