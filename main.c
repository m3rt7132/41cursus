/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:00:41 by mecetink          #+#    #+#             */
/*   Updated: 2025/05/30 15:14:37 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void test_strchr()
{
	
}

int main()
{
	char s[] = "hello world";
	printf("%s", ft_strrchr(s, 'o'));
	printf("%s", strrchr(s, 'o'));
}

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