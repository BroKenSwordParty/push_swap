/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:50:21 by jchamorr          #+#    #+#             */
/*   Updated: 2022/11/17 21:06:03 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// - - - SUPUESTAMENTE ESTÁ TERMINADA - - -
// Se utuliza split y atoi para pasar de args char** a int y meter numeros en stack_a
// DIRECCIÓN DE MEMORIA DE STRUCT
void	check_args(t_push *s) //                                        1!
{
	int	i;
	int	j;

	s->tmp = ft_split(s->arg, ' '); // Aquí tengo el array de números
	if (!s->tmp)
		end_point(1);
	i = 0;
	while (s->tmp[i++])
		s->nb[i] = ft_atoi(s->tmp[i]);
	i = 0;
	while (s->tmp[i] && s->tmp[i + 1] != NULL) // Checkeo y paso los args a array de ints.
	{
		if (!ft_isdigit(s->nb[i]) || s->nb[i] > INT_MAX || s->nb[i] < INT_MIN) // Si no es un número o es mayor que MAXINT, out
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


void	join_args(t_push *s, char *av)
{
	static int	i = 0;

	while (av[i++])
	{
		printf("%c\n", av[i]);
		s->arg = ft_strjoin(&av[i], " ");
	}
	s->arg[i] = '\0';
}

void	end_point(int i)
{
	if (i == 1)
		printf("%s\n", ARG_ERR);
	if (i == 2)
		printf("%s\n", NUM_ERR);
	if (i == 3)
		printf("%s\n", REP_ERR);
	exit (1);
}

// Vamos a utilizar ft_memset para inicializar las variables de la estructura sin tener que hacer malloc
// Iniciamos el primer nodo a NULL para poder usarlo.
// Si tenemos más de 2 args, hacemos un join para que sea solo uno.
int	main(int ac, char **av)
{
	t_push	s;

	s.a = NULL;
	s.b = NULL;
	ft_memset(&s, 0, sizeof(t_push));
	if (ac > 2) // si hay más de 2 args me joinea los args y me los convierte en uno solo.
		join_args(&s, av[1]);
	if (ac == 2)
		s.arg = av[1]; // Si hay 2 args, guardo todo en uno y empiezo a check args.
	check_args(&s); // chequeo los argumentos
	return (0);
}
