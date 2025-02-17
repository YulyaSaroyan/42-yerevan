/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:30:39 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/29 18:59:43 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_helper(unsigned long nbr, const char *base, t_flags *flags)
{
	int	base_len;
	int	len;

	len = 0;
	base_len = ft_strlen(base);
	if (nbr >= (unsigned long)base_len)
		len += ft_putnbr_base_helper(nbr / base_len, base, flags);
	len += write(1, &base[nbr % base_len], 1);
	return (len);
}
