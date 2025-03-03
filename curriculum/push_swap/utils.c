/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:56:11 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/26 14:44:38 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(char *operation)
{
	ft_putstr_fd(operation, 1);
	ft_putchar_fd('\n', 1);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->size = 0;
	return (stack);
}

void	free_arr_struct(t_arr *arr_struct)
{
	free(arr_struct->sorted_arr);
	free(arr_struct->arr);
	free(arr_struct);
}

int	generate_chunk(int size)
{
	int	chunk;

	chunk = 1;
	if (size < 50)
		chunk = 3 + (size - 6) / 7;
	else if (size >= 50 && size < 100)
		chunk = 10 + (size - 50) / 8;
	else if (size >= 100 && size < 350)
		chunk = 18 + (size - 100) / 9;
	else if (size >= 350 && size <= 500)
		chunk = 27 + (size - 350) / 15;
	else if (size > 500)
		chunk = 37 + (size - 500) / 20;
	return (chunk);
}

void free_list(t_node *head)
{
    if (!head) return;
    t_node *current;
    t_node *next;

	current = head;
	while (1)
	{
		next = current->next;
		free(current);
		current = next;
		if (current == head)
			break ;
	}
}

void free_stack(t_stack *stack)
{
    if (!stack)
        return;
    if (stack->head)
        free_list(stack->head);
    free(stack);
}

void	find_max_and_push_a(t_node *lst, t_stack *stack_b)
{
	int	i;
	int	is_tail;

	i = 0;
	is_tail = 0;
	while (is_tail == 0)
	{
		if (lst->index == stack_b->size - 1)
		{
			if (i > stack_b->size - i - 1)
			{
				while (i++ != stack_b->size)
					do_and_print(stack_b, rrb, "rrb");
			}
			else
				while (i-- > 0)
					do_and_print(stack_b, rb, "rb");
			break ;
		}
		++i;
		lst = lst->next;
		if (lst == stack_b->head)
			is_tail = 1;
	}
}

void	find_max_and_push_b(t_node *lst, t_stack *stack_a)
{
	int	i;
	int	is_tail;

	i = 0;
	is_tail = 0;
	while (is_tail == 0)
	{
		if (lst->index == stack_a->size - 1)
		{
			if (i > stack_a->size - i - 1)
			{
				while (i++ != stack_a->size)
					do_and_print(stack_a, rra, "rra");
			}
			else
				while (i-- > 0)
					do_and_print(stack_a, ra, "ra");
			break ;
		}
		++i;
		lst = lst->next;
		if (lst == stack_a->head)
			is_tail = 1;
	}
}

