#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUF_SIZE 4096

typedef struct		s_gnl
{
	char			*tmp;
	int				i;
	int				size;
}					t_gnl;

int					get_next_line(int const fd, char **line);

#endif