NAME = ft_printf

SRC = main.c \
	  ft_printf.c \
	  init.c \
	  printf_meat.c \
	  arg_handle.c \
	  get_things.c

FLAGS = -Wall -Werror -Wextra

LIB = -L libft -lft

DEBUG = -v -g

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(LIB) -o $(NAME) $(SRC)

clean:
	rm *.o

fclean:
	rm $(NAME)

re: fclean all

debug:
	gcc $(FLAGS) $(DEBUG) $(LIB) $(SRC)
