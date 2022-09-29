/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliaresGenerales.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:53:06 by scartage          #+#    #+#             */
/*   Updated: 2022/09/29 19:50:09 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*para escribir str en pantalla*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
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
