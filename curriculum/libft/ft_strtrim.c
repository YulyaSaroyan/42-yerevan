#include <stdlib.h>

int	ft_strlen(char const *str);

int	ft_trimlen(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				len++;
			j++;
		}
		i++;
	}
	return (len);
}

int	is_inset(char ch, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == ch)
			return (1);
		i++;	
	}
	return (0);

}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	trimlen;
	char	*trimmed;

	i = 0;
	j = 0;
	trimlen = ft_trimlen(s1, set);
	trimmed = (char *)malloc(ft_strlen(s1) - trimlen + 1);
	while (s1[i])
	{
		if (!is_inset(s1[i], set))
		{
			trimmed[j] = s1[i];
			j++;
		}
		i++;
	}
	return (trimmed);
}
