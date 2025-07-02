/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:25:29 by mecetink          #+#    #+#             */
/*   Updated: 2025/07/01 17:32:35 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *fmt, ...);

size_t	ft_strlen(const char *s);
ssize_t	handle_percent(void);
ssize_t	handle_char(va_list args);
ssize_t	handle_str(va_list args);

ssize_t	handle_int(va_list args);
ssize_t	handle_uint(va_list args);
ssize_t	handle_hex(va_list args, int type);
ssize_t	handle_ptr(va_list args);

char	*ft_itoa(int n);
ssize_t	ft_putstr(const char *s);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
char	*ft_utoa_base(unsigned long num, const char *base);

#endif