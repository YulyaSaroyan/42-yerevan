/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:25:07 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/29 18:54:29 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_inset(char ch, char const *set)
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
	int		i;
	int		j;
	int		len;
	int		trimlen;
	char	*trimmed;

	i = 0;
	j = 0;
	len = ft_strlen(s1);
	while (s1[i] && is_inset(s1[i], set))
		i++;
	j = len - 1;
	while (s1[j] && is_inset(s1[j], set))
		j--;
	trimlen = len - (i + (len - 1 - j));
	trimmed = ft_substr(s1, i, trimlen);
	return (trimmed);
}
