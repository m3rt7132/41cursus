/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:51:03 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:17:43 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks if the character is a printable character.
 * Printable characters are those that are visible on the screen.
 * @param c The character to check.
 * @return 1 if the character is printable, 0 otherwise.
 * TODO: bitwise version
 * * 0x20 = 0010 0000 (32) is the ASCII code for space.
 * * 0x7E = 0111 1110 (126) is the ASCII code for tilde (~).
 * ^ The condition checks if the character is between 32 (space) and 126 (tilde).
 * * (c >= 0x20 && c <= 0x7E);
 * ? Example:
 * * * - ' ' (space) is printable.
 * * * - 127 (DEL) is not printable.
 * * * - 31 (control characters) are not printable.
 */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
