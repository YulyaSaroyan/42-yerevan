#include <stddef.h>
#include <stdlib.h>

int	ft_strlen(char const *str);
char	*ft_strdup(char const *src);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	unsigned int	i;
	size_t		j;
	unsigned int	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[i])
	{
		sub[j] = s[i];
		i++;
		j++;
	}
	sub[len] = '\0';
	return (sub);
}
