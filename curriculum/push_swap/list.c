/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:35:20 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/03/01 19:13:55 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_index(t_arr *arr_struct, int value)
{
	int	i;

	i = -1;
	while (++i < arr_struct->length)
	{
		if (arr_struct->sorted_arr[i] == value)
			return (i);
	}
	return (0);
}

static t_node	*create_head(t_arr *arr_struct)
{
	t_node	*head;

	head = (t_node *)malloc(sizeof (t_node));
	if (!head)
		return (NULL);
	head->value = arr_struct->arr[0];
	head->next = head;
	head->prev = head;
	head->index = find_index(arr_struct, arr_struct->arr[0]);
	return (head);
}

static int	list_size(t_node *head)
{
	t_node	*lst;
	int		size;

	size = 0;
	lst = head;
	while (1)
	{
		size++;
		lst = lst->next;
		if (lst == head)
			break ;
	}
	return (size);
}

static t_node	*create_node(t_arr *arr_struct, t_node *current, t_node *head, int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->prev = current;
	new->next = head;
	new->index = find_index(arr_struct, value);
	current->next = new;
	head->prev = new;
	return (new);
}

static t_node	*create_list(t_arr *arr_struct)
{
	t_node	*head;
	t_node	*current;
	int		i;

	head = create_head(arr_struct);
	i = 0;
	current = head;
	while (++i < arr_struct->length)
		current = create_node(arr_struct, current, head, arr_struct->arr[i]);
	return (head);
}

t_stack	create_stack(t_arr *arr_struct)
{
	t_stack	stack;
	stack.head = create_list(arr_struct);
	stack.size = list_size(stack.head);
	free(arr_struct->sorted_arr);
	free(arr_struct->arr);
	free(arr_struct);
	return (stack);
}
