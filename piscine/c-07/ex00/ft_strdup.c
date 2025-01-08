/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:54:23 by ysaroyan          #+#    #+#             */
/*   Updated: 2024/09/25 21:28:52 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		len;

	if (!src || !src[0])
	{
		dest = (char *)malloc(1);
		if (dest)
			dest[0] = '\0';
		return (dest);
	}
	len = 0;
	while (src[len])
		len++;
	dest = (char *)malloc(len + 1);
	if (!dest)
		return ((void *)0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
