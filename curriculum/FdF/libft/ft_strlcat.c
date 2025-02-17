/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:32:12 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/14 16:34:05 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	destlen = (size_t)ft_strlen((const char *)dest);
	srclen = (size_t)ft_strlen(src);
	if (destlen >= size)
		return (srclen + size);
	i = 0;
	while (src[i] && i < size - destlen - 1)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	if (destlen <= size)
		dest[destlen + i] = '\0';
	return (destlen + srclen);
}
