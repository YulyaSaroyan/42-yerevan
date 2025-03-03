/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:13:19 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/11 16:29:58 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex_to_int(const char *hex)
{
	int		result;
	int		value;
	char	c;

	result = 0;
	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
		hex += 2;
	while (*hex)
	{
		c = *hex;
		value = 0;
		if (ft_isdigit(c))
			value = c - '0';
		else if (c >= 'A' && c <= 'F')
			value = c - 'A' + 10;
		else if (c >= 'a' && c <= 'f')
			value = c - 'a' + 10;
		else
			return (-1);
		result = result * 16 + value;
		hex++;
	}
	return (result);
}
