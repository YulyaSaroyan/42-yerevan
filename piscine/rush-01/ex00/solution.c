/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:46:24 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/15 20:30:37 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int		len(int *str);

void	rev(int c, int s, int str[9]);

void	loop(int map[9][9], int s[2], int v, int l);

void	fill(int count, int map[9][9]);

int		input_check(char *argv, int *views, int *count);

int	checker(int str[9], int n, int s, int c)
{
	int		count;
	int		max;
	int		i;

	rev(c, s, str);
	max = 0;
	count = 0;
	i = -1;
	while (++i < s)
	{
		if (str[i] > max)
		{
			max = str[i];
			count++;
		}
	}
	if (count == n)
		return (1);
	else
		return (0);
}

int	check(int map[9][9], int *views)
{
	int		ids[4];
	int		col[9];

	ids[2] = len(map[0]);
	ids[0] = -1;
	while (++ids[0] < ids[2] * 4)
	{
		ids[3] = 1;
		if (ids[0] < ids[2] || (ids[0] < ids[2] * 3 && ids[0] >= ids[2] * 2))
			ids[3] = 0;
		ids[1] = -1;
		if (ids[0] < ids[2] * 2)
		{
			while (++ids[1] < ids[2])
				col[ids[1]] = map[ids[1]][ids[0] % ids[2]];
		}
		else if (ids[0] < ids[2] * 4)
		{
			while (++ids[1] < ids[2])
				col[ids[1]] = map[ids[0] % ids[2]][ids[1]];
		}
		if (!(checker(col, views[ids[0]], ids[2], ids[3])))
			return (0);
	}
	return (1);
}

void	print(int map[9][9]);

int		rep(int map[9][9], int i, int j, int v);

int	cond(int i, int s, int map[9][9], int *views)
{
	if (i == s)
	{
		if (check(map, views))
		{
			print(map);
			return (1);
		}
	}
	return (0);
}

int	rec(int map[9][9], int *views, int i, int j)
{
	int		v;
	int		s;

	s = len(map[0]);
	if (cond(i, s, map, views))
		return (1);
	v = 0;
	while (++v <= s && i < s)
	{
		if (rep(map, i, j, v))
		{
			map[i][j] = v;
			if (j < s - 1)
			{
				if (rec(map, views, i, j + 1))
					return (1);
			}
			else
			{
				if (rec(map, views, i + 1, 0))
					return (1);
			}
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		map[9][9];
	int		views[36];
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!input_check(argv[1], views, &count))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	fill(count, map);
	if (count % 4 == 0 && (count / 4 > 3 && count / 4 < 10)
		&& rec(map, views, 0, 0))
		return (0);
	else
		write(1, "Error\n", 6);
	return (0);
}
