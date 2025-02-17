/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:20:34 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/29 19:03:00 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_decimal(int num, t_flags *flags)
{
	int		size;
	char	*str;
	int		len;
	t_pad	pad;

	size = 0;
	pad.pad_char = get_pad_char(flags);
	str = ft_itoa(num);
	if (!str)
		return (0);
	len = ft_strlen(str);
	pad.padding = get_pad_len(flags, num, len, str[0] == '-');
	size += handle_padding(pad, str[0] == '-', flags);
	size += handle_precision(flags, len - (str[0] == '-'));
	if (!(num == 0 && flags->precision == 0))
		size += write(1, str + (str[0] == '-'),
				ft_strlen(str) - (str[0] == '-'));
	if (flags->left_align)
		size += ft_putnchar(' ', pad.padding);
	free(str);
	return (size);
}
