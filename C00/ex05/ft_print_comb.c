/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:00:11 by ysaroyan          #+#    #+#             */
/*   Updated: 2024/09/08 15:28:46 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}

void	print_separator(void)
{
	write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i <= 7)
	{
		j = i + 1;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				print_num(i + '0', j + '0', k + '0');
				if (!(i == 7 && j == 8 && k == 9))
					print_separator();
				k++;
			}
			j++;
		}
		i++;
	}
}
