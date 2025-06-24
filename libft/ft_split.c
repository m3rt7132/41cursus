/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:26:32 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/25 00:13:57 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Splits a string into an array of strings based on a delimiter character.
 * The function allocates memory for the array and each substring,
 * so it is the caller's responsibility to free the memory when done.
 *
 * @param s The string to split.
 * @param c The delimiter character.
 * @return An array of strings (substrings) or NULL if the allocation fails.
 * @return The last element of the array is NULL to indicate the end of the array.
 * ? Example:
 * * ft_split("Hello World", ' ') returns ["Hello", "World", NULL]
 * * The function handles multiple consecutive delimiters and leading/trailing delimiters.
 * ! If the input string is empty, it returns an array with a single NULL element.
 * ! If the allocation fails, it frees any previously allocated memory and returns NULL.
 * ! The caller is responsible for freeing the memory allocated for the array and its elements.
 */

#include "libft.h"
#include <stdlib.h>
/* ! These comment lines need to be deleted if you want to use codes due to norminette comment blocks. */
static int	add_word(char **arr, const char *s, int word_len, int index)
{
	char	*word;

	word = ft_substr(s, 0, word_len); // Extract the substring of length 'word_len' from 's'
	if (!word)
	{
		while (index--)
			free(arr[index]);
		free(arr);
		return (0);
	}
	arr[index] = word;
	return (1);
}

static int	count_words(const char *s, char c, int push, char **arr)
{
	int	i;
	int	word_len;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c) // Skip delimiters
			i++;
		word_len = 0; // Reset word length for the next word
		while (s[i + word_len] && s[i + word_len] != c)
			word_len++; // Count the length of the word
		if (word_len > 0)
		{
			/* If word is correctly found, and push(3rd param) is 1 we are appending word to our array,
			   if it fails, add_word function will return 0 and finally it will return -1 for debugging. */
			if (push && arr && !(add_word(arr, s + i, word_len, words)))
				return (-1);
			words++;
			i += word_len; // Move index to the end of the current word
		}
	}
	return (words);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	int		words;

	if (!s)
		return ((void *)0);
	/* Count just only words and return word count to 'words' variable */
	words = count_words(s, c, 0, 0);
	/* Allocate the array of substrings with word count + NULL */
	arr = (char **) malloc((sizeof(char *) * (words + 1)));
	if (!arr)
		return ((void *)0);
	/* Count words again *and* while counting, that push(3rd param) parameter
	   *allows us to push the current word* to our empty array, if it fails, it frees
	   the previously allocated memory and returns -1. And then we can handle it */
	words = count_words(s, c, 1, arr);
	if (words == -1)
		return ((void *)0);
	arr[words] = 0;
	return (arr);
}