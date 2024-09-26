/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 21:12:02 by ysaroyan          #+#    #+#             */
/*   Updated: 2024/09/25 22:09:43 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_sep(char ch, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (ch == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			++i;
		if (!is_sep(str[i], charset))
			++count;
		while (str[i] && !is_sep(str[i], charset))
			++i;
	}
	return (count);
}

char	*ft_strndup(char *str, int start, int len)
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

char	**split_logic(char *str, char *charset, char **result)
{
	int	i;
	int	word_index;
	int	start;

	i = 0;
	word_index = 0;
	while (str[i])
	{
		while (is_sep(str[i], charset) && str[i])
			i++;
		start = i;
		while (!is_sep(str[i], charset) && str[i])
			i++;
		if (start != i)
			result[word_index++] = ft_strndup(str, start, i - start);
	}
	result[word_index] = 0;
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	int		word_count;
	char	**result;

	if (!str || !charset)
		return (NULL);
	word_count = count_words(str, charset);
	result = (char **)malloc((word_count + 1) * sizeof (char *));
	if (!result)
		return (NULL);
	return (split_logic(str, charset, result));
}
