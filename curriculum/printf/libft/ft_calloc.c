/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:00:43 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/14 18:42:31 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*space;
	size_t	total_size;

	if (nelem && elsize > INT_MAX / nelem)
		return (NULL);
	total_size = nelem * elsize;
	if (total_size == 0)
		return (malloc(0));
	space = malloc(total_size);
	if (!space)
		return (NULL);
	ft_bzero(space, total_size);
	return (space);
}
