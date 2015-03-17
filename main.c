#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int
main(void)
{
	char		*buf;
	int			ret;
	int			fd;

	if (!(fd = open("test", O_RDONLY)))
	{
		printf("Error bitch !\n");
		return (-1);
	}
	while ((ret = get_next_line(fd, &buf)) > 0)
	{
		printf("ret = %d\n", ret);
		printf("%s\n", buf);
	}
	close(fd);
	return (0);
}