/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:03:39 by ysaroyan          #+#    #+#             */
/*   Updated: 2024/09/25 21:33:19 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (dest[len])
		len++;
	while (src[i])
	{
		dest[len] = src[i];
		len++;
		i++;
	}
	dest[len] = '\0';
	return (dest);
}

int	calculate_total_length(int size, char **strs, char *sep)
{
	int	i;
	int	total_length;
	int	sep_length;

	total_length = 0;
	sep_length = ft_strlen(sep);
	i = 0;
	while (i < size)
	{
		total_length += ft_strlen(strs[i]);
		i++;
	}
	total_length += sep_length * (size - 1);
	return (total_length);
}

void	concatenate_strings(char *result, int size, char **strs, char *sep)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_length;

	total_length = 0;
	if (!strs || !sep)
		return (NULL);
	if (size == 0)
	{
		result = (char *)malloc(1);
		if (result)
			result[0] = '\0';
		return (result);
	}
	total_length = calculate_total_length(size, strs, sep);
	result = (char *)malloc(total_length + 1);
	if (!result)
		return (NULL);
	result[0] = '\0';
	concatenate_strings(result, size, strs, sep);
	return (result);
}
