#include "get_next_line.h"

#include <libft.h>
#include <stdio.h>
#include <fcntl.h>

#include <stdlib.h>

int
main(int argc, char **argv)
{
	int			fd;
	char		*buf;

	if (argc != 2)
		return (-1);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		perror("");
		
	int ret;
	
	while ((ret = get_next_line(42, &buf)) > 0)
	{
		// printf("ret = %d \"%s\"\n", ret, buf);
		printf("%s\n", buf);
		free(buf);
	}

	// ret = get_next_line(fd, &buf);
	// free(buf);
	// printf("@@ret = %d \"%s\"\n", ret, buf);

	// ret = get_next_line(fd, &buf);
	// free(buf);
	// printf("@@ret = %d \"%s\"\n", ret, buf);

	// ret = get_next_line(fd, &buf);
	// free(buf);
	// printf("@@ret = %d \"%s\"\n", ret, buf);

	// ret = get_next_line(fd, &buf);
	// printf("@@ret = %d \"%s\"\n", ret, buf);
}