/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:55:45 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/03/01 18:12:16 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	*arr_dup(int *arr, int size)
{
	int	*dup;
	int	i;

	dup = malloc(sizeof(int) * size);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dup[i] = arr[i];
		++i;
	}
	return (dup);
}

t_arr	*create_array(char **splitted)
{
	int	i;
	int	*arr;
	int	size;
	t_arr	*arr_struct;

	size = 0;
	while(splitted[size])
		++size;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = -1;
	while (splitted[++i])
		arr[i] = ft_atoi(splitted[i]);
	arr_struct = malloc(sizeof(t_arr));
	if (!arr_struct)
	{
		free(arr);
		return (NULL);
	}
	arr_struct->length = size;
	arr_struct->arr = arr;
	arr_struct->sorted_arr = arr_dup(arr, size);
	if (!arr_struct->sorted_arr)
	{
		free(arr);
		free(arr_struct);
		return (NULL);
	}
	bubble_sort(arr_struct);
	free_splitted(splitted);
	return (arr_struct);
}

int	is_sorted(t_arr *arr_struct)
{
	int	i;

	i = 0;
	if (arr_struct->length < 2)
		return (1);
	while (++i < arr_struct->length)
		if (arr_struct->arr[i] <= arr_struct->arr[i - 1])
			return (0);
	return (1);
}

void	bubble_sort(t_arr *arr_struct)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < arr_struct->length - 1)
	{
		j = -1;
		while (++j < arr_struct->length - i - 1)
		{
			if (arr_struct->sorted_arr[j] > arr_struct->sorted_arr[j + 1])
			{
				temp = arr_struct->sorted_arr[j];
				arr_struct->sorted_arr[j] = arr_struct->sorted_arr[j + 1];
				arr_struct->sorted_arr[j + 1] = temp;
			}
		}
	}
}
