BIN			=	./bin/

FLAGS		= -Wall -Wextra -Werror

SRCS		=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c

OBJS		= ${BIN}${SRCS:.c=.o}

CC			= gcc

COMPILE.C	= ${CC} ${FLAGS} -c

OUTPUT_OPT	= -o $@

%.o: %.c
	${COMPILE.C} ${OUTPUT_OPT} $<

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

RM			= rm -f

.PHONY	= clean fclean
