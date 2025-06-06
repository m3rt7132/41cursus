/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:26:32 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/05 12:43:31 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	count_words(const char *s, char c, int push, char **arr)
{
	int	words;
	int	next_offset;
	int	cur_char;

	next_offset = 0;
	cur_char = 0;
	words = 0;
	while (1)
	{
		if (s[cur_char + next_offset] == c || s[cur_char + next_offset] == 0)
		{
			if (push && arr != NULL)
				arr[words++] = ft_substr(s, next_offset, cur_char);
			else
				words++;
			if (s[cur_char + next_offset] == 0)
				break ;
			next_offset += cur_char + 1;
			cur_char = 0;
		}
		else
			cur_char++;
	}
	return (words);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	int		words;

	if (!s)
		return (0);
	words = count_words(s, c, 0, 0);
	arr = (char **)malloc((sizeof(char *) * (words + 1)));
	if (!arr)
		return (0);
	words = count_words(s, c, 1, arr);
	arr[words] = 0;
	return (arr);
}
