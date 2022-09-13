/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:17:14 by scartage          #+#    #+#             */
/*   Updated: 2022/07/08 18:41:14 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	/*funcion TEMPORALI para ver los stacks antes y despues*/
void	mostrar_stacks(t_stack *stack_a, t_stack *stack_b, int mode)
{
	if (mode == 0)
	{
		ft_putstr("stack_a: \n");
		recorrido_array(stack_a);
		ft_putstr("stack_b: \n");
		recorrido_array(stack_b);
	}
	else if (mode == 1)
	{
		ft_putstr("stack_a despues de movimientos: \n");
		recorrido_array(stack_a);
		ft_putstr("stack_b despues de movimientos: \n");
		recorrido_array(stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int confirm;

	if (argc < 2)
		exit(EXIT_FAILURE);
	confirm = move_to_complete(&stack_a, &stack_b, argc); //inicializa stacks
	if (confirm == 0)
	{
		ft_iscorrect(argc, argv, &stack_a); //revisamos y rellenamos stack
		ft_putstr("los parametros pasan los checkers\n");
		/*para ir probando con stack_b*/
		stack_b.array[0] = 12;
		stack_b.array[1] = 13;
		stack_b.array[2] = 14;

		mostrar_stacks(&stack_a, &stack_b, 0);	//show stacks antes
			
		ft_putstr("-- Comienzan los movimietos entre stacks: \n");
		confirm = is_sorted(&stack_a); //para revisar si el stack esta ordenado
		if (confirm == 0)
		{
			ft_putstr("los argumentos estan ordenados.\n");
			exit(EXIT_SUCCESS);
		}
		else
			ft_putstr("Stack desordenado. Comienza el algoritmo:\n");	
		mostrar_stacks(&stack_a, &stack_b, 1);	//show stacks despues
		memory_free(&stack_a, &stack_b);
	}
	else
		ft_perror("fallo en el proceso");
	return (0);
}
