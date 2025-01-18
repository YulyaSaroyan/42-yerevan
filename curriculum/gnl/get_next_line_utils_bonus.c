/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:19:24 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/18 20:49:17 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*gnl_concat(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = gnl_strlen(s1);
	len2 = gnl_strlen(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (++i < len1)
		str[i] = s1[i];
	i = -1;
	while (++i < len2)
		str[i + len1] = s2[i];
	str[len1 + len2] = '\0';
	free(s1);
	return (str);
}

char	*gnl_strdup(char *s)
{
	size_t	len;
	char	*dup;
	int		i;

	if (!s)
		return (NULL);
	len = gnl_strlen(s);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		++i;
	}
	dup[i] = '\0';
	return (dup);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	str_len;

	if (!s)
		return (NULL);
	str_len = gnl_strlen(s);
	if (start >= str_len)
		return (gnl_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[len] = '\0';
	return (sub);
}
