/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:05:56 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/19 19:39:05 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_pointer(void *ptr)
{
	unsigned long	address;
	int				len;

	address = (unsigned long)ptr;
	len = ft_putstr_helper("0x");
	len += ft_putnbr_base_helper(address, "0123456789abcdef");
	return (len);
}
