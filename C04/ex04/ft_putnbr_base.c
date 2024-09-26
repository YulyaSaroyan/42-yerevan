/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 22:19:05 by ysaroyan          #+#    #+#             */
/*   Updated: 2024/09/21 16:39:59 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	printnumber(char ch)
{
	write(1, &ch, 1);
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
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	radix;
	int	check;

	radix = str_len(base);
	check = check_format(base);
	if (radix <= 1 || !check)
		return ;
	if (nbr == 0)
	{
		write(1, base, 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		if (nbr / radix != 0)
			ft_putnbr_base(-(nbr / radix), base);
		printnumber(base[-(nbr % radix)]);
		return ;
	}
	if (nbr / radix != 0)
		ft_putnbr_base(nbr / radix, base);
	printnumber(base[nbr % radix]);
}
