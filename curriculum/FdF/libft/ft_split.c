/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:36:49 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/13 16:01:52 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

void	*clear(char **splitted, int k)
{
	while (k >= 0)
	{
		free(splitted[k]);
		k--;
	}
	free(splitted);
	return (NULL);
}

int	skip_same_chars(const char *s, int i, char c)
{
	while (s[i] && s[i] == c)
		i++;
	return (i);
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
		i = skip_same_chars(s, i, c);
		if (s[i] && s[i] != c)
		{
			j = 0;
			while (s[i] && s[i] != c)
			{
				i++;
				j++;
			}
			splitted[k] = ft_substr(s, i - j, j);
			if (!splitted[k])
				return (clear(splitted, k));
			k++;
		}
	}
	splitted[k] = NULL;
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	splitted = (char **)malloc((count + 1) * sizeof (char *));
	if (!splitted)
		return (NULL);
	return (split_logic(s, c, splitted));
}
