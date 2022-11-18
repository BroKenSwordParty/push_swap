/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:50:21 by jchamorr          #+#    #+#             */
/*   Updated: 2022/10/31 13:51:04 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Se utuliza split y atoi para pasar de args char** a int y meter numeros en stack_a
// DIRECCIÓN DE MEMORIA DE STRUCT
void	check_args(t_push *s, char *s1) //                                        1!
{
	int	i;

	i = 0;
	s->tmp = ft_split(s1, ' '); // Aquí tengo el array de números
	if (!s->tmp)
		end_point(1);
	while (s->tmp[i]) // Checkeo y paso los args a array de ints.
	{
		if (!ft_isdigit(s->tmp[i]))
			end_point (2);


		printf ("%d\n", s->a->content);
		i++;
	}
}

void	end_point(int i)
{
	if (i == 1)
		printf("%s\n", ARG_ERROR);
	if (i == 2)
		printf("%s\n", NUM_ERROR);
	exit (1);
}


// Vamos a utilizar ft_memset para inicializar las variables de la estructura sin tener que hacer malloc
int	main(int ac, char **av)
{
	t_push	s;

	s.a = NULL;
	ft_memset(&s, 0, sizeof(t_push));
	if (ac == 2)
		check_args(&s, av[1]);//1
	else if (ac > 2)
		printf("Error papi\n");
		//check_args2();
	return (0);
}
