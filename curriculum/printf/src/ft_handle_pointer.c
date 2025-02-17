/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:05:56 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/25 21:39:00 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	checker(t_flags *flags, unsigned long address,
	int padding, void *ptr)
{
	int	size;
	int	len;

	size = 0;
	if (flags && flags->precision > ft_numlen_base(address, 16))
	{
		len = flags->precision - ft_numlen_base(address, 16);
		size += ft_putnchar('0', len);
	}
	if (flags && flags->zero_pad && !flags->left_align && padding > 0)
		size += ft_putnchar('0', padding);
	if (!ptr)
		size += ft_putstr_helper("0");
	else
		size += ft_putnbr_base_helper(address, "0123456789abcdef", flags);
	if (flags && flags->left_align)
		size += ft_putnchar(' ', padding);
	return (size);
}

int	ft_handle_pointer(void *ptr, t_flags *flags)
{
	unsigned long	address;
	int				num_len;
	int				padding;
	int				printed_chars;
	int				total_len;

	printed_chars = 0;
	address = (unsigned long)ptr;
	num_len = ft_numlen_base(address, 16);
	if (flags && flags->precision > num_len)
		num_len = flags->precision;
	total_len = num_len + 2;
	padding = 0;
	if (flags && flags->width > total_len)
		padding = flags->width - total_len;
	if (flags && !flags->left_align && !flags->zero_pad)
		printed_chars += ft_putnchar(' ', padding);
	printed_chars += ft_putstr_helper("0x");
	printed_chars += checker(flags, address, padding, ptr);
	return (printed_chars);
}
