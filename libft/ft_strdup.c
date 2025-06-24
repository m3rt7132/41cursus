/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 00:41:12 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:52:42 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Duplicates a string.
 * This function allocates memory for a new string and copies the content of the
 * input string into the newly allocated memory.
 * @param s The string to duplicate.
 * @return A pointer to the newly allocated string, or NULL if the allocation fails.
 * @return The returned string is null-terminated.
 * @return If the input string is NULL, it returns NULL.
 * @return The caller is responsible for freeing the memory allocated for the duplicated string.
 */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*dup;

	len = 0;
	while (s[len])
		len++;
	dup = (char *) malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return ((void *)0);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
