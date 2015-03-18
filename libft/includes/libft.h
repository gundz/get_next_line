/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgundlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 21:02:52 by fgundlac          #+#    #+#             */
/*   Updated: 2015/03/17 21:02:59 by fgundlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int					ft_strlen(const char *const str);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *const str);

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

t_list				*lst_create_elem(void *data);
void				lst_push_back(t_list **lst, void *data);
void				lst_free(t_list *lst, const int free_data);
char				*lst_to_char(t_list *lst);
int					lst_csize(t_list *lst);

#endif
