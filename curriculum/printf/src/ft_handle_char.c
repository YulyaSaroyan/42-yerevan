/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:01:55 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/25 21:02:47 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_char(char c, t_flags *flags)
{
	int	printed_chars;

	printed_chars = 0;
	if (!flags)
		return (write(1, &c, 1));
	if (!flags->left_align && flags->width > 1)
		printed_chars += ft_putnchar(' ', flags->width - 1);
	printed_chars += write(1, &c, 1);
	if (flags->left_align && flags->width > 1)
		printed_chars += ft_putnchar(' ', flags->width - 1);
	return (printed_chars);
}
