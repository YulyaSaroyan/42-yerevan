/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:54:12 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/30 19:09:48 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_flags(t_flags *flags)
{
	flags->left_align = 0;
	flags->zero_pad = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->alt_form = 0;
	flags->space = 0;
	flags->plus = 0;
}

static void	ft_parse_dot_flag(t_flags *flags, const char *format, int *i)
{
	if (format[*i] == '.')
	{
		(*i)++;
		flags->precision = ft_atoi(&format[*i]);
		while (format[*i] && ft_isdigit(format[*i]))
			(*i)++;
	}
}

static int	ft_parse_flags(const char *format,
		int *i, t_flags *flags)
{
	ft_init_flags(flags);
	while (format[*i] && (format[*i] == '-' || format[*i] == '0' || \
			format[*i] == '#' || format[*i] == ' ' || format[*i] == '+'))
	{
		if (format[*i] == '-')
			flags->left_align = 1;
		else if (format[*i] == '0')
			flags->zero_pad = 1;
		else if (format[*i] == '#')
			flags->alt_form = 1;
		else if (format[*i] == ' ')
			flags->space = 1;
		else if (format[*i] == '+')
			flags->plus = 1;
		(*i)++;
	}
	if (format[*i] && ft_isdigit(format[*i]))
	{
		flags->width = ft_atoi(&format[*i]);
		while (format[*i] && ft_isdigit(format[*i]))
			(*i)++;
	}
	ft_parse_dot_flag(flags, format, i);
	return (0);
}

static int	ft_handle_format(char c, t_flags *flags, va_list args)
{
	if (c == 'c')
		return (ft_handle_char(va_arg(args, int), flags));
	else if (c == 's')
		return (ft_handle_string(va_arg(args, char *), flags));
	else if (c == 'p')
		return (ft_handle_pointer(va_arg(args, void *), flags));
	else if (c == 'd' || c == 'i')
		return (ft_handle_decimal(va_arg(args, int), flags));
	else if (c == 'u')
		return (ft_handle_unsigned(va_arg(args, unsigned int), flags));
	else if (c == 'x' || c == 'X')
		return (ft_handle_hex(va_arg(args, unsigned int), c, flags));
	else if (c == '%')
		return (ft_handle_percent(flags));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_len;
	int		i;
	t_flags	flags;

	total_len = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			ft_parse_flags(format, &i, &flags);
			total_len += ft_handle_format(format[i], &flags, args);
		}
		else
			total_len += ft_handle_char(format[i], NULL);
		i++;
	}
	va_end(args);
	return (total_len);
}
