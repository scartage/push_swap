/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:20:34 by scartage          #+#    #+#             */
/*   Updated: 2022/07/08 17:12:29 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h> 		/* printf*/
# include <stdlib.h>		/*para usar perror y exit*/

/*Hay que borrar los comentarios de los 
 ft_perror antes de entregar este proyecto*/

typedef struct s_stack
{
	int	len;
	int	*array;
}			t_stack;

/*Funciones TEMPORARES*/
void	mostrar_stacks(t_stack *stack_a, t_stack *stack_b, int mode);

/*Funcioones utiles*/
int ft_perror(char	*str);
int	move_to_complete(t_stack *stack_a, t_stack *stack_b, int argc);
int is_sorted(t_stack *stack_a);
void	memory_free(t_stack	*stack_a, t_stack	*stack_b);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	recorrido_array(t_stack *stack);


 /* ft_iscorrect: filtro que nos lleva a comprobar los parametros
  *		ft_yes_isdigit: los numeros pasados como parametro son digitos
  *		ft_no_duplicate: revisa que no hayan numeros duplicados
  *		ft_is_int:	revisa que los parametros estan entre los valores INT_MIN y INT_MAX
  */

void	ft_iscorrect(int argc, char **argv, t_stack *stack_a);
void	ft_yes_isdigit(char *str);
void	ft_is_int(char *str);
void	ft_rellena_stack_a(int argc, char **matriz, t_stack *stack_a);

void	aux_algoritmo(t_stack *stack_a, t_stack *stack_b);

 /* Funciones de movimiento */
void	sa(t_stack *stack_a);	//swap a
void	sb(t_stack *stack_b);	//swap b
void 	ss(t_stack	*stack_a, t_stack *stack_b);

void	pb(t_stack	*stack_a, t_stack *stack_b);
void	pa(t_stack	*stack_b, t_stack *stack_a);
void	ra(t_stack	*stack_a);
void	rb(t_stack	*stack_b);
void	rr(t_stack	*stack_a, t_stack	*stack_b);
void	rra(t_stack	*stack_a);
void	rrb(t_stack	*stack_b);
void	rrr(t_stack	*stack_a, t_stack *stack_b);

 /*auxiliares de sa, sb y ss*/
void	ft_aux_swap(t_stack *stack);

/*auxiliares de pb, pa, ra, rb, rra y rrb
 * se les agrego la opcion de restar/sumar
 * un elemento, dependiendo si el paramentreo (mood)
 * es (1) o (0), con el objetivo de usar las funciones en mas casos*/
void 	elementosStack_arriba(t_stack	*stack, int mode);
void	elementosStack_abajo(t_stack	*stack, int mode);
void	rotate(t_stack	*stack);
void	reverse(t_stack *stack);

#endif	
