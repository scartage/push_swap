/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:17:14 by scartage          #+#    #+#             */
/*   Updated: 2022/09/27 16:11:03 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_stack stack_d;
	int confirm;

	if (argc < 2)
		exit(EXIT_FAILURE);

	move_to_complete(&stack_a, &stack_b, &stack_d,  argc - 1);
	ft_iscorrect(argc, argv, &stack_a);

	confirm = is_sorted(&stack_a); 
	if (confirm == 0)
		exit(EXIT_SUCCESS);
	hidden_sort(&stack_a, &stack_b,  &stack_d);		
	algoritmo(&stack_a, &stack_b);
	memory_free(&stack_a, &stack_b);

	return (0);
}
