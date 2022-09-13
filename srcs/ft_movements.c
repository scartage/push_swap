/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:20:02 by scartage          #+#    #+#             */
/*   Updated: 2022/06/27 20:29:29 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Aqui se programan los movimientos de arrays*/
 
	/*SA, SB, SS, PA Y PB*/
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int aux;

	ft_putstr("pb\n");
	aux = stack_a->array[0];
	elementosStack_arriba(stack_a, 0);
	elementosStack_abajo(stack_b, 0);
	stack_b->array[0] = aux;
}

void	pa(t_stack *stack_b, t_stack *stack_a)
{
	int aux;

	ft_putstr("pa\n");
	aux = stack_b->array[0];
	elementosStack_arriba(stack_b, 0);
	elementosStack_abajo(stack_a, 0);
	stack_a->array[0] = aux;
}

void 	ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr("ss\n");
	if (stack_a->len > 1 && stack_b->len > 1)
	{
		ft_aux_swap(stack_a);
		ft_aux_swap(stack_b);
	}
}

void	sb(t_stack *stack_b)
{
	ft_putstr("sb\n");
	if (stack_b->len > 1)
		ft_aux_swap(stack_b);
}

void	sa(t_stack *stack_a)
{
	ft_putstr("sa\n");
	if (stack_a->len > 1)
		ft_aux_swap(stack_a);

}
