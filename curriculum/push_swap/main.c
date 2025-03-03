/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:52:13 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/03/01 18:07:56 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_len(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		++i;
	return (i);
}

int	main(int argc, char **argv)
{
	char	*arg;
	char	**splitted_arg;
	int		len;
	t_stack	stack_a;
	t_arr	*arr_struct;

	if (argc == 1)
		print_error("Error");
	validate_format(argc, argv);
	arg = get_arg(argc, argv);
	splitted_arg = ft_split(arg, ' ');
	validate_duplication(splitted_arg);
	len = count_len(splitted_arg);
	if (len == 1)
	{
		free_splitted(splitted_arg);
		return (0);
	}
	arr_struct = create_array(splitted_arg);
	if (!arr_struct)
		return (0);
	if (is_sorted(arr_struct))
	{
		free(arr_struct->arr);
		free(arr_struct);
		return (0);
	}
	stack_a = create_stack(arr_struct);
	sort(&stack_a);
	return (0);
}
