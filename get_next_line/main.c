#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

extern int readcount; // Declare the external variable

int main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return 1;
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	printf("\nEnd of file reached.\n");
	if (close(fd) < 0)
	{
		perror("Error closing file");
		return 1;
	}
	printf("File closed successfully.\n");
	return 0;
}