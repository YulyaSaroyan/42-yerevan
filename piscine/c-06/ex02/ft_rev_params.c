/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:53:11 by ysaroyan          #+#    #+#             */
/*   Updated: 2024/09/18 23:10:01 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		while (argc > 1)
		{
			i = 0;
			while (argv[argc - 1][i])
			{
				write(1, &argv[argc - 1][i], 1);
				i++;
			}
			write(1, "\n", 1);
			argc--;
		}
	}
	return (0);
}
