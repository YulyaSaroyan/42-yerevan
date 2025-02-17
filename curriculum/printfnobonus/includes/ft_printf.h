/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:05:04 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/20 17:54:28 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *format, ...);
int	ft_handle_char(char c);
int	ft_handle_decimal(int n);
int	ft_handle_hex(unsigned int n, char format);
int	ft_handle_percent(void);
int	ft_handle_pointer(void *ptr);
int	ft_handle_string(char *str);
int	ft_handle_unsigned(unsigned int n);
int	ft_putnbr_base_helper(unsigned long nbr, const char *base);
int	ft_putnbr_helper(int n);
int	ft_putstr_helper(char *s);

#endif
