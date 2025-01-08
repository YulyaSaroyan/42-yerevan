#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char *ptr = (unsigned char *)s;
	
	while (n--)
		*ptr++ = 0;
}
