/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicializando_stacks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:45:38 by scartage          #+#    #+#             */
/*   Updated: 2022/09/29 20:00:23 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Funcion que nos permite saber si el stack_a esta ordenado*/
int	is_sorted(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (i < (stack_a->len - 1))
	{
		if (stack_a->array[i] < stack_a->array[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

/* Asignacion a las variables de los stacks, 
 * ademas de reservar memoria dinamica para estos.
 * 
 * Tenemos 3 stacks, dos obligatorios y uno auxiliar
 * que se le da uso mas adelante*/
void	move_to_complete(t_stack *stack_a, t_stack *stack_b, t_stack *stack_d, int len)
{
	stack_a->len = len;
	stack_a->array = malloc(sizeof(int) * len);
	if (stack_a->array == NULL)
		return (exit(EXIT_FAILURE));
	stack_b->len = 0;
	stack_b->array = malloc(sizeof(int) * len);
	if (stack_b->array == NULL)
	{
		free(stack_a->array);
		return (exit(EXIT_FAILURE));
	}
	stack_d->len = len;
	stack_d->array = malloc(sizeof(int) * len);
	if (stack_d->array == NULL)
	{
		free(stack_a->array);
		free(stack_b->array);
		return (exit(EXIT_FAILURE));
	}
}
