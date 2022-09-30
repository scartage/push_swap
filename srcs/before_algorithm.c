/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:09:01 by scartage          #+#    #+#             */
/*   Updated: 2022/09/30 14:12:46 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Aqui, con la ayuda del stack_d, se vuelve a rellenar el stack_a, 
 * esta vez no con numeros (en valores) sino en numeros (por posiciones)
 *
 * No se mira si: 5 3 2 1 4
 * sino:		  4 2 1 0 3*/
void	game_index(int *array, int len, t_stack *stack_a)
{
	int	counter_g;
	int	counter_s;
	int	nbr;

	counter_g = 0;
	nbr = 0;
	while (counter_g < len)
	{
		nbr = 0;
		counter_s = 0;
		while (counter_s < len)
		{
			if (array[counter_g] > array[counter_s])
				nbr++;
			counter_s++;
		}
		stack_a->array[counter_g] = nbr;
		counter_g++;
	}
}

/*Nos iguala el contenido de stack_a en el stack_d (auxiliar)*/
void	equal_stacks(t_stack *stack_a, t_stack *stack_d)
{
	int	i;

	i = 0;
	while (i < stack_a->len)
	{
		stack_d->array[i] = stack_a->array[i];
		i++;
	}
}

void	hidden_sort(t_stack *stack_a, t_stack *stack_d)
{
	equal_stacks(stack_a, stack_d);
	game_index(stack_d->array, stack_d->len, stack_a);
}
