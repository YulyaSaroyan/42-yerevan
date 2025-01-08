#include <stdlib.h>

int	ft_strlen(char const *str);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int	lens;
	int	i;
	int	j;

	lens = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(lens + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
