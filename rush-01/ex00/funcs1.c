/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:37:07 by ysaroyan          #+#    #+#             */
/*   Updated: 2024/09/15 18:27:51 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "unistd.h"

void	loop(int map[9][9], int s[2], int v, int l);

void	fill(int count, int map[9][9])
{
	int		ids[2];

	ids[0] = count / 4;
	ids[1] = 0;
	loop(map, ids, 0, 9);
	ids[0] = 0;
	ids[1] = count / 4;
	loop(map, ids, 0, 9);
	ids[1] = 0;
	loop(map, ids, 1, count / 4);
}

int	size_check(int *views, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		if (views[i] > count / 4)
			return (0);
		i++;
	}
	return (1);
}

int	input_check(char *argv, int *views, int *count)
{
	int		i;

	i = 0;
	while (argv[i])
	{
		if (i % 2 == 0 && argv[i] >= '1' && argv[i] <= '9')
		{
			views[*count] = argv[i] - '0';
			(*count)++;
			i++;
		}
		else if (i % 2 == 1 && argv[i] == ' ')
		{
			i++;
			continue ;
		}
		else
			return (0);
	}
	if (!size_check(views, *count))
		return (0);
	return (1);
}
