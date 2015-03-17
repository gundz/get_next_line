#include <stdlib.h>

char					*ft_strdup(const char *const str)
{
	unsigned int		len;
	char				*ret;

	len = 0;
	while (str[len] != '\0')
		len++;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	while (str[len] != '\0')
	{
		ret[len] = str[len];
		len++;
	}
	ret[len] = '\0';
	return (ret);
}