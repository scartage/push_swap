#include "mini_swap.h"

 /*FUNCIONES ENCARGADAS DE MOVIMIENTOS
  * ENTRE LOS DOS STACKS*/

void	rrr(t_array *stack_a, t_array *stack_b)
{
	ft_putstr("rrr\n");
	reverse(stack_a);
	reverse(stack_b);
}

void	rrb(t_array	*stack_b)
{
	ft_putstr("rrb\n");
	reverse(stack_b);	
}

void	rra(t_array	*stack_a)
{
	ft_putstr("rra\n");
	reverse(stack_a);
}

void	rr(t_array	*stack_a, t_array	*stack_b)
{
	ft_putstr("rr\n");
	rotate(stack_a);
	rotate(stack_b);
}


void	rb(t_array	*stack_b)
{
	ft_putstr("rb\n");
	rotate(stack_b);
}

void	ra(t_array	*stack_a)
{
	ft_putstr("ra\n");
	rotate(stack_a);
}

void	pb(t_array *stack_a, t_array *stack_b)
{
	int aux;

	ft_putstr("pb\n");
	aux = stack_a->array[0];
	elementosStack_arriba(stack_a, 0);
	elementosStack_abajo(stack_b, 0);
	stack_b->array[0] = aux;
}

void	pa(t_array *stack_b, t_array *stack_a)
{
	int aux;

	ft_putstr("pa\n");
	aux = stack_b->array[0];
	elementosStack_arriba(stack_b, 0);
	elementosStack_abajo(stack_a, 0);
	stack_a->array[0] = aux;
}

void 	ss(t_array *stack_a, t_array *stack_b)
{
	ft_putstr("ss\n");
	if (stack_a->len > 1 && stack_b->len > 1)
	{
		ft_aux_swap(stack_a);
		ft_aux_swap(stack_b);
	}
}

void	sb(t_array *stack_b)
{
	ft_putstr("sb\n");
	if (stack_b->len > 1)
		ft_aux_swap(stack_b);
}

void	sa(t_array *stack_a)
{
	ft_putstr("sa\n");
	if (stack_a->len > 1)
		ft_aux_swap(stack_a);

}
