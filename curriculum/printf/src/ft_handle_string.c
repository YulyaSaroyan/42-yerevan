/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:03:07 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/21 14:55:00 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_string(char *str, t_flags *flags)
{
	int	len;
	int	padding;
	int	printed_chars;

	printed_chars = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags && flags->precision >= 0 && flags->precision < len)
		len = flags->precision;
	padding = 0;
	if (flags && flags->width > len)
		padding = flags->width - len;
	if (flags && !flags->left_align && !flags->zero_pad)
		printed_chars += ft_putnchar(' ', padding);
	printed_chars += write(1, str, len);
	if (flags && flags->left_align)
		printed_chars += ft_putnchar(' ', padding);
	return (printed_chars);
}
