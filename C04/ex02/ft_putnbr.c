/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:14:43 by ysaroyan          #+#    #+#             */
/*   Updated: 2024/09/21 16:35:15 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_digit(int digit)
{
	char	c;

	c = digit + 48;
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb / 10 != 0)
			ft_putnbr(-(nb / 10));
		print_digit(-(nb % 10));
		return ;
	}
	if (nb / 10 != 0)
		ft_putnbr(nb / 10);
	print_digit(nb % 10);
}
