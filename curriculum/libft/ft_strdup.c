#include <stdlib.h>

char *ft_strdup(char const *src)
{
	char	*dest;
	int	i;
	int	len;

	if (!src || !src[0])
	{
		dest = (char *)malloc(1);
		if (dest)
			dest[0] = '\0';
		return (dest);
	}
	len = 0;
	while (src[len])
		len++;
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
