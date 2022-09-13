
#include "mini_swap.h"

/*ojo que solo se puede usar el write
 * (cremos la funcion ft_putstr para usarla)*/

int main(int argc, char **argv)
{
	int confirm;
	t_array stack_a;
	t_array	stack_b;

	confirm = move_to_complete(&stack_a, &stack_b, argc, argv);
 	if (confirm == 0)
	{
		ft_putstr("stack_a: \n");
		recorrido_array(&stack_a);
		ft_putstr("stack_b: \n");
		recorrido_array(&stack_b);

		ft_putstr("comienzan los movimietos entre stacks\n");	

		rr(&stack_a, &stack_b);

		printf("stack_a despues de movimientos: \n");
		recorrido_array(&stack_a);
		printf("stack_b despues de movimientos: \n");
		recorrido_array(&stack_b);
	}
	else
		ft_perror("fallo en el proceso");
	return (0);
}
