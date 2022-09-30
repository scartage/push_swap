/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritmo_and_small_algorithm.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:41:25 by scartage          #+#    #+#             */
/*   Updated: 2022/09/30 14:04:41 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *stack_a)
{
	if (stack_a->array[0] > stack_a->array[1])
		sa(stack_a);
}

/*La funcion auxiliar move_sort_3 esta en auxiliaresGenerales*/
void	sort_3(t_stack *stack_a)
{
	move_sort_3(stack_a);
}

void	sort_4(t_stack *stack_a, t_stack *stack_b)
{
	int	nb_min;

	nb_min = search_min(stack_a);
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
		pb(stack_a, stack_b);
	}
	else if (nb_min == stack_a->array[3])
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}	
	sort_3(stack_a);
	pa(stack_b, stack_a);
}

/*La funcion auxliar move_sort_5 se encuentra en auxiliareaGenerales,
se encarga de mover los mnumeros dependiendo donde esta el nb_min*/
void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	nb_min;

	nb_min = search_min(stack_a);
	move_sort_5(nb_min, stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_b, stack_a);
}

void	algoritmo(t_stack *stack_a, t_stack *stack_b)
{	
	if (stack_a->len == 2)
		sort_2(stack_a);
	else if (stack_a->len == 3)
		sort_3(stack_a);
	else if (stack_a->len == 4)
		sort_4(stack_a, stack_b);
	else if (stack_a->len == 5)
		sort_5(stack_a, stack_b);
	else
		big_algorithm(stack_a, stack_b);
}
