/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgundlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 21:02:25 by fgundlac          #+#    #+#             */
/*   Updated: 2015/03/17 21:02:26 by fgundlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdlib.h>

int main(int ac, char **av) 
{ 
char *line; 
int fd;

(void)ac;
(void)av;
fd = open(av[1], O_RDONLY);
while (get_next_line(fd, &line) > 0)
{
    printf("%s\n", line);
    free(line);
}
return (0);
}

// int
// main(void)
// {
// 	int		fd;
// 	char	*buf;
// 	int		ret;

// 	if (!(fd = open("test", O_RDONLY)))
// 	{
// 		printf("Error bitch !\n");
// 		return (-1);
// 	}

// 	while ((ret = get_next_line(fd, &buf)) > 0)
// 	{
// 		printf("%s\n", buf);
// 		//printf("ret = %d\n", ret);
// 		free(buf);
// 	}
// 	return (0);
// }

// #include <string.h>
// int
// main(void)
// {
// 	char 	*line;
// 	int		out;
// 	int		p[2];
// 	char 	*str;
// 	int		len = 50;

// 	str = (char *)malloc(1000 * 1000);
// 	*str = '\0';
// 	while (len--)
// 		strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
// 	out = dup(1);
// 	pipe(p);
// 	dup2(p[1], 1);

// 	if (str)
// 		write(1, str, strlen(str));
// 	close(p[1]);
// 	dup2(out, 1);
// 	get_next_line(p[0], &line);
// 	if (strcmp(line, str) == 0)
// 		printf("ok\n");
// }

// int
// main(void)
// {
// 	char		*buf;
// 	int			ret;

// 	while ((ret = get_next_line(0, &buf)) > 0)
// 	{
// 		printf("%s\n", buf);
// 		free(buf);
// 		buf = NULL;
// 	}
// 	return (0);
// }

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
