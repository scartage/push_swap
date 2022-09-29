/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliaresMovimientos.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:11:22 by scartage          #+#    #+#             */
/*   Updated: 2022/09/29 19:40:06 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	/*AUXILIARES DE MOVIMIENTOS*/
void	reverse(t_stack *stack)
{
	int	aux;
	int	len_aux;

	len_aux = stack->len;
	aux = stack->array[len_aux - 1];
	elementosStack_abajo(stack, 1);
	stack->array[0] = aux;
}

void	rotate(t_stack	*stack)
{
	int	aux;
	int	len_aux;

	aux = stack->array[0];
	len_aux = stack->len;
	elementosStack_arriba(stack, 1);
	stack->array[len_aux - 1] = aux;
}

/*Aux de pa, pb*/
void	elementosStack_arriba(t_stack *stack, int mode)
{
	int	i;

	i = 0;
	while (i < stack->len - 1)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	if (mode == 0)
		stack->len--;
}

void	elementosStack_abajo(t_stack *stack, int mode)
{
	int	len_aux;

	len_aux = stack->len;
	while (len_aux)
	{
		stack->array[len_aux] = stack->array[len_aux - 1];
		len_aux--;
	}
	if (mode == 0)
		stack->len++;
}

/*Aux sa, sb y ss*/
void	ft_aux_swap(t_stack *stack)
{
	int	aux;

	aux = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = aux;
}
