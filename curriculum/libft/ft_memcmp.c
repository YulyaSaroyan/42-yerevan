#include<stddef.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	const unsigned char *src1;
	const unsigned char *src2;

	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	i = 0;
	while (i < n && src1[i] == src2[i])
		i++;
	if (i == n)
		return (0);
	return (src1[i] - src2[i]);

}
