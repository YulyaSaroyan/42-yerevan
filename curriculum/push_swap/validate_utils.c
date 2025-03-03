/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:49:55 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/27 17:47:26 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_splitted(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		++i;
	}
	free(splitted);
}

void	print_error(char *error)
{
	ft_putstr_fd(error, 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}

char	*get_arg(int argc, char **argv)
{
	char	*arg;
	char	*temp_join;
	int		i;

	i = 1;
	arg = "";
	while (i < argc)
	{
		if (i == 1)
			temp_join = ft_strjoin(arg, "");
		else
			temp_join = ft_strjoin(arg, " ");
		arg = ft_strjoin(temp_join, argv[i]);
		free(temp_join);
		++i;
	}
	return (arg);
}

int	is_not_num(char *num)
{
	return (num[0] != '0' && ft_atoi(num) == 0);
}

int	are_same_num(char *num1, char *num2)
{
	return (ft_atoi(num1) == ft_atoi(num2));
}
