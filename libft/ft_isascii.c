/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:43:40 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 16:41:41 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks if the character is an ASCII character (0-127).
 * @param c The character to check.
 * @return 1 if the character is an ASCII character, 0 otherwise.
 * TODO: bitwise version
 * * !(c & ~0x7F) if c is in the ASCII range, the 8th bit is 0.
 * * 0100 0001 (65) & 0111 1111 (127) = 0100 0001 (65) // 8th bit is 0
 * * 1000 0001 (129) & 0111 1111 (127) = 0000 0001 (1) // 8th bit is 1 it's not ASCII
 */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
