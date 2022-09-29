# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scartage <scartage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 13:57:56 by scartage          #+#    #+#              #
#    Updated: 2022/09/29 20:15:38 by scartage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= gcc
CFLAGS		=  -g -Wall -Wextra -Werror   
# -fsanitize=address


RM 			= rm -f
RMDIR 		= rm -rf


#tengo problemas al hacer libft.h, ya que me vuelve a compilar los punto c del push_swap
INCLUDES_H	= srcs/push_swap.h	\

SRCS		= 	main.c ft_iscorrect.c ft_movements.c	\
				ft_movements_2.c ft_movements_3.c	\
				inicializando_stacks.c	\
			   	auxiliaresGenerales.c auxiliaresMovimientos.c \
				algoritmo_and_small_algorithm.c	aux_algoritmos.c \
				before_algorithm.c big_algorithm.c	auxErrores.c

INCLUDES 	= libft/libft.a

OBJ_DIR		= obj
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

vpath %.c srcs 
.SECONDEXPANSION:

$(OBJ_DIR)/%.o: %.c $(INCLUDES_H) Makefile
		$(CC) $(CFLAGS) -c $< -o $@


all: make_libs make_dir  $(NAME)

make_libs:
		make -C libft

make_dir:
	@mkdir -p $(OBJ_DIR)

$(NAME):	$(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

clean:
		make clean -C libft
		$(RM) $(OBJS)

fclean: clean
		make fclean -C libft
		$(RM) $(NAME)
		$(RMDIR) $(OBJ_DIR)
		
test: make_libs	${NAME}
	./${NAME} 10 9 8 7 6 5 4 3 2 1

leaks: $(NAME)
		leaks -atExit -- ./$(NAME) 10 9 8 7 6 5 4 3 2 1
#		valgrind --leak-check=yes ./$(NAME) `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`

re: fclean all

.PHONY: all clean fclean re leaks
