/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:54:28 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/25 16:40:52 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_duplicate(char *str, char **splitted, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (are_same_num(splitted[i], str))
			return (1);
		++i;
	}
	return (0);
}

static void	validate_long_arg(char *arg)
{
	int	j;

	if (arg[0] == '-' || arg[0] == '+')
	{
		if (ft_atoi(arg) == 0)
			print_error("Error");
	}
	else
	{
		j = -1;
		while (arg[++j])
		{
			if ((arg[0] == '-' || arg[0] == '+')
				&& (arg[1] != '-' || arg[1] != '+'))
				++j;
			if (!ft_isspace(arg[j]) && !ft_isdigit(arg[j]))
				print_error("Error");
		}
	}
}

void	validate_format(int argc, char **argv)
{
	int	i;
	int	j;
	int	seen;

	i = 1;
	while (i < argc)
	{
		seen = 0;
		j = -1;
		while (argv[i][++j])
			if (ft_isdigit(argv[i][j]))
				seen = 1;
		if (!seen)
			print_error("Error");
		if (ft_strlen(argv[i]) == 1 && is_not_num(argv[i]))
			print_error("Error");
		else
			validate_long_arg(argv[i]);
		++i;
	}
}

void	validate_duplication(char **splitted_arg)
{
	int	i;

	i = -1;
	while (splitted_arg[++i])
		if (is_duplicate(splitted_arg[i], splitted_arg, i))
			print_error("Error");
	i = -1;
	while (splitted_arg[++i])
	{
		if (ft_atoi(splitted_arg[i]) > INT_MAX
				|| ft_atoi(splitted_arg[i]) < INT_MIN)
			print_error("Error");
	}
}
