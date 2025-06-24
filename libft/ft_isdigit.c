/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:00:07 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:17:50 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks if the character is a digit (0-9).
 * @param c The character to check.
 * @return 1 if the character is a digit, 0 otherwise.
 * TODO: bitwise version
 * * 0xF0 = 1111 0000 (240) is used to isolate the first 4 bits of the character.
 * * 0x0F = 0000 1111 (15) is used to isolate the last 4 bits of the character.
 * ^ The condition checks if the first 4 bits are 0011 (0x30) and the last 4 bits
 * ^ are less than or equal to 1001 (0x09).
 * ? ((c & 0xF0) == 0x30) && ((c & 0x0F) <= 0x09);
 */

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
