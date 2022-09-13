#ifndef MINI_SWAP_H
# define MINI_SWAP_H

#include <unistd.h>		/*write*/
#include <stdio.h>  	/*printf*/
#include <strings.h> 	/*para el atoi*/
#include <stdlib.h>		/*para el perror y el exit*/

typedef struct s_stack
{
	int len;
	int *array;
}		t_array; 		//ojo que en el PS es t_stack;

void	sa(t_array	*stack_a);
void	sb(t_array	*stack_b);
void 	ss(t_array	*stack_a, t_array *stack_b);

void	pb(t_array	*stack_a, t_array *stack_b);
void	pa(t_array	*stack_b, t_array *stack_a);
void	ra(t_array	*stack_a);
void	rb(t_array	*stack_b);
void	rr(t_array	*stack_a, t_array	*stack_b);
void	rra(t_array	*stack_a);
void	rrb(t_array	*stack_b);
void	rrr(t_array	*stack_a, t_array *stack_b);

 /*aux de sa, sb y ss*/
void	ft_aux_swap(t_array *stack);

/*auxiliares de pb, pa, ra, rb, rra y rrb
 * se les agrego la opcion de restar/sumar
 * un elemento, dependiendo si el paramentreo (mood)
 * es (1) o (0), con el objetivo de usar las funciones en mas casos*/
void 	elementosStack_arriba(t_array	*stack, int mode);
void	elementosStack_abajo(t_array	*stack, int mode);
void	rotate(t_array	*stack);
void	reverse(t_array *stack);

/*auxiliares generales*/
int ft_perror(char	*str);
int move_to_complete(t_array *stack_a, t_array *stack_b, int argc, char **argv);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	recorrido_array(t_array *stack);

#endif
