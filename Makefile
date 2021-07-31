NAME	= philo

CC		= gcc

CFLAGS	=  -Wall  -Werror -Wextra

SOURCES	= main.c utils.c init_and_launch.c action.c

OBJECTS	= $(SOURCES:.c=.o)

HEADER	= -I philo.h

.c.o: ${CC} ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJECTS)
	${CC} ${CFLAGS} ${OBJECTS} -o $(NAME)

clean:
	-rm -f $(OBJECTS)

fclean: clean
	-rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re