/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 21:11:25 by ysaroyan          #+#    #+#             */
/*   Updated: 2024/09/24 21:53:33 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	check_format(char *base);
int	str_len(char *str);

int	ft_intlen(int nb, int radix)
{
	int	len;

	if (nb <= 0)
		len = 1;
	len = 0;
	while (nb)
	{
		len++;
		nb /= radix;
	}
	return (len);
}

char	*ft_itoa_base(int nb, int radix, char *base)
{
	int		len;
	long	num;
	char	*str;

	num = nb;
	len = ft_intlen(num, radix);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	else if (num == 0)
		str[0] = base[0];
	while (num > 0)
	{
		str[--len] = base[num % radix];
		num /= radix;
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;

	if (str_len(base_from) <= 1 || str_len(base_to) <= 1
		|| !check_format(base_from) || !check_format(base_to))
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(nb, str_len(base_to), base_to));
}
