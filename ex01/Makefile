NAME = libft.a
SRC = srcs
INC = includes
SRCPATHS = ${SRC}/ft_putchar.c ${SRC}/ft_putstr.c ${SRC}/ft_strcmp.c ${SRC}/ft_strlen.c ${SRC}/ft_swap.c
BFILESPATHS = ${SRCPATHS:.c=.o}
RM = rm -f
CC = cc
CCFLAGS = -Wall -Wextra -Werror -c

all: ${NAME}
%.o: %.c
	${CC} ${CCFLAGS} $< -o $@ -I ${INC}
${NAME}: ${BFILESPATHS}
	ar -rc $@ ${BFILESPATHS}
clean:
	${RM} ${BFILESPATHS}
fclean:	clean
	${RM} ${NAME}
re: fclean all
