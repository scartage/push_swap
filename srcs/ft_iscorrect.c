/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscorrect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:55:47 by scartage          #+#    #+#             */
/*   Updated: 2022/09/27 19:20:17 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_check_repeat_int(t_stack *stack_a)
{
	int i = 0;
	int x;

	while (i < stack_a->len)
	{
		x = i + 1;
		while (x < stack_a->len)
		{
			if (stack_a->array[i] == stack_a->array[x])
				ft_perror ("Error\n");
			x++;
		}
		i++;
	}
}

/*Esta funcion revisa que no hayan "numeros" repetidos en argv
 * r es la variable que devolvemos, tiene que ser 0 para saber
 * que no hay valores repetidos*/
static int  check_repeat(int len, char **argv)
{
    int y;
    int x;
    int r;

    r = 0;
	x = 1;
    while (x < len)
    {
        y = x + 1;
        while (y < len)
        {
            if (ft_strequal(argv[x], argv[y]) == 1)
                r++;
            y++;
        }
        x++;
    }
    return (r);
}

/*Con esta funcion empezamos a rellenar el stack_a con numeros*/
void	ft_rellena_stack_a(int argc, char **matriz, t_stack *stack_a)
{
	int i;
	int aux_number;
	int j;

	j = 0;
	i = 1;
	aux_number = 0;
	while (i < argc)
	{	
		aux_number = ft_atoi(matriz[i]);
		stack_a->array[i - 1]  = aux_number;
		i++;
	}
}

/* Comprobamos que los datos almacenados en argv sean digitos*/
void	ft_yes_isdigit(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			i++;
		if (ft_isdigit(str[i++]) != 1)
			ft_perror("Error\n");
	}
}

/*comprobamos que los datos son menores que un INT_MAX
 *y mayores que un INT_MIN*/
void	ft_is_int(char *str)
{
	if (ft_check_atoi(str) == 1)
		ft_perror("Error\n");
}

/*
 * Funcion para comprobar los datos pasados como parametro.
 * Primero se comprueba que los datos pasados como parametro sean digitos.
 * 
 * check_repeat(); revisa si los argv (en str) no estan duplicados,
 * en caso de que no, pasamos a rellenar el stack, cada valor pasa
 * de ser un char a un int.
 */
void ft_iscorrect(int argc, char **argv, t_stack *stack_a)
{
	int i;

	i = 1;
	while (i < argc)
		ft_yes_isdigit(argv[i++]);
	i = 1;
	while (i < argc)
		ft_is_int(argv[i++]);
	if (check_repeat(argc, argv) == 0)
	{
		ft_rellena_stack_a(argc, argv, stack_a);
		ft_check_repeat_int(stack_a);
	}
	else
		ft_perror("Error\n");	 
}

