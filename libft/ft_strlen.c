/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:10:49 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/25 00:18:49 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Calculates the length of a string.
 * This function counts the number of characters in the string
 * until it reaches the null terminator ('\0').
 * @param s The string whose length is to be calculated.
 * @return The length of the string, excluding the null terminator.
 */

#include <stddef.h>
#include <stdio.h> // unnecessary but used for snprintf (alternative to loopless counting)

size_t	ft_strlen(const char *s)
{
	/*
	const char	*start;

	start = s;
	while (*s)
		s++;
	return (s - start);
	*/
	return (snprintf(NULL, 0, "%s", s));
}
