/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliaresGenerales.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:53:06 by scartage          #+#    #+#             */
/*   Updated: 2022/09/30 14:16:54 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Funcion porque a norminette no le gusta tener todo en una sola funcion.
esta pertenece a move_sort_3, para ordenar 3 numeros*/
static void	move_other_sort_3(t_stack *stack_a)
{
	if (stack_a->array[0] < stack_a->array[1]
		&& stack_a->array[1] > stack_a->array[2]
		&& stack_a->array[2] > stack_a->array[0])
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (stack_a->array[0] < stack_a->array[1]
		&& stack_a->array[1] > stack_a->array[2]
		&& stack_a->array[2] < stack_a->array[0])
		rra(stack_a);
}

void	move_sort_3(t_stack *stack_a)
{
	if (stack_a->array[0] > stack_a->array[1]
		&& stack_a->array[1] < stack_a->array[2]
		&& stack_a->array[2] > stack_a->array[0])
		sa(stack_a);
	else if (stack_a->array[0] > stack_a->array[1]
		&& stack_a->array[1] > stack_a->array[2]
		&& stack_a->array[2] < stack_a->array[0])
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (stack_a->array[0] > stack_a->array[1]
		&& stack_a->array[1] < stack_a->array[2]
		&& stack_a->array[2] < stack_a->array[0])
		ra(stack_a);
	else
		move_other_sort_3(stack_a);
}

void	move_sort_5(int nb_min, t_stack *stack_a, t_stack *stack_b)
{
	if (nb_min == stack_a->array[0])
		pb(stack_a, stack_b);
	else if (nb_min == stack_a->array[1])
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (nb_min == stack_a->array[2])
	{
		rra(stack_a);
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (nb_min == stack_a->array[3])
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (nb_min == stack_a->array[4])
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
}

/*liberar memoria*/
void	memory_free(t_stack *stack_a, t_stack *stack_b, t_stack *stack_d)
{
	if (stack_a->array)
		free(stack_a->array);
	if (stack_b->array)
		free(stack_b->array);
	if (stack_d->array)
		free(stack_d->array);
	exit(0);
}
