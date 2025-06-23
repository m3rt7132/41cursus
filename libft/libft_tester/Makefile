NAME = tester
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c $(wildcard tests/*.c)
LIBFT = libft.a
INC = -I.

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(INC) -o $(NAME)

run: all
	./$(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f logs/*.txt

re: fclean all

.PHONY: all run clean fclean re