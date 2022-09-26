/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:45:39 by scartage          #+#    #+#             */
/*   Updated: 2022/09/26 19:38:59 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*funcion para crear montones ordenados en el stack_b*/
static void	get_chunks(t_stack *stack_a, t_stack *stack_b, int chunk, int limit)
{
	while (get_chunk_number(stack_a, chunk, limit) > 0)
	{
		if (stack_a->array[0] >= (chunk * limit) && stack_a->array[0] < (chunk * limit) + limit)
		{
			pb (stack_a, stack_b);
			if (get_chunk_number(stack_a, chunk, limit) % 2 == 0 && chunk > 0)
				rb(stack_b);		//ponemos el ultimo valor en stack_b en primera posicion
		}
		else if (stack_a->array[0] > stack_a->array[1] && stack_b->array[1] > stack_b->array[0])
			ss(stack_a, stack_b);	//en caso que los dos primeros de los stacks esten invertidos
		else if (position_right_chunk(stack_a, chunk, limit) > stack_a->len / 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
}

/*probando solo para numeros menores a 100,
 * faltan numeros mayores*/
static int how_many_chunks(int len)
{
	int q_chunks = 0;

	if (len > 200)
		q_chunks = 13;
	else if (len > 10)
		q_chunks = 4;
	else
		q_chunks = 2;
	return (q_chunks);
}

/*prueba para empezar a ordenar por montones*/
void big_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	int chunk;
	int hM_chunks;
	int limit;
	int find;

	chunk = 0;
	hM_chunks = how_many_chunks(stack_a->len);
	limit = stack_a->len / hM_chunks;
	while (chunk < limit)
	{
		get_chunks(stack_a, stack_b, chunk, limit);  //chunk (del 0 al 3), limit(25)
		mostrar_stacks(stack_a, stack_b, 0);
		chunk++;
	}	
	while (stack_b->len > 0)
	{
		find = search_max(stack_b);
		while (stack_b->array[0] != find)
		{
			if (position_right(stack_b, find) > stack_b->len / 2)
				rrb(stack_b);
			else
				rb(stack_b);
		}
		pa(stack_b, stack_a);
	}
}
