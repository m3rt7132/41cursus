/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:44:07 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/20 15:22:44 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	srclength;
	size_t	start;
	char	*newstr;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (*s1 == 0)
	{
		newstr = ft_strdup("");
		if (!newstr)
			return (NULL);
		return (newstr);
	}
	srclength = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (srclength > start && ft_strchr(set, s1[srclength - 1]))
		srclength--;
	newstr = (char *) malloc(sizeof(char) * (srclength - start + 1));
	if (!newstr)
		return (NULL);
	ft_memcpy(newstr, s1 + start, srclength - start);
	newstr[srclength - start] = 0;
	return (newstr);
}
