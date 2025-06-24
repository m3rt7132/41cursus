/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:17:06 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 15:50:31 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Converts a lowercase letter to its uppercase.
 * If the character is not a lowercase letter, it returns itself.
 * @param c The character to convert.
 * @return The uppercase of the character if it is a lowercase letter,
 * TODO: bitwise version:
 *  c &= ~0x20; // This clears the 6th bit of the character, converting it to uppercase.
 * * 01 1 0 0001 (97) -> 01 0 0 0001 (65) // 6. bit is set to 0 means its lowercase
 */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
