BIN			=	./bin/

FLAGS		= -Wall -Wextra -Werror

SRCS		=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c

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
	${COMPILE.C} -o $@ $<

main:	${NAME}
	${CC} ${COMPILE.C} -c main.c \
	${CC} ${FLAGS} ${NAME} main.o -o exec.o

clean:
		${RM} ${OBJS} *.o

fclean:	clean
		${RM} ${NAME}


.PHONY	= clean fclean
