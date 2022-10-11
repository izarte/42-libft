BIN			=	./bin/

DEV-FLAGS	= -Wall -Wextra

FLAGS		= ${DEV-FLAGS} -Werror

SRCS		=	ft_isalpha.c 	\
				ft_isdigit.c 	\
				ft_isalnum.c 	\
				ft_isascii.c 	\
				ft_isprint.c 	\
				ft_strlen.c		\
				ft_toupper.c	\
				ft_tolower.c	\
				ft_strchr.c		\
				ft_strrchr.c	\
				ft_strncmp.c	\
				ft_memset.c		\
				ft_bzero.c		\
				ft_memchr.c		\
				ft_memcpy.c		\
				ft_memcmp.c

OBJS_NO_BIN		= ${SRCS:.c=.o}

OBJS		= $(addprefix ${BIN}, ${OBJS_NO_BIN})

CC			= gcc

NAME		= libft.a

COMPILE.C	= ${CC} ${FLAGS} -c

OUTPUT_OPT	= -o $@

RM			= rm -f

${NAME}:	${OBJS}
		ar rcs ${NAME} ${OBJS}

print:
		echo ${OBJS}

bin/%.o:	%.c
	${COMPILE.C} $< -o $@

main:	${NAME}
	${COMPILE.C} main.c \
	${CC} ${FLAGS} ${NAME} main.o -o exec.o

test:	${NAME} c_test
	rm -f a.out
	${CC} ${DEV-FLAGS} bin/test.o -L. -lft && ./a.out

c_test: ${ARGS}
	${CC} ${DEV-FLAGS} -c ${ARGS} -o bin/test.o \
	

clean:
		${RM} ${OBJS} *.o a.out

fclean:	clean
		${RM} ${NAME}


.PHONY	= clean fclean
