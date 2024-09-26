/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 13:15:54 by ysaroyan          #+#    #+#             */
/*   Updated: 2024/09/21 12:59:57 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	len = 0;
	while (dest[len])
		len++;
	if (len > size)
		return (len + size);
	i = 0;
	while (src[i] && i < size - len - 1)
	{
		dest[len + i] = src[i];
		i++;
	}
	if (len <= size)
		dest[len + i] = '\0';
	return (len + size);
}
