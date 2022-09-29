/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:45:39 by scartage          #+#    #+#             */
/*   Updated: 2022/09/29 20:21:51 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*funcion para crear montones ordenados en el stack_b*/
static void	get_chunks(t_stack *stack_a, t_stack *stack_b, int chunk, int limit)
{
	while (get_chunk_number(stack_a, chunk, limit) > 0)
	{
		if (stack_a->array[0] >= (chunk * limit)
			&& stack_a->array[0] < (chunk * limit) + limit)
		{
			pb (stack_a, stack_b);
			if (get_chunk_number(stack_a, chunk, limit) % 2 == 0 && chunk > 0)
				rb(stack_b);
		}
		else if (stack_a->array[0] > stack_a->array[1]
			&& stack_b->array[1] > stack_b->array[0])
			ss(stack_a, stack_b);
		else if (position_right_chunk(stack_a, chunk, limit) > stack_a->len / 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
}

static int	how_many_chunks(int len)
{
	int	q_chunks;

	q_chunks = 0;
	if (len > 200)
		q_chunks = 13;
	else if (len > 10)
		q_chunks = 7;
	else
		q_chunks = 2;
	return (q_chunks);
}

void	big_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk;
	int	hm_chunks;
	int	limit;
	int	max_num;

	chunk = 0;
	hm_chunks = how_many_chunks(stack_a->len);
	limit = stack_a->len / hm_chunks;
	while (chunk < limit)
	{
		get_chunks(stack_a, stack_b, chunk, limit);
		chunk++;
	}	
	while (stack_b->len > 0)
	{
		max_num = search_max(stack_b);
		while (stack_b->array[0] != max_num)
		{
			if (position_right(stack_b, max_num) > stack_b->len / 2)
				rrb(stack_b);
			else
				rb(stack_b);
		}
		pa(stack_b, stack_a);
	}
}
