/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:37:56 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/29 18:52:50 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_digit(int num, int fd)
{
	char	ch;

	ch = num + 48;
	write(fd, &ch, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n / 10 != 0)
			ft_putnbr_fd(-(n / 10), fd);
		print_digit(-(n % 10), fd);
		return ;
	}
	if (n / 10 != 0)
		ft_putnbr_fd((n / 10), fd);
	print_digit((n % 10), fd);
}
