#include "push_swap.h"

void sort_3(t_stack *stack_a)
{
	if (stack_a->array[0] > stack_a->array[1] && stack_a->array[1] < stack_a->array[2] && stack_a->array[2] > stack_a->array[0])
		sa(stack_a);
	
	else if (stack_a->array[0] > stack_a->array[1] && stack_a->array[1] > stack_a->array[2] && stack_a->array[2] < stack_a->array[0])
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (stack_a->array[0] > stack_a->array[1] && stack_a->array[1] < stack_a->array[2] && stack_a->array[2] < stack_a->array[0])
		ra(stack_a);

	else if (stack_a->array[0] < stack_a->array[1] && stack_a->array[1] > stack_a->array[2] && stack_a->array[2] > stack_a->array[0])
	{
		sa(stack_a);
		ra(stack_a);
	}

	else if (stack_a->array[0] < stack_a->array[1] && stack_a->array[1] > stack_a->array[2] && stack_a->array[2] < stack_a->array[0])
		rra(stack_a);
}

int search_min(t_stack *stack_a)
{
	int i = 0;
	int min = stack_a->array[i];

	while (i < stack_a->len)
	{
		if (stack_a->array[i] < min)
			min = stack_a->array[i];
		i++;
	}
	return (min);
}

void sort_4(t_stack *stack_a, t_stack *stack_b)
{
	int nb_min = 0;

	nb_min = search_min(stack_a);
	if (nb_min == stack_a->array[0])
		pb(stack_a, stack_b);
	else if (nb_min == stack_a->array[1])
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (nb_min == stack_a->array[2])
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (nb_min == stack_a->array[3])
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}	
	sort_3(stack_a);
	pa(stack_b, stack_a);
}

void sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int nb_min = 0;

	nb_min = search_min(stack_a);
	if (nb_min == stack_a->array[0])
		pb(stack_a, stack_b);
	else if (nb_min == stack_a->array[1])
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (nb_min == stack_a->array[2])
	{
		rra(stack_a);
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (nb_min == stack_a->array[3])
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (nb_min == stack_a->array[4])
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_4(stack_a, stack_b);
	//ra(stack_a);
	pa(stack_b, stack_a);
	//ra(stack_a);
}

void	aux_algoritmo(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	if (stack_a->len == 3)
		sort_3(stack_a);
	else if (stack_a->len == 4)
		sort_4(stack_a, stack_b);
	else if (stack_a->len == 5)
		sort_5(stack_a, stack_b);
	else
		printf("solo ordeno hasta 5 xd \n");
}
