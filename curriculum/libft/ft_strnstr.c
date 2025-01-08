#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!little[0]) 
		return ((char *)big);
	i = 0;
	j = 0;
	while (i < len && big[i])
	{
		while (little[j] && (i + j) < len && big[i + j] == little[i])
			j++;
		if (!little[j]) 
			return ((char *)(big + i));	
		i++;
	}
	return (NULL);
}
