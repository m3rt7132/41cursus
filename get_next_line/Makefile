NAME	=	getnextline.a
CC		=	cc -Wall -Wextra -Werror
SRCS	=	get_next_line.c			get_next_line_utils.c
BSRCS	=	get_next_line_bonus.c	get_next_line_utils_bonus.c
AR		=	ar rcs
BUFSIZ  =	10

all:		$(NAME)

mand: $(SRCS)
	$(CC) $(SRCS) -D BUFFER_SIZE=$(BUFSIZ) -o out && ./out

bns: $(BSRCS)
	$(CC) $(BSRCS) -D BUFFER_SIZE=$(BUFSIZ) -o out && ./out

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o:		%.c
	$(CC) -c $< -o $@

clean:
	@rm -f $(OBJS) $(BOBJS) out

fclean:		clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run
