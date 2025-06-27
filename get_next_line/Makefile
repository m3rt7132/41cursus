NAME	=	getnextline.a
CC		=	cc -Wall -Wextra -Werror
SRCS	=	get_next_line.c get_next_line_utils.c
OBJS	=	$(SRCS:.c=.o)
AR		=	ar rcs
BUFSIZ  =	10

all:		$(NAME)

run:		$(NAME)
	@rm -f out
	$(CC) main.c getnextline.a -D BUFFER_SIZE=$(BUFSIZ) -o out && ./out

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o:		%.c
	$(CC) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean:		clean
	@rm -f $(NAME) out

re: fclean all

.PHONY: all clean fclean re run
