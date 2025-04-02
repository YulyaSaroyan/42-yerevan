/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <ysaroyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:17:27 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/03/31 19:37:14 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_valid(char *num)
{
	int	i;

	if (num[0] == '0')
		return (0);
	if (num[0] != '0' && ft_atoi(num) == 0)
		return (0);
	i = -1;
	while (num[++i])
		if (!ft_isdigit(num[i]))
			return (0);
	return (1);
}

int	is_valid_args(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (0);
	i = 0;
	while (argv[++i])
		if (!is_valid(argv[i]))
			return (0);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
