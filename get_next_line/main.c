#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	size_t	tozero;

	tozero = nmemb * size;
	alloc = malloc(nmemb * size);
	if (alloc == NULL)
		return ((void *)0);

	while (tozero)
	{
		*(((unsigned char *)alloc) + tozero) = 0;
		tozero--;
	}
	*((unsigned char *)alloc + 0) = 0;
	return (alloc);
}

int main(void)
{
	// int fd;
	// char *line;

	// fd = open("test.txt", O_RDONLY);
	// if (fd < 0)
	// {
	// 	perror("Error opening file");
	// 	return 1;
	// }
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("%s", line);
	// 	free(line);
	// }
	// printf("\nEnd of file reached.\n");
	// if (close(fd) < 0)
	// {
	// 	perror("Error closing file");
	// 	return 1;
	// }
	// printf("File closed successfully.\n");
	// return 0;

	void *alloc = ft_calloc(4,5);
	printf("ilk %d\n", *((unsigned char *)(alloc + 0)));
	printf("son %d\n", *((unsigned char *)(alloc + 23)));
	free(alloc);
}
