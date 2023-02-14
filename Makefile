BIN			=	./bin/

BIN_TEST	= ./bin/tests/

DEV-FLAGS	= -Wall -Wextra

FLAGS		= ${DEV-FLAGS} -Werror

SRCS		=	ft_isalpha.c 	\
				ft_isdigit.c 	\
				ft_isalnum.c 	\
				ft_isascii.c 	\
				ft_isprint.c 	\
				ft_strlen.c		\
				ft_toupper.c	\
				# ft_tolower.c	\
				# ft_strchr.c		\
				# ft_strrchr.c	\
				# ft_strncmp.c	\
				# ft_memset.c		\
				# ft_bzero.c		\
				# ft_memchr.c		\
				# ft_memcpy.c		\
				# ft_memcmp.c		\
				# ft_strstr.c		\
				# ft_atoi.c		\
				# ft_strlcpy.c	\
				# ft_strlcat.c


OBJS_NO_BIN		= ${SRCS:.c=.o}

OBJS		= $(addprefix ${BIN}, ${OBJS_NO_BIN})

T  = tests/test_

TESTS_SRCS	= $(addprefix ${T}, ${SRCS})
# TESTS_SRCS	= tests/test_ft_isdigit.c
TESTS_NO_BIN = ${TESTS_SRCS:.c=.o}
TESTS_OBJS  = $(addprefix ${BIN}, ${TESTS_NO_BIN})


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

bin/tests/%.o: tests/%.c
	${CC} ${DEV-FLAGS} $< -o $@ -L. -lft 

main:	${NAME}
	${COMPILE.C} main.c \
	${CC} ${FLAGS} ${NAME} main.o -o exec.o

test:	${NAME} ${TESTS_OBJS}
	for file in ${TESTS_OBJS}; do \
		./$$file; \
	done

clean:
		${RM} ${OBJS} ${TESTS_OBJS} *.o a.out

fclean:	clean
		${RM} ${NAME}


.PHONY	= clean fclean
