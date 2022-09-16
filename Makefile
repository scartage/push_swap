# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scartage <scartage@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 13:57:56 by scartage          #+#    #+#              #
#    Updated: 2022/09/16 17:40:58 by scartage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

RM 			= rm -f
RMDIR 		= rm -rf


#tengo problemas al hacer libft.h, ya que me vuelve a compilar los punto c del push_swap
INCLUDES_H	= srcs/push_swap.h	\

SRCS		= 	main.c ft_iscorrect.c ft_movements.c	\
				ft_movements_2.c	inicializando_stacks.c	\
			   	auxiliaresGenerales.c auxiliaresMovimientos.c \
				algoritmo.c	aux_algoritmos.c

INCLUDES 	= libft/libft.a \

OBJ_DIR		= obj
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

vpath %.c srcs 
.SECONDEXPANSION:

all: make_libs	$(NAME)

make_libs:
		make -C libft

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c  $(OBJ_DIR) $(INCLUDES_H)
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(OBJ_DIR)
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

clean:
		make clean -C libft
		$(RM) $(OBJS)

fclean: clean
		make fclean -C libft
		$(RM) $(NAME)
		$(RMDIR) $(OBJ_DIR)
		
test: make_libs	${NAME}
	./${NAME} 12 45 78 23 5

leaks: $(NAME)
		leaks -atExit -- ./$(NAME) 1 2 3 8
#		valgrind --leak-check=yes ./$(NAME) `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`

re: fclean all

.PHONY: all clean fclean re leaks
