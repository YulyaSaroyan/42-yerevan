/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:18:11 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/23 14:02:44 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\r'
		|| ch == '\n' || ch == '\f' || ch == '\v');
}

long	ft_atoi(const char *nptr)
{
	long	nb;
	int		i;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (is_space(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}
