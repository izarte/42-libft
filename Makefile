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
ADITIONAL_SRC	=	ft_substr.c		\
					ft_strjoin.c	\
					ft_strtrim.c	\
					ft_split.c		\
					ft_itoa.c		\
					ft_strmapi.c	\
					ft_striteri.c	\
					ft_putchar_fd.c	\
					ft_putstr_fd.c	\
					ft_putendl_fd.c	\
					ft_putnbr_fd.c

BONUS_PATH	= 	bonus/
BONUS_SRC	=	ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c


OBJS_NO_BIN		= ${SRCS:.c=.o}

LIBC		= $(addprefix ${LIBC_PATH}, ${LIBC_SRC})
ADITIONAL	= $(addprefix ${ADITIONAL_PATH}, ${ADITIONAL_SRC})
BONUS	= $(addprefix ${BONUS_PATH}, ${BONUS_SRC})
SRCS			= ${LIBC} ${ADITIONAL} ${BONUS}

OBJS		= $(addprefix ${BIN}, ${OBJS_NO_BIN})

T  = tests/

TESTS_LIBC_SRC 			= $(addprefix test_, ${LIBC_SRC})
TESTS_LIBC 				= $(addprefix ${LIBC_PATH}, ${TESTS_LIBC_SRC})
TESTS_ADITIONAL_SRC 	= $(addprefix test_, ${ADITIONAL_SRC})
TESTS_ADITIONAL 		= $(addprefix ${ADITIONAL_PATH}, ${TESTS_ADITIONAL_SRC})
TESTS_BONUS_SRC 		= $(addprefix test_, ${BONUS_SRC})
TESTS_BONUS 			= $(addprefix ${BONUS_PATH}, ${TESTS_BONUS_SRC})

TEST_SRC 				= ${TESTS_LIBC} ${TESTS_ADITIONAL} ${TESTS_BONUS}

TEST_SRCS_DIR			= $(addprefix ${T}, ${TEST_SRC})
TESTS_NO_BIN 			= ${TEST_SRCS_DIR:.c=.o}
TESTS_OBJS  			= $(addprefix ${BIN}, ${TESTS_NO_BIN})

CC			= gcc

NAME		= libft.a

INCLUDE		= -I./include

COMPILE.C	= ${CC} ${FLAGS} ${INCLUDE}
DEV_COMPILE = ${CC} ${DEV-FLAGS} ${INCLUDE}

OUTPUT_OPT	= -o $@

RM			= rm -f


${NAME}:	${OBJS}
	@	ar -rcs ${NAME} ${OBJS}
	@	echo "Succesfully created ${NAME}"

bin/%.o:	%.c
	@	mkdir -p bin/libc bin/aditional bin/bonus
	@	echo "$< OK"
	@	${COMPILE.C} -c $< -o $@

bin/tests/%.o: tests/%.c
	@ 	mkdir -p bin/tests/libc bin/tests/aditional bin/tests/bonus
	@	echo "$< OK"
	@	${DEV_COMPILE} $< -o $@ -L. -lft 

test:	fclean ${NAME} ${TESTS_OBJS} ${OBJS}
	@	for file in ${TESTS_OBJS}; do \
			./$$file; \
		done

print:
	@	echo "${OBJS}"

clean:
	@	${RM} ${OBJS} ${TESTS_OBJS} *.o a.out
	@	echo "Succesfully deleted objects"

fclean:	clean
	@:	${RM} ${NAME}
	@	echo "Succesfully deleted library"


.PHONY	= clean fclean
