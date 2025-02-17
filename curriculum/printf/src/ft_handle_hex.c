/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:24:58 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/27 20:49:14 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	define_format(t_flags *flags, unsigned int n, char format)
{
	if (flags && flags->alt_form && n != 0)
	{
		if (format == 'x')
			return (ft_putstr_helper("0x"));
		else
			return (ft_putstr_helper("0X"));
	}
	return (0);
}

static char	*define_base(char format)
{
	if (format == 'x')
		return ("0123456789abcdef");
	else
		return ("0123456789ABCDEF");
}

static int	checker(t_flags *flags, unsigned int n, int padding, char *base)
{
	int	size;

	size = 0;
	if (flags && flags->precision > ft_numlen_base(n, 16))
		size += ft_putnchar('0', flags->precision - ft_numlen_base(n, 16));
	if (flags && flags->zero_pad && !flags->left_align && flags->precision < 0)
		size += ft_putnchar('0', padding);
	if (flags->precision != 0 || n)
		size += ft_putnbr_base_helper(n, base, flags);
	if (flags && flags->left_align)
		size += ft_putnchar(' ', padding);
	return (size);
}

int	ft_handle_hex(unsigned int n, char format, t_flags *flags)
{
	int		num_len;
	int		padding;
	int		printed_chars;
	char	*base;

	printed_chars = 0;
	base = define_base(format);
	num_len = ft_numlen_base(n, 16);
	if (flags && flags->precision > num_len)
		num_len = flags->precision;
	padding = 0;
	if (flags && flags->width > num_len)
		padding = flags->width - num_len;
	if (flags && flags->alt_form && n != 0)
		padding -= 2;
	if (!n && flags->precision == 0 && flags->width > 0)
		padding += 1;
	if (flags && !flags->left_align
		&& (!flags->zero_pad || (flags->precision >= 0)))
		printed_chars += ft_putnchar(' ', padding);
	printed_chars += define_format(flags, n, format);
	printed_chars += checker(flags, n, padding, base);
	return (printed_chars);
}
