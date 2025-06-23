#ifndef TESTER_H
# define TESTER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdint.h>
# include <limits.h>
# include <assert.h>

/* my functions */

void init_log_file(void);
void close_log_file(void);
void log_start(const char *func_name);
void log_assert(int passed, const char *format, ...);
void log_end(void);
void log_info(const char *fmt, ...);
void log_error(const char *fmt, ...);
void log_warn(const char *fmt, ...);
size_t getheap(size_t align);
char *generate_log_filename(void);

/* tester libft prototypes */

void test_ft_atoi(void);
void test_ft_calloc(void);
void test_ft_bzero(void);
void test_ft_itoa(void);
void test_ft_isalnum(void);
void test_ft_isalpha(void);
void test_ft_isdigit(void);
void test_ft_isprint(void);
void test_ft_isascii(void);
void test_ft_putchar_fd(void);
void test_ft_putstr_fd(void);
void test_ft_putendl_fd(void);
void test_ft_putnbr_fd(void);
void test_ft_strnstr(void);
void test_ft_strrchr(void);
void test_ft_strtrim(void);
void test_ft_substr(void);
void test_ft_tolower(void);
void test_ft_toupper(void);
void test_ft_striteri(void);
void test_ft_strjoin(void);
void test_ft_strlcat(void);
void test_ft_strlcpy(void);
void test_ft_strlen(void);
void test_ft_strmapi(void);
void test_ft_strncmp(void);
void test_ft_split(void);
void test_ft_strchr(void);
void test_ft_strdup(void);
void test_ft_memchr(void);
void test_ft_memcmp(void);
void test_ft_memcpy(void);
void test_ft_memmove(void);
void test_ft_memset(void);

/* libft mandatory and additional functions */

int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif