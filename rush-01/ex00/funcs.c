/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 13:59:12 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/15 17:36:55 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "unistd.h"

int	len(int *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	print(int map[9][9])
{
	int		i;
	int		j;
	char	c;
	int		s;

	s = len(map[0]);
	i = 0;
	j = 0;
	while (i < s)
	{
		j = 0;
		while (j < s)
		{
			c = map[i][j] + '0';
			write (1, &c, 1);
			write (1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	rep(int map[9][9], int i, int j, int v)
{
	int		k;
	int		l;

	k = i;
	l = j;
	while (--k >= 0)
	{
		if (map[k][j] == v)
			return (0);
	}
	while (--l >= 0)
	{
		if (map[i][l] == v)
			return (0);
	}
	return (1);
}

void	rev(int c, int s, int str[9])
{
	int		i;
	int		temp;

	i = -1;
	if (c == 1)
	{
		while (++i < s / 2)
		{
			temp = str[i];
			str[i] = str[s - i - 1];
			str[s - i - 1] = temp;
		}
	}
}

void	loop(int map[9][9], int s[2], int v, int l)
{
	int		i;
	int		j;

	i = s[0];
	while (i < l)
	{
		j = s[1];
		while (j < l)
		{
			map[i][j] = v;
			j++;
		}
		i++;
	}
}
