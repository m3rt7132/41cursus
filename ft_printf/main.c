#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int a = ft_printf("mert %s", "bir");
	printf("\n%d\n", a);
	// printf(" NULL %s NULL\n", NULL);
	// printf(" %p %p ", 0, 0);
}