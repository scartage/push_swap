/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incializando_stacks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:45:38 by scartage          #+#    #+#             */
/*   Updated: 2022/09/26 18:40:49 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *stack_a)
{
	int i;

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

int  move_to_complete(t_stack *stack_a, t_stack *stack_b, t_stack *stack_d, int len)
{
	/*STACK_A*/
	stack_a->len = len;
	stack_a->array = malloc(sizeof(int) * len);
	if (stack_a->array == NULL)
		return (ft_perror("fallo reserva"));

	/*STACK_B*/
	stack_b->len = 0;
	stack_b->array = malloc(sizeof(int) * len);
	if (stack_b->array == NULL)
	{
		free(stack_a->array);
		return (ft_perror("fallo en reserva stack_b"));
	}

	/*el stack_b comienza estando vacio*/
	stack_d->len = len;
	stack_d->array = malloc(sizeof(int) * len);
	if (stack_d->array == NULL)
	{
		free(stack_a->array);
		free(stack_b->array);
		return (ft_perror("fallo en reserva stack_b"));
	}
	/*el stack_d tambien comienza vacio*/
	return (0);
}
