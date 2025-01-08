#include <stdlib.h>

int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	*ft_strndup(char const *str, int start, int len)
{
	char	*dup;
	int		i;

	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str[start + i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}

char	**split_logic(char const *s, char c, char **splitted)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			j = 0;
			while (s[i] && s[i] != c)
			{
				j++;
				i++;
			}
			splitted[k] = ft_strndup(s, i - j, j);
			k++;
		}
	}
	splitted[k] = 0;
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	char 	**splitted;
	int	count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	splitted = (char **)malloc((count + 1) * sizeof (char *));
	if (!splitted)
		return (NULL);
	return (split_logic(s, c, splitted));
}
