/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscorrect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:55:47 by scartage          #+#    #+#             */
/*   Updated: 2022/07/08 18:02:52 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*esta funcion se puede optimizar, dejando de usar tantas veces el atoi.
 * se puede guardar directamente el int en el stack, y luego comprobar en el mismo stack
 * que no hayan duplicados
 * */

static int  check_repeat(int len, char **argv) //argc y argv
{
    int y;
    int x;
    int r;

    r = 0;	//valor a devolver
    x = 1;
    while (x < len)
    {
        y = x + 1;
        while (y < len)
        {
            if (ft_strequal(argv[x], argv[y]) == 1)  //hay un duplicado
                r++;
            y++;
        }
        x++;
    }
    return (r);
}

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

/* Comprobamos que los datos almacenados en argv sean digitos. */
 
void	ft_yes_isdigit(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			i++;
		if (ft_isdigit(str[i++]) != 1)
			ft_perror("Error: hay argumentos que no son digitos\n");
	}
}

/*comprobamos que los datos son menores que un INT_MAX*/

void	ft_is_int(char *str)
{
	if (ft_check_atoi(str) == 1)
		ft_perror("Error: hay aun dato mayor  o menor a int\n");
}

/*
 * Funcion para comprobar los datos pasados como parametro.
 * Primero se comprueba que los datos pasados como parametro sean digitos.
 * 
 * check_repeat(); revisa si los argv (en str) no estan duplicados,
 * en caso de que no, pasamos a rellenar el stack.
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
		ft_rellena_stack_a(argc, argv, stack_a);
	else
		ft_perror("Error: hay un valor duplicado\n");	 
}

