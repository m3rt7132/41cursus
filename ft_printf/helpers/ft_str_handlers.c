/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:03:49 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/29 18:06:11 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t ft_strlen(const char *s)
{
    const char *start;

	start = s;
    while (*s)
        s++;
    return (s - start);
}

ssize_t	handle_percent(void)
{
	return (write(1, "%", 1));
}

ssize_t	handle_char(va_list args)
{
	int	c;

	c = (char)va_arg(args, int);
	return (write(1, &c, 1));
}

ssize_t	handle_str(va_list args)
{
	return (ft_putstr((char *)va_arg(args, char *)));
}
