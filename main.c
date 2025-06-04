/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:00:41 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/04 21:40:49 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
// libft test asserts
#include <string.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

int main()
{
	ft_putnbr_fd(0, 1);
}

/* int main()
{
	char src[] = "ABCDEFGHI";
	char dest[] = "12345678";
	memmove(src, src + 3, 5);
	printf("%s\n", dest);
	ft_memmove(src, src + 3, 5);
	printf("%s\n", dest);
	char a[] = {'h', 'e', 'l', 'l', 'o'};
	char b[] = {'h', 'e', 'l', 'l', 'o'};
	char c[] = {'h', 'e', 'l', 'l', 'x'};
	char d[] = {'h', 'e', 'l', '\0', '\0'};

	printf("%d == %d\n", memcmp(a, b, 5), ft_memcmp(a, b, 5)); // 0
	printf("%d == %d\n", memcmp(a, c, 5), ft_memcmp(a, c, 5)); // < 0
	printf("%d == %d\n", memcmp(c, a, 5), ft_memcmp(c, a, 5)); // > 0
	printf("%d == %d\n", memcmp(a, d, 3), ft_memcmp(a, d, 3)); // 0
	printf("%d == %d\n", memcmp(a, d, 5), ft_memcmp(a, d, 5)); // > 0
} */

/*#include <stdio.h>
int main()
{
	char a = 10;
	char b = 20;
	char c = 30;
	char d = (a * b * c);
	printf("%c char d before %d", d, d);
	d /= 1000;
	printf("%c char d after %d", d, d);

	int test = 0x11223344;
	int test2 = ~0x7FFFFFFF; // INT_MAX
	printf("\n%d %d\n", test, test2);

	char buff[100];
	buff[1] = 0x11223344;
	printf("\n%d\n", buff[1]);
	buff[0] = 1;
	buff[5] = 5;
	printf("%p %d %d\n", buff, buff[0], buff[5]);
}*/
