/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:24:58 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/19 18:48:20 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_hex(unsigned int n, char format)
{
	if (format == 'x')
		return (ft_putnbr_base_helper(n, "0123456789abcdef"));
	else if (format == 'X')
		return (ft_putnbr_base_helper(n, "0123456789ABCDEF"));
	return (0);
}
