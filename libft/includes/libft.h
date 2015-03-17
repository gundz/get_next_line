#ifndef		LIBFT_H
# define	LIBFT_H

# include <stddef.h>

char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *const str);

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

t_list				*lst_create_elem(void *data);
void				lst_push_back(t_list **lst, void *data);
char				*lst_to_char(t_list *lst, const int size);
int					lst_csize(t_list *lst);

#endif