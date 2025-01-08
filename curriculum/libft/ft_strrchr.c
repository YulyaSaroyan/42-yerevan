#include <stddef.h>

char	*ft_strrchr(char *s, int c)
{
	int	len;

	if (c == '\0')
		return (NULL);
	while (s[len])
		len++;
	while (s[len] && len)
	{
		if (s[len] == c)
			return (s + len);
		len--;
	}
	return (NULL);
}
