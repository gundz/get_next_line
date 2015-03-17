#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int
main(void)
{
	int			fd;
	char		*buf;

	if (!(fd = open("get_next_line.c", O_RDONLY)))
	{
		printf("Error bitch !\n");
		return (-1);
	}
	while (get_next_line(fd, &buf) > 0)
		printf("%s\n", buf);
	close(fd);
	return (0);
}