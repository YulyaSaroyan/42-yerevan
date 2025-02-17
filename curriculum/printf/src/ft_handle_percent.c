/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:26:01 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/20 19:26:00 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_percent(t_flags *flags)
{
	int	padding;
	int	printed_chars;

	printed_chars = 0;
	padding = 0;
	if (flags && flags->width > 1)
		padding = flags->width - 1;
	if (flags && flags->zero_pad && !flags->left_align)
		printed_chars += ft_putnchar('0', padding);
	if (flags && !flags->left_align && !flags->zero_pad)
		printed_chars += ft_putnchar(' ', padding);
	printed_chars += write(1, "%", 1);
	if (flags && flags->left_align)
		printed_chars += ft_putnchar(' ', padding);
	return (printed_chars);
}
