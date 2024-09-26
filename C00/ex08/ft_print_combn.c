/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:34:43 by ysaroyan          #+#    #+#             */
/*   Updated: 2024/09/08 15:34:21 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnumber(char nums[10], int size, int is_last)
{
	int		j;
	char	ch;

	j = 0;
	while (j < size)
	{
		ch = nums[j] + '0';
		write(1, &ch, 1);
		j++;
	}
	if (!is_last)
		write(1, ", ", 2);
}

int	check_nums(char nums[10], int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
		if (nums[i] >= nums[i + 1])
			return (0);
	return (1);
}

void	print_recursive(int n, int size, char nums[10])
{
	int	i;
	int	is_last;

	is_last = 0;
	i = size - n;
	if (n < 1 || n > 9)
		return ;
	while (i <= 10 - n)
	{
		nums[size - n] = i;
		if (n > 1)
			print_recursive(n - 1, size, nums);
		if (n == 1 && check_nums(nums, size))
		{
			is_last = (nums[0] == (10 - size));
			putnumber(nums, size, is_last);
		}
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	nums[10];

	print_recursive(n, n, nums);
}
