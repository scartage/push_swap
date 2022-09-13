#include "mini_swap.h"

/*para escribir str en pantalla*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

/*para mostrar en pantalla la informacion del los stacks*/
void	recorrido_array(t_array *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
		printf("%d\n", stack->array[i++]);
}

/*gestion de errores*/
int	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
