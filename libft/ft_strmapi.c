/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:00:01 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/25 00:01:11 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Applies a function to each character of a string and returns a new string.
 * The function takes the index of the character and the character itself,
 * and returns a new character.
 * @param s The string to iterate over.
 * @param f(unsigned int, char) The function to apply to each character.
 * @return A new string with the transformed characters,
 * * or NULL if memory allocation fails.
 * ! The new string is dynamically allocated and must be freed by the caller.
 */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	if (!s)
		return (0);
	ret = (char *) malloc((sizeof(char) * ft_strlen(s)) + 1);
	if (!ret)
		return ((void *)0);
	i = 0;
	while (s[i])
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
