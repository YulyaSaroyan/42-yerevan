#include <stddef.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	const unsigned char	*src;

	i = 0;
	src = (const unsigned char *)s;
	while (i < n)
	{
		if (src[i] == c)
			return ((void *)(src + i));
		i++;
	}
	return (NULL);
}
