/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:21:55 by mecetink          #+#    #+#             */
/*   Updated: 2025/05/30 14:34:37 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*f = s + ft_strlen((char *)s);
	
	while (f >= s)
	{
		if (*f == (char)c)
			return ((char *)f);
		f--;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}
