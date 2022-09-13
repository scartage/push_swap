
#include "mini_swap.h"

int  move_to_complete(t_array *stack_a, t_array *stack_b, int argc, char **argv)
{
	int i;

	
	/*STACK_A*/
	stack_a->len = argc - 1;
	stack_a->array = malloc(sizeof(int) * stack_a->len);
	if (stack_a->array == NULL)
		return (ft_perror("fallo reserva"));

	/*parte encargada de llenar el stack_a*/
	i = 1;
	while (i <= stack_a->len)
	{
		stack_a->array[i - 1] = atoi(argv[i]);
		i++;
	}
	
	/*STACK_B*/
	stack_b->len = argc - 1;
	stack_b->array = malloc(sizeof(int) * stack_b->len);
	if (stack_b->array == NULL)
		return (ft_perror("fallo en reserva stack_b"));

	/*el stack_b comienza estando vacio*/

	stack_b->array[0] = 69;
	stack_b->array[1] = 13;
	stack_b->array[2] = 14;
	stack_b->array[3] = 1;
	stack_b->array[4] = 9;
	/*los numeros de arriba son solo 
	 * para USO PRACTICO*/

	return (0);
}
