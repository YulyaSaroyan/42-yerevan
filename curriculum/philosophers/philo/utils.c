/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <ysaroyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:13:58 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/04/01 16:51:08 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_space(char ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\r'
		|| ch == '\n' || ch == '\f' || ch == '\v');
}

static int	ft_isdigit(int ch)
{
	return (ch >= '0' && ch <= '9');
}

int	is_valid(char *num)
{
	int	i;

	if (num[0] == '0')
		return (0);
	if (num[0] != '0' && ft_atoi(num) == 0)
		return (0);
	i = -1;
	while (num[++i])
		if (!ft_isdigit(num[i]))
			return (0);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	i;
	int	sign;

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

int	get_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
