CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c 	\
ft_isalnum.c ft_isalpha.c ft_isascii.c		\
ft_isdigit.c ft_isprint.c					\
ft_memchr.c ft_memcmp.c ft_memcpy.c 		\
ft_memmove.c ft_memset.c					\
ft_strchr.c ft_strdup.c ft_strjoin.c		\
ft_strlcat.c ft_strlcpy.c ft_strlen.c		\
ft_strncmp.c ft_strnstr.c ft_strrchr.c		\
ft_strtrim.c ft_substr.c					\
ft_tolower.c ft_toupper.c
OBJS = $(SRCS:.c=.o)
RM=rm -f
AR=ar rcs
NAME=libft.a


all: $(NAME)

test: re
	$(CC) $(CFLAGS) main.c libft.a -o out
	@echo "done"

$(NAME): $(OBJS)
	@echo "archiving.."
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	@echo "transformin to .o.." 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "cleaning objects.." 
	rm -f $(OBJS)

fclean: clean
	@echo "cleaning all.."
	rm -f $(NAME)
	rm -f out

re: fclean all

.PHONY: all clean fclean re
