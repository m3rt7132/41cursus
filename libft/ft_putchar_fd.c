/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:04:48 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:45:42 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Writes a character to the specified file descriptor.
 * @param c The character to write.
 * @param fd The file descriptor to write to.
 * @return VOID.
 * * This function is useful and gives flexibility for writing characters to files,
 * * standard output, or standard error.
 * ! Note: The file descriptor must be valid and opened for writing.
 * ! If the file descriptor is invalid or closed, the behavior is undefined.
 * ! If you want to write a string, consider using `ft_putstr_fd` or `ft_putendl_fd`.
 * ? Example usage:
 * * int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
 * * * if (fd != -1)
 * * * {
 * * * *   ft_putchar_fd('A', fd); // Writes 'A' to the file
 * * * *   close(fd); // Don't forget to close the file descriptor
 * * * }
 * * If you want to write to standard output, you can use `ft_putchar_fd('A', 1);`
 */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}
