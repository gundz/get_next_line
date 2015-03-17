#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char				*store(const int fd, int *const size)
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
	*size = lst_csize(lst);
	tmp = lst_to_char(lst, *size);
	//free_lst
	return (tmp);
}

int					get_next_line(int const fd, char **line)
{
	static char		*tmp;
	static int		i = 0;
	static int		size = 0;
	int				j;

	if (size == 0)
	{
		if ((tmp = store(fd, &size)) == NULL)
			return (-1);
	}
	if (i >= size)
	{
		free(tmp);
		return (0);
	}
	j = i;
	while (tmp[j] != '\n' && tmp[j] != '\0')
		j++;
	*line = ft_strsub(tmp, i, j - i);
	i = j + 1;
	return (1);
}