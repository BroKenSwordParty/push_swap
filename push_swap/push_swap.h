/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:50:29 by jchamorr          #+#    #+#             */
/*   Updated: 2022/11/17 20:40:10 by jchamorr         ###   ########.fr       */
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
	int			nbrs; // nº of nbrs.
	int			*nb; // tmp pero de números.
	char		*arg; // arg en caso de que no haya "".
	char		**tmp; // split del arg
	t_stack		*a; // linked - a
	t_stack		*b; // linked - b
}	t_push;

//Ordenar los números pequeños.
//	Si hay 1 nº lo muestro.
//	si hay menos de 5 nº los ordeno y muestro

// HACERLO CON LINKED LIST ---- RADIX
// Comprobar argumentos si son con comillas o no.
// DONE -- Hacer SPLIT a los números y luego ATOI para pasar los nº a INT.
// Al comprobar que es un INT Se pasa al stack B
// Una vez tenga el STACK A,
// Necesito que todos los números sean POSITIVOS
// Cuantos nº me están entrando
// Añadir un índice para eliminar los nº negativos.
// Buscar lo que hace & (Geeks4geeks, cuál es el bit mas importante seteado).


void	check_args(t_push *s);
void	end_point(int i);
void	join_args(t_push *s, char *av);

#endif

// LO QUE TENGO HASTA AHORA:
// 1. Inicializo estructura y entro a checkear argumentos
// 2. Si hay 2 arg (nº entre comillas) lo paso por split y obtengo un bi-array con todos los ints.
// 3. Comparo esos números entre sí para ver si están repetidos
// 4. Strjoin si hay más de 2 args para convertirlo en uno y jugar con él.
// 5.