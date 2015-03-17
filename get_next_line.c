#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int					ft_strlen(char *str)
{
	int				len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

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
	//free_lst
	return (tmp);
}

int					get_next_line(int const fd, char **line)
{
	static char		*tmp;
	static int		i = 0;
	static int		size = 0;
	int				j = 0;

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
	j = i;
	while (tmp[j] != '\n' && tmp[j] != '\0')
		j++;
	*line = ft_strsub(tmp, i, j - i);
	i = j + 1;
	return (1);
}