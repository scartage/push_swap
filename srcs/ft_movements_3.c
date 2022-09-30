/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:12:06 by scartage          #+#    #+#             */
/*   Updated: 2022/09/30 14:11:57 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "rrr\n", 4);
	reverse(stack_a);
	reverse(stack_b);
}

/*Esta funcion deberia estar en ft_iscorrect
 * se encarga de mirar que una vez en el array
 * hay numeros, no vayan a estar repetidos*/
void	ft_check_repeat_int(t_stack *stack_a)
{
	int	i;
	int	x;

	i = 0;
	while (i < stack_a->len)
	{
		x = i + 1;
		while (x < stack_a->len)
		{
			if (stack_a->array[i] == stack_a->array[x])
				ft_perror ("Error\n");
			x++;
		}
		i++;
	}
}
