/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:30:39 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/20 18:09:18 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_helper(unsigned long nbr, const char *base)
{
	int	base_len;
	int	len;

	len = 0;
	base_len = ft_strlen(base);
	if (nbr >= (unsigned long)base_len)
		len += ft_putnbr_base_helper(nbr / base_len, base);
	len += ft_handle_char(base[nbr % base_len]);
	return (len);
}
