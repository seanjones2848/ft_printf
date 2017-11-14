NAME = ft_printf

SRC = main.c \
	  ft_printf.c \
	  init.c

FLAGS = -Wall -Werror -Wextra

DEBUG = -v -g

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC)

clean:
	rm *.o

fclean: clean
	rm $(NAME)

debug:
	gcc $(FLAGS) $(DEBUG) $(SRC)
