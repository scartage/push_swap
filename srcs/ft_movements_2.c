/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:10:15 by scartage          #+#    #+#             */
/*   Updated: 2022/09/30 14:12:27 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*FUNCIONES ENCARGADAS DE MOVIMIENTOS
  * ENTRE LOS DOS STACKS*/
void	rrb(t_stack	*stack_b)
{
	write(1, "rrb\n", 4);
	reverse(stack_b);
}

void	rra(t_stack	*stack_a)
{
	write(1, "rra\n", 4);
	reverse(stack_a);
}

void	rr(t_stack	*stack_a, t_stack	*stack_b)
{
	write(1, "rr\n", 3);
	rotate(stack_a);
	rotate(stack_b);
}

void	rb(t_stack	*stack_b)
{
	write(1, "rb\n", 3);
	rotate(stack_b);
}

void	ra(t_stack	*stack_a)
{
	write(1, "ra\n", 3);
	rotate(stack_a);
}
