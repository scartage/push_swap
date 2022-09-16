/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_algoritmos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:39:56 by scartage          #+#    #+#             */
/*   Updated: 2022/09/16 17:40:31 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int search_min(t_stack *stack_a)
{
	int i = 0;
	int min = stack_a->array[i];

	while (i < stack_a->len)
	{
		if (stack_a->array[i] < min)
			min = stack_a->array[i];
		i++;
	}
	return (min);
}
