/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:07:02 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/25 21:09:17 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_sign(int is_negative, t_flags *flags)
{
	if (is_negative)
		return (write(1, "-", 1));
	if (flags->plus)
		return (write(1, "+", 1));
	if (flags->space)
		return (write(1, " ", 1));
	return (0);
}

int	get_pad_len(t_flags *flags, int num, int len, int is_negative)
{
	int	padding;

	padding = 0;
	if (flags->width > len && flags->precision >= len)
		padding = flags->width - flags->precision - is_negative;
	else if (flags->width > len)
		padding = flags->width - len;
	if (flags->width && !num && flags->precision == 0)
		padding += 1;
	if (num >= 0 && (flags->plus || flags->space))
		padding -= 1;
	return (padding);
}

char	get_pad_char(t_flags *flags)
{
	char	pad_char;

	pad_char = ' ';
	if (flags->zero_pad && flags->precision == -1)
		pad_char = '0';
	return (pad_char);
}

int	handle_precision(t_flags *flags, int len)
{
	if (flags->precision != -1 && flags->precision > len)
		return (ft_putnchar('0', flags->precision - len));
	return (0);
}

int	handle_padding(t_pad pad, int is_negative, t_flags *flags)
{
	int	len;

	len = 0;
	if (pad.pad_char == '0')
		len += print_sign(is_negative, flags);
	if (!flags->left_align)
		len += ft_putnchar(pad.pad_char, pad.padding);
	if (pad.pad_char != '0')
		len += print_sign(is_negative, flags);
	return (len);
}
