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

	if (!(fd = open("get_next_line.c", O_RDONLY)))
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

/*#include <string.h>
int
main(void)
{
	char *line;
	int		out;
	int		p[2];
	int		fd;
	int		gnl_ret;

	fd = 1;
	out = dup(fd);
	pipe(p);
	dup2(p[1], fd);
	write(fd, "aaa", 3);
	close(p[1]);
	dup2(out, fd);
	gnl_ret = get_next_line(p[0], &line);
	printf("%s\n", line);
	if (strcmp(line, "aaa") == 0)
		printf("ok\n");
	if (gnl_ret == 0 || gnl_ret == 1)
		printf("ok2\n");
	return (0);
}*/
/*
int
main(void)
{
	char	*line = NULL;

	while (get_next_line(0, &line) > 0)
		printf("%s\n", line);
	return (0);
}*/