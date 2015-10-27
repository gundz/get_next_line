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
#include <stdio.h>
int					find_n(t_list *lst, int eof)
{
	int				i;
	int				j;
	char			*str;

	i = 0;
	while (lst != NULL)
	{
		str = lst->data;
		j = 0;
		while (str[j] != '\0')
		{
			if (str[j] == '\n')
				return (i + j);
			j++;
		}
		if (lst->next == NULL)
			break ;
		lst = lst->next;
		i += j;
	}
	if (eof == 0)
		return (lst_csize(lst));
	if (str[j] == '\0')
		return (-1);
	return (i);
}

char				*get_line(t_list **lst, int *n)
{
	char			*ret;
	char			*tmp;
	int				size;
	int				n2;

	tmp = lst_to_char(*lst);
	n2 = find_n(*lst, *n);
	lst_free(lst, 1);
	ret = ft_strsub(tmp, 0, n2);
	if (tmp[n2] == '\n')
		n2++;
	size = ft_strlen(tmp + n2);
	lst_push_back(lst, ft_strsub(tmp + n2, 0, size));
	free(tmp);
	// tmp = (*lst)->data;
	// n2 = 0;
	// while (tmp[n2] != '\0')
	// {
	// 	if (tmp[n2] != '\n')
	// 		n2++;
	// }
	if (n2 > 0)
		*n = 1;
	else
		*n = 0;
	return (ret);
}

int					get_next_line(int const fd, char **line)
{
	int				n;
	char			buf[BUFF_SIZE + 1];
	static t_list	*lst = NULL;

	if (line == NULL || fd < 0)
		return (-1);
	n = 0;
	while ((n = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[n] = '\0';
		lst_push_back(&lst, ft_strdup(buf));
		if (find_n(lst, n) >= 0)
			break ;
	}
	if (n == -1)
		return (-1);
	*line = get_line(&lst, &n);
	return (n);
}

// "test12\ncl"
// BUFF_SIZE = 4
// while (n = read(buf, BUFF_SIZE))
// {
// 	if (n <= 0)
// 		return (n);
// 	buf[n] = '\0';
// 	while (buf[i] != '\0' && buf[i] != '\n')
// 		i++;
// 	if (buf[i] == '\n')
// 		break ;
// 	lst_push_back(buf);
// }
// if (buf[i] == '\0')
// {
// 	*line = lst_to_char(lst);
// 	lst_free(lst);
// 	return (1);
// }
// else
// {
// 	*line = ft_strsub()
// }
