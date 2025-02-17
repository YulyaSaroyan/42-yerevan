/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:51:43 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/10 16:18:29 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*src;

	i = 0;
	src = (const unsigned char *)s;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
			return ((void *)(src + i));
		i++;
	}
	return (NULL);
}
