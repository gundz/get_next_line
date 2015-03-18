/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgundlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 21:00:25 by fgundlac          #+#    #+#             */
/*   Updated: 2015/03/17 21:00:34 by fgundlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char				*store(const int fd)
{
	char			buf[BUF_SIZE + 1];
	char			*tmp;
	t_list			*lst;
	int				n;

	lst = NULL;
	while ((n = read(fd, &buf, BUF_SIZE)))
	{
		if (n <= -1)
			return (NULL);
		buf[n] = '\0';
		lst_push_back(&lst, ft_strdup(buf));
	}
	tmp = lst_to_char(lst);
	lst_free(lst, 1);
	return (tmp);
}

int					get_line(char *tmp, char **line, int *i)
{
	int				j;

	j = *i;
	while (tmp[j] != '\n' && tmp[j] != '\0')
		j++;
	*line = ft_strsub(tmp, *i, j - *i);
	*i = j + 1;
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	static char		*tmp;
	static int		i = 0;
	static int		size = 0;

	if (line == ((void *)0))
		return (-1);
	if (size == 0)
	{
		if ((tmp = store(fd)) == NULL)
			return (-1);
		size = ft_strlen(tmp) + 1;
	}
	if (i >= size)
	{
		if (tmp != NULL)
			free(tmp);
		tmp = NULL;
		return (0);
	}
	return (get_line(tmp, line, &i));
}
