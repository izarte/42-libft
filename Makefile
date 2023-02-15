BIN			=	bin/

BIN_TEST	= bin/tests/

DEV-FLAGS	= -Wall -Wextra

FLAGS		= ${DEV-FLAGS} -Werror

LIBC_PATH	= libc/

LIBC_SRC	=	ft_isalpha.c 	\
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
				ft_memmove.c	\
				ft_memcmp.c		\
				ft_strnstr.c	\
				ft_atoi.c		\
				ft_strlcpy.c	\
				ft_strlcat.c	\
				ft_calloc.c		\
				ft_strdup.c

ADITIONAL_PATH	= aditional/
ADITIONAL_SRC	= ft_substr.c

OBJS_NO_BIN		= ${SRCS:.c=.o}

LIBC		= $(addprefix ${LIBC_PATH}, ${LIBC_SRC})
ADITIONAL	= $(addprefix ${ADITIONAL_PATH}, ${ADITIONAL_SRC})
SRCS			= ${LIBC} ${ADITIONAL}

OBJS		= $(addprefix ${BIN}, ${OBJS_NO_BIN})

T  = tests/test_

TESTS_SRCS	= $(addprefix ${T}, ${SRCS})
TESTS_NO_BIN = ${TESTS_SRCS:.c=.o}
TESTS_OBJS  = $(addprefix ${BIN}, ${TESTS_NO_BIN})

CC			= gcc

NAME		= libft.a

COMPILE.C	= ${CC} ${FLAGS} -c

OUTPUT_OPT	= -o $@

RM			= rm -f


${NAME}:	${OBJS}
	@	ar rcs ${NAME} ${OBJS}
	@	echo "Succesfully created ${NAME}"

bin/%.o:	%.c
	@	echo "$< OK"
	@	${COMPILE.C} $< -o $@

bin/tests/%.o: tests/%.c
	@	echo "$< OK"
	@	${CC} ${DEV-FLAGS} $< -o $@ -L. -lft 

test:	${NAME} ${TESTS_OBJS} ${OBJS}
	@	for file in ${TESTS_OBJS}; do \
			./$$file; \
		done

print:
	@	echo "${SRCS}"

clean:
	@	${RM} ${OBJS} ${TESTS_OBJS} *.o a.out
	@	echo "Succesfully deleted objects"

fclean:	clean
	@:	${RM} ${NAME}
	@	echo "Succesfully deleted library"


.PHONY	= clean fclean
