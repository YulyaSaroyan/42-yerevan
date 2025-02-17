/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:54:12 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/21 14:00:28 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_handle_char(va_arg(args, int)));
	else if (c == 's')
		return (ft_handle_string(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_handle_pointer(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_handle_decimal(va_arg(args, int)));
	else if (c == 'u')
		return (ft_handle_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_handle_hex(va_arg(args, unsigned int), c));
	else if (c == '%')
		return (ft_handle_percent());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_len;
	int		i;

	total_len = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			total_len += ft_handle_format(format[i], args);
		}
		else
			total_len += ft_handle_char(format[i]);
		i++;
	}
	va_end(args);
	return (total_len);
}
