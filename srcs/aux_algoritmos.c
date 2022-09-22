/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_algoritmos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:39:56 by scartage          #+#    #+#             */
/*   Updated: 2022/09/22 18:23:52 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int position_right_chunk(t_stack *stack, int chunk, int limit)
{
	int i = 0;

	while (i < stack->len && !(stack->array[i] >= (chunk * limit) &&
				stack->array[i] < (chunk * limit) + limit))
		i++;
	return (i);
}

/*va de 0 hasta el len en busca del numero (find) y te dice cuantos caracteres hay hasta este*/
int position_right(t_stack *stack, int find)
{
	int i = 0;

	while (i < stack->len && stack->array[i] != find)
		i++;
	return (i);
}

/*para saber la cantidad de numeros que se obtiene de un monton*/
int get_chunk_number(t_stack *stack, int chunk, int limit)
{
	int i = 0;
	int x = 0;

	while (i < stack->len)
	{
		if (stack->array[i] >= (chunk * limit) && stack->array[i] < (chunk * limit) + limit)
			x++;
		i++;
	}
	return (x);
}

int search_max(t_stack *stack)
{
	int i = 0;
	int max = stack->array[i];

	while (i < stack->len)
	{
		if (stack->array[i] > max)
			max = stack->array[i];
		i++;
	}
	return (max);
}

int search_min(t_stack *stack)
{
	int i = 0;
	int min = stack->array[i];

	while (i < stack->len)
	{
		if (stack->array[i] < min)
			min = stack->array[i];
		i++;
	}
	return (min);
}
