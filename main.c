#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdlib.h>

int
main(void)
{
	char		*buf;
	int			ret;
	int			fd;

	if (!(fd = open("test2", O_RDONLY)))
	{
		printf("Error bitch !\n");
		return (-1);
	}
	while ((ret = get_next_line(fd, &buf)) > 0)
	{
		printf("%s\n", buf);
		free(buf);
		buf = NULL;
	}
	close(fd);
	return (0);
}