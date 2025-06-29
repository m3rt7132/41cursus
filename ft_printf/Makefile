NAME	=	libftprintf.a
SRCS	=	ft_printf.c \
			helpers/ft_intptr_handlers.c \
			helpers/ft_str_handlers.c \
			helpers/ft_libft_utils.c
OBJS	=	$(SRCS:.c=.o)
CC		=	cc -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

run:		$(NAME) main.c
	$(CC) main.c $(NAME) -o out && ./out

%.o:		%.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re