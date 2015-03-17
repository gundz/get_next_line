#include <libft.h>
#include <stdlib.h>

char					*lst_to_char(t_list *lst, const int size)
{
	t_list				*lstwalker;
	char				*tmp;
	char				*ret;
	int					i;
	int					j;

	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	lstwalker = lst;
	i = 0;
	while (lstwalker != NULL)
	{
		tmp = lstwalker->data;
		j = 0;
		while (tmp[j] != '\0')
			ret[i++] = tmp[j++];
		if (lstwalker->next == NULL)
			break ;
		lstwalker = lstwalker->next;
	}
	ret[i] = '\0';
	return (ret);
}