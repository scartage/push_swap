/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:45:39 by scartage          #+#    #+#             */
/*   Updated: 2022/10/04 18:59:26 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_sort_menos_100(t_stack *stack_a, t_stack *stack_b)
{
	int max_num = 0;
	
	//printf("Dentro del sort\n");
	while (stack_b->len > 0)
	{
		max_num = search_max(stack_b);
		while (stack_b->array[0] != max_num)
		{
			if (position_right(stack_b, max_num) > stack_b->len / 2)
				rrb(stack_b);
			else
				rb(stack_b);
		}
		pa(stack_b, stack_a);
	}
}


static void ft_check_b(t_stack *stack_b, int idx, int limit)
{
	if (idx < limit / 2)
		rb(stack_b);
}

/*prueba*/
static void	ft_move_menos100(t_stack *stack_a, t_stack *stack_b, int chunks)
{
	int i2;
    int limit;

	//printf("Dentro de move\n");
    limit = stack_a->len / chunks;
    while (stack_a->len)
    {
        i2 = -1;
        while (++i2 <= stack_a->len / chunks)
        {
			/*if (stack_a[i2] < cut) ??*/
            /*if (a->first->idx < cut)*/
			if (stack_a->array[i2] < limit)
            {
                pb(stack_a, stack_b);
                /*ft_at_b_stack(b, b->first->idx, cut);*/
				ft_check_b(stack_b, stack_b->array[0], limit);
                limit++;
            }
            else
                ra(stack_a);
        }
    }
    //ft_backto_a(a, b);  //pa(?)
	pa(stack_b, stack_a);
}


/*funcion para crear montones ordenados en el stack_b*/
/*static void	get_chunks(t_stack *stack_a, t_stack *stack_b, int chunk, int limit)
{
	while (get_chunk_number(stack_a, chunk, limit) > 0)
	{
		if (stack_a->array[0] >= (chunk * limit)
			&& stack_a->array[0] < (chunk * limit) + limit)
		{
			pb (stack_a, stack_b);
			if (get_chunk_number(stack_a, chunk, limit) % 2 == 0 && chunk > 0)
				rb(stack_b);
		}
		else if (stack_a->array[0] > stack_a->array[1]
			&& stack_b->array[1] > stack_b->array[0])
			ss(stack_a, stack_b);
		else if (position_right_chunk(stack_a, chunk, limit) > stack_a->len / 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
}

static int	how_many_chunks(int len)
{
	int	q_chunks;

	q_chunks = 0;
	//if (leb > 200)
	if (len > 100)
		q_chunks = 13;
	else if (len > 10 && len < 100)
		q_chunks = 7;
	else
		q_chunks = 2;
	return (q_chunks);
}*/

void	big_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	/*int	chunk;
	int	hm_chunks;
	int	limit;
	int	max_num;

	chunk = 0;*/
	//esta parte nos ordena menos de 100 numeros
	//en caso de que sean mas deberia funcionar el otro algoritmo
	//sin problema
	//printf("dentro de big\n");

	if (stack_a->len > 10 && stack_a->len < 100)
	{
		//printf("dentro del if\n");
		ft_move_menos100(stack_a, stack_b, 7);
		ft_sort_menos_100(stack_a, stack_b);
		exit(1);
	}
	/*
	else
	{
		hm_chunks = how_many_chunks(stack_a->len);
		limit = stack_a->len / hm_chunks;
		while (chunk < limit)
		{
			get_chunks(stack_a, stack_b, chunk, limit);
			chunk++;
		}
		while (stack_b->len > 0)
		{
			max_num = search_max(stack_b);
			while (stack_b->array[0] != max_num)
			{
				if (position_right(stack_b, max_num) > stack_b->len / 2)
					rrb(stack_b);
				else
					rb(stack_b);
			}
			pa(stack_b, stack_a);
		}
	}*/
}

/*OJO: todo lo que esta comentado es para poder probar el algoritmo
 * que ordena menos de 100 numeros, de momento NO funciona, literalmente
 * o no hace nada o da muchos mas movimientos que el que se encargaba de todos
 * los numeros grandes, hay que tener ese algoritmo para poder sacar 100*/
