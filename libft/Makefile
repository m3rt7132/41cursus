CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS=ft_atoi.c	ft_bzero.c		ft_calloc.c 	\
ft_isalnum.c	ft_isalpha.c	ft_isascii.c	\
ft_isdigit.c	ft_isprint.c	ft_itoa.c		\
ft_memchr.c		ft_memcmp.c		ft_memcpy.c 	\
ft_memmove.c	ft_memset.c 					\
ft_putchar_fd.c	ft_putendl_fd.c					\
ft_putnbr_fd.c	ft_putstr_fd.c					\
ft_putstr_fd.c	ft_split.c		ft_strchr.c		\
ft_strdup.c 	ft_striteri.c	ft_strjoin.c	\
ft_strlcat.c	ft_strlcpy.c	ft_strlen.c		\
ft_strmapi.c	ft_strncmp.c	ft_strnstr.c	\
ft_strrchr.c	ft_strtrim.c	ft_substr.c		\
ft_tolower.c	ft_toupper.c
BONUSES=ft_lstnew_bonus.c		ft_lstsize_bonus.c	ft_lstmap_bonus.c		\
		ft_lstiter_bonus.c		ft_lstlast_bonus.c	ft_lstadd_back_bonus.c	\
		ft_lstadd_front_bonus.c	ft_lstclear_bonus.c	ft_lstdelone_bonus.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BONUSES:.c=.o)
AR=ar rcs
NAME=libft.a

all: $(NAME)

test: $(NAME)
	@rm -f out
	$(CC) $(CFLAGS) main.c -L. -lft -o out && ./out

bonus: $(OBJS) $(BOBJS)
	@if ! ar t $(NAME) 2>/dev/null | grep -q 'lst'; then \
		ar rcs $(NAME) $(OBJS) $(BOBJS); \
	fi
	$(CC) $(CFLAGS) main.c -L. -lft -o out

$(NAME): $(OBJS)
	@echo "archiving.."
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "cleaning objects.." 
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	@echo "cleaning all.."
	rm -f $(NAME)
	rm -f out

re: fclean all

.PHONY: all clean fclean re test bonus
