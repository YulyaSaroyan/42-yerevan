/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:56:36 by ysaroyan          #+#    #+#             */
/*   Updated: 2024/09/12 19:56:52 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_first_last(int x)
{
	int	j;

	j = 0;
	while (j < x)
	{
		if (j == 0)
			ft_putchar('A');
		else if (j == x - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
		j++;
	}
	ft_putchar('\n');
}

void	ft_print_middle(int x)
{
	int	j;

	j = 0;
	while (j < x)
	{
		if (j == 0 || x - j == 1)
			ft_putchar('B');
		else
			ft_putchar(' ');
		j++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	if (x < 1 || y < 1 || x > 100 || y > 100)
		write(1, "please provide numbers between range of 1 - 100", 47);
		return ;
	i = 0;
	while (i < y)
	{
		if (i == 0 || i == y - 1)
			ft_print_first_last(x);
		else
			ft_print_middle(x);
		i++;
	}
}
