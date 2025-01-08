/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 21:11:35 by ysaroyan          #+#    #+#             */
/*   Updated: 2024/09/24 20:49:20 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\r'
		|| ch == '\n' || ch == '\f' || ch == '\v');
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_format(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || is_space(base[i]))
			return (0);
		i++;
	}
	return (1);
}

int	get_num(char *str, char *base, int len)
{
	int	num;
	int	i;
	int	base_idx;

	num = 0;
	i = 0;
	while (str[i])
	{
		base_idx = 0;
		while (base[base_idx] && base[base_idx] != str[i])
			base_idx++;
		if (!base[base_idx])
			break ;
		num = num * len + base_idx;
		i++;
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len;
	int	sign;
	int	num;
	int	i;

	len = str_len(base);
	if (len <= 1 || !check_format(base))
		return (0);
	i = 0;
	while (is_space(str[i]))
		i++;
	sign = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	num = get_num(&str[i], base, len);
	return (num * sign);
}
