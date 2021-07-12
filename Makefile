
NAME	= UTest 

SRC		= main.c src/utest.c
OBJ		= ${SRC;.c=.o}
 
BUILD	= build/

CC		= gcc
RM		= rm -f

LIBRARY	=

INCLUDE = src/utest.h

CFLAGS	= -Wextra -Werror ${INCLUDE}

${NAME}:	${OBJ}
			@${CC} -o ${BUILD}${NAME} ${CFLAGS} ${SRC} ${LIBRARY}
			@./${BUILD}${NAME}

all:		${NAME}

debug:		${OBJ}
			@${CC} -g -o ${BUILD}${NAME} ${CFLAGS} ${SRC}

dry-run:
			@${CC} -o ${BUILD}${NAME} ${SRC}
			@./${BUILD}${NAME}

clean:		
			@${RM} ${OBJ}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

run:		re
			@./${BUILD}${NAME}

test:		
			@${CC} 

.PHONY 	=	all clean fclean re src run test dry-run
