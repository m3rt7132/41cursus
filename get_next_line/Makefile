NAME	=	getnextline.a
CC		=	cc -Wall -Wextra -Werror
SRCS	=	get_next_line.c			get_next_line_utils.c
BSRCS	=	get_next_line_bonus.c	get_next_line_utils_bonus.c
OBJS	=	$(SRCS:.c=.o)
BOBJS	=	$(BSRCS:.c=.o)
AR		=	ar rcs
BUFSIZ  =	10

all:		$(NAME)

bonus:		$(OBJS) $(BOBJS)
	@if ! ar t $(NAME) 2>/dev/null | grep -q 'lst'; then \
		ar rcs $(NAME) $(OBJS) $(BOBJS); \
	fi

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
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run
