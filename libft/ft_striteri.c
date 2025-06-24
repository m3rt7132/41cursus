/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:25:28 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 23:58:14 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Iterates through a string and applies a function to each character's address.
 * The function takes the index of the character and a pointer to the character itself.
 * @param s The string to iterate over.
 * @param f(unsigned int, char*) The function to apply to each character.
 * @return VOID.
 * * If 's' is NULL or 'f' is NULL, the function does nothing.
 */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
