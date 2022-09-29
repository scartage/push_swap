/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxErrores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:02:22 by scartage          #+#    #+#             */
/*   Updated: 2022/09/29 20:06:49 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_put_cherror(char c)
{
	write(2, &c, 1);
}

static void	ft_put_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_put_cherror(str[i]);
		i++;
	}
}

int	ft_perror(char *str)
{
	ft_put_error(str);
	exit(-1);
}
