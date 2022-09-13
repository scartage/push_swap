/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:10:15 by scartage          #+#    #+#             */
/*   Updated: 2022/06/27 20:29:57 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

 /*FUNCIONES ENCARGADAS DE MOVIMIENTOS
  * ENTRE LOS DOS STACKS*/

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr("rrr\n");
	reverse(stack_a);
	reverse(stack_b);
}

void	rrb(t_stack	*stack_b)
{
	ft_putstr("rrb\n");
	reverse(stack_b);
}

void	rra(t_stack	*stack_a)
{
	ft_putstr("rra\n");
	reverse(stack_a);
}

void	rr(t_stack	*stack_a, t_stack	*stack_b)
{
	ft_putstr("rr\n");
	rotate(stack_a);
	rotate(stack_b);
}


void	rb(t_stack	*stack_b)
{
	ft_putstr("rb\n");
	rotate(stack_b);
}

void	ra(t_stack	*stack_a)
{
	ft_putstr("ra\n");
	rotate(stack_a);
}
