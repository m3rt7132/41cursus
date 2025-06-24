/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:52:37 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:52:53 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Locates the first occurrence of the character 'c' in the string 's'.
 * If 'c' is found, it returns a pointer to the first occurrence of 'c'.
 * If 'c' is not found, it returns NULL.
 * @param s The string to search in.
 * @param c The character to search for.
 * @return A pointer to the first occurrence of 'c' in 's', or NULL if not found.
 * * Also NULL-terminator is searched.
 * ? Example:
 * * ft_strchr("Hello, World!", 'W') returns a pointer to the 'W'. "World!"
 * * ft_strchr("Hello, World!", 'z') returns NULL.
 */

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (*s == 0)
			break ;
		s++;
	}
	return ((void *)0);
}
