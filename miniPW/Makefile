
NAME	= mini_swap
CC		= gcc
CFLAGS 	= -Wall -Werror -Wextra

RM		= rm -f

INCLUDES_H = mini_swap.h
SRCS 	   = main_swap.c movimientos.c completando_stacks.c	\
			 auxiliaresGenerales.c auxiliaresMovimientos.c

OBJS	=  ${SRCS:.c=.o}

all:	${NAME}

${NAME}:	${OBJS} ${INCLUDES_H} 
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
		${RM} ${OBJS}
	
fclean: clean
	${RM} ${NAME}

test: ${NAME}
	./${NAME} 12 45 78 23 5

re: fclean all 
.PHONY: all clean fclean re
