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
#include <get_next_line.h>

int					find_n(t_list *lst)
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
	if (str[j] == '\0')
		return (-1);
	return (i);
}

char				*get_line(t_list **lst)
{
	char			*ret;
	char			*tmp;
	int				n_pos;

	if ((n_pos = find_n(*lst)) == -1)
	{
		ret = lst_to_char(*lst);
		lst_free(lst, 1);
		return (ret);
	}
	tmp = lst_to_char(*lst);
	ret = ft_strsub(tmp, 0, n_pos);
	lst_free(lst, 1);
	lst_push_back(lst, ft_strsub(tmp, n_pos + 1, ft_strlen(tmp) - n_pos));
	free(tmp);
	return (ret);
}

int					get_next_line(int const fd, char **line)
{
	int				n2;
	char			buf[BUFF_SIZE + 1];
	static t_list	*lst = NULL;

	n2 = 0;
	if (line == NULL || fd < 0)
		return (-1);
	while ((n2 = read(fd, &buf, BUFF_SIZE)))
	{
		if (n2 == -1)
			return (-1);
		if (n2 == 0)
			return (0);
		buf[n2] = '\0';
		lst_push_back(&lst, ft_strdup(buf));
		if (find_n(lst) >= 0)
			break ;
	}
	if (lst == NULL)
		return (0);
	*line = get_line(&lst);
	if (lst == NULL && n2 == 0)
		return (0);
	return (1);
}
