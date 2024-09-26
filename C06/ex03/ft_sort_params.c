/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:08:37 by ysaroyan          #+#    #+#             */
/*   Updated: 2024/09/21 21:42:02 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_bubble_sort(char **arr, int n)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < n - 1)
	{
		j = 1;
		while (j < n - i)
		{
			if (ft_strcmp(arr[j], arr[j + 1]) > 0)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_print_args(char **args, int n)
{
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		j = 0;
		while (args[i][j])
		{
			write(1, &args[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	ft_bubble_sort(argv, argc);
	ft_print_args(argv, argc);
	return (0);
}
