/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliaresGenerales.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:53:06 by scartage          #+#    #+#             */
/*   Updated: 2022/07/06 15:10:53 by scartage         ###   ########.fr       */
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
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

/*para mostrar en pantalla la informacion del los stacks*/
void	recorrido_array(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
		printf("%d\n", stack->array[i++]);
}

/*liberar memoria*/
void	memory_free(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->array);
	free(stack_b->array);
}

/*gestion de errores*/
int	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
