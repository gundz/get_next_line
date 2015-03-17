#include <stdlib.h>

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*fresh;
	size_t		i;

	if (!(fresh = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		fresh[i] = s[i + start];
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}