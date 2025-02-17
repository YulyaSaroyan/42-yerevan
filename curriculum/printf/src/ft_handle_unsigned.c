/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:22:55 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/25 21:42:41 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	checker(t_flags *flags, int padding, unsigned int n)
{
	int	size;

	size = 0;
	if (flags && flags->zero_pad && !flags->left_align && flags->precision < 0)
		size += ft_putnchar('0', padding);
	if (flags && !flags->left_align
		&& (!flags->zero_pad || flags->precision != -1))
		size += ft_putnchar(' ', padding);
	if (flags && flags->precision >= 0)
		size += ft_putnchar('0', flags->precision - ft_numlen_base(n, 10));
	if (n != 0 || flags->precision != 0)
		size += ft_putnbr_base_helper(n, "0123456789", flags);
	if (flags && flags->left_align)
		size += ft_putnchar(' ', padding);
	return (size);
}

int	ft_handle_unsigned(unsigned int n, t_flags *flags)
{
	int	num_len;
	int	padding;
	int	printed_chars;

	printed_chars = 0;
	num_len = ft_numlen_base(n, 10);
	if (flags && flags->precision > num_len)
		num_len = flags->precision;
	padding = 0;
	if (flags && flags->width > num_len)
	{
		if (flags->precision > num_len)
			padding = flags->width - flags->precision;
		else
			padding = flags->width - num_len;
	}
	if (!n && flags->precision == 0 && flags->width > 0)
		padding += 1;
	printed_chars += checker(flags, padding, n);
	return (printed_chars);
}
