NAME = libftprintf.a

SRCS = ft_printf.c ft_utils.c
OBJS = ${SRCS:.c=.o}
INCLUDES = ft_printf.h

CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

%.o: %.c $(INCLUDES)
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	$(AR) ${NAME} ${OBJS}

all: ${NAME}

clean:	
	rm -f ${OBJS}

fclean:	clean;
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re