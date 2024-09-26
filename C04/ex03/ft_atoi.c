/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:31:59 by ysaroyan          #+#    #+#             */
/*   Updated: 2024/09/21 16:36:35 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\n'
		|| ch == '\r' || ch == '\f' || ch == '\v');
}

int	get_sign(int count)
{
	if (count % 2 != 0)
		return (-1);
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	count;
	int	nb;
	int	sign;

	i = 0;
	count = 0;
	nb = 0;
	while (is_space(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	sign = get_sign(count);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (sign * nb);
}
