/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:29:47 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/20 15:13:55 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_helper(int n)
{
	long	nbr;
	int		len;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		len += ft_handle_char('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		len += ft_putnbr_helper(nbr / 10);
	len += ft_handle_char((nbr % 10) + '0');
	return (len);
}
