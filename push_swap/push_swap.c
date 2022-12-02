/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:50:21 by jchamorr          #+#    #+#             */
/*   Updated: 2022/12/02 15:56:26 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(t_push *s)
{
	int		i;
	int		j;

	i = 0;
	s->tmp = ft_split(s->arg, ' '); // Aquí tengo el array de números
	if (!s->tmp)
		end_point(1);
	// Ésto es de prueba y se puede eliminar después --------------
	while (s->tmp[i])
	{
		printf ("%s\n", s->tmp[i]);
		i++;
	}
	// ------------------------------------------------------------
	i = 0;
	while (s->tmp[i])
	{
		printf("El char* a comparar: %s\n", s->tmp[i]);
		printf("El ATOI de mentira: %d\n", ft_atoi(s->tmp[i]));
		printf("El ITOA de mentira: %s\n", ft_itoa(ft_atoi(s->tmp[i])));
		printf("El ATOI de verdad : %d\n", atoi(s->tmp[i]));
		if (!negative_numbers(s->tmp[i]))
			end_point(1);
		if (ft_atoi(s->tmp[i]) > INT_MAX || ft_atoi(s->tmp[i]) < INT_MIN)// Si está entre los ints
			end_point (2);
		if (s->tmp[i + 1] == NULL)
			break;
		j = i + 1;
		if (ft_strcmp(s->tmp[i], s->tmp[j]) == 0) // Si son iguales, ERROR.
			end_point (3);
		while (s->tmp[i] != s->tmp[j] && j < i) //Mientras sean diferentes, avanza
			j++;
		i++;
	}
	s->index = i; // aprovecho que estoy avanzando en los numeros para contar el nº de numeros que hay.
	printf("HE SALIDO DEL CHECKER\n");
}

// Función que comprueba todos los números, sean negativos o no.
int	negative_numbers(char *num)
{
	int		i;

	i = 0;
	printf("La comparación de los números es: %s / %s\n", ft_itoa(ft_atoi(num)), num);
	if (ft_strcmp(ft_itoa(ft_atoi(num)), num) != 0)
		return (0);
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return(0);
		i++;
	}
	return(1);
}

// función que joinea los args en caso de que no lleven comillas
void	join_args(t_push *s, char **av)
{
	int		i;
	char 	*tmp;

	i = 0;
	s->arg = ft_strdup("");
	while (av[i])
	{
		tmp = ft_strjoin(&av[i][0], " ");
		s->arg = ft_strjoin(s->arg, tmp);
		i++;
	}
	s->arg[ft_strlen(s->arg) + 1] = '\0';
	free (tmp);
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
	if (ac > 2) // si hay más de 2 args me joinea los args y me los convierte en uno solo.
		join_args(&s, &av[1]);
	if (ac == 2)
		s.arg = av[1]; // Si hay 2 args, guardo todo en uno y empiezo a check args.
	//antes de hacer el chequeo de los argumentos tengo que hacer bien los join
	check_args(&s); // chequeo los argumentos (FINISHED?¿?¿)
	printf("Me he pasado el juego\n");
	//Ahora a meter los args en las listas
	//Luego a mirar a ver si están ordenados
	return (0);
}

//  2147483647, -2147483648
