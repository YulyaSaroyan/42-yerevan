/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:05:04 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/30 15:51:19 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <limits.h>

typedef struct s_flags
{
	int	left_align;
	int	zero_pad;
	int	width;
	int	precision;
	int	alt_form;
	int	space;
	int	plus;
}	t_flags;
typedef struct s_pad
{
	int		padding;
	char	pad_char;
}	t_pad;
int		ft_printf(const char *format, ...);
int		ft_handle_char(char c, t_flags *flags);
int		ft_handle_decimal(int n, t_flags *flags);
int		ft_handle_hex(unsigned int n, char format, t_flags *flags);
int		ft_handle_percent(t_flags *flags);
int		ft_handle_pointer(void *ptr, t_flags *flags);
int		ft_handle_string(char *str, t_flags *flags);
int		ft_handle_unsigned(unsigned int n, t_flags *flags);
int		ft_putnbr_base_helper(unsigned long nbr, const char *base,
			t_flags *flagis);
int		ft_putnbr_helper(int n, t_flags *flags);
int		ft_putstr_helper(char *s);
int		ft_putnchar(char c, int n);
int		ft_numlen_base(unsigned long n, int base);
//decimal utils
int		print_sign(int is_negative, t_flags *flags);
int		get_pad_len(t_flags *flags, int num, int len, int is_negative);
char	get_pad_char(t_flags *flags);
int		handle_precision(t_flags *flags, int len);
int		handle_padding(t_pad pad, int is_negative, t_flags *flags);
#endif
