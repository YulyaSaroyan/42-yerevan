/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:59:19 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/27 16:19:39 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack_2(t_stack *stack_a)
{
	int	top;
	int	bottom;

	top = stack_a->head->value;
	bottom = stack_a->head->prev->value;
	if (top > bottom)
		do_and_print(stack_a, ra, "ra");
}

static void	sort_stack_3(t_stack *stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = stack_a->head->value;
	middle = stack_a->head->next->value;
	bottom = stack_a->head->prev->value;
	if (top > middle && top < bottom && middle < bottom)
		do_and_print(stack_a, sa, "sa");
	if (top > middle && top > bottom && middle > bottom)
	{
		do_and_print(stack_a, sa, "sa");
		do_and_print(stack_a, rra, "rra");
	}
	if (top > middle && top > bottom && middle < bottom)
		do_and_print(stack_a, ra, "ra");
	if (top < middle && top < bottom && middle > bottom)
	{
		do_and_print(stack_a, sa, "sa");
		do_and_print(stack_a, ra, "ra");
	}
	if (top < middle && top > bottom && middle > bottom)
		do_and_print(stack_a, rra, "rra");
}

static void	sort_stack_4(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = init_stack();
	if (!stack_b)
	{
		free_stack(stack_a);
		return ;
	}
	find_max_and_push_b(stack_a->head, stack_a);
	do_both_and_print(stack_a, stack_b, pb, "pb");
	sort_stack_3(stack_a);
	do_both_and_print(stack_a, stack_b, pa, "pa");
	do_and_print(stack_a, ra, "ra");
	free_stack(stack_b);
}

static void	sort_stack_5(t_stack *stack_a)
{
	int	size;
	t_stack	*stack_b;

	stack_b = init_stack();
	if (!stack_b)
	{
		free_stack(stack_a);
		return ;
	}
	size = stack_a->size;
	while (size--)
	{
		if (stack_a->head->index == 0 || stack_a->head->index == 1)
			do_both_and_print(stack_a, stack_b, pb, "pb");
		else
			do_and_print(stack_a, ra, "ra");
	}
	sort_stack_3(stack_a);
	do_both_and_print(stack_a, stack_b, pa, "pa");
	do_both_and_print(stack_a, stack_b, pa, "pa");
	if (stack_a->head->index > stack_a->head->next->index)
		do_and_print(stack_a, sa, "sa");
	free_stack(stack_b);
}

void	make_butterfly(t_stack *stack_a, t_stack *stack_b, int chunk)
{
	int		counter;
	t_node	*lst;

	counter = 0;
	while (stack_a->head != NULL)
	{
		lst = stack_a->head;
		if (lst->index <= counter)
		{
			do_both_and_print(stack_a, stack_b, pb, "pb");
			do_and_print(stack_b, rb, "rb");
			++counter;
		}
		else if (lst->index <= counter + chunk)
		{
			do_both_and_print(stack_a, stack_b, pb, "pb");
			++counter;
		}
		else
			do_and_print(stack_a, ra, "ra");
	}
}

static void	sort_stack_bigger(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*lst;

	while (stack_b->head != NULL)
	{
		lst = stack_b->head;
		find_max_and_push_a(lst, stack_b);
		do_both_and_print(stack_a, stack_b, pa, "pa");
	}
}

static void	sort_stack(t_stack *stack_a)
{
	int	chunk;
	t_stack	*stack_b;

	stack_b = init_stack();
	if (!stack_b)
	{
		free_stack(stack_a);
		return ;
	}
	chunk = generate_chunk(stack_a->size);
	make_butterfly(stack_a, stack_b, chunk);
	sort_stack_bigger(stack_a, stack_b);
	free_stack(stack_b);
}

void	sort(t_stack *stack_a)
{
	if (stack_a->size == 2)
		sort_stack_2(stack_a);
	else if (stack_a->size == 3)
		sort_stack_3(stack_a);
	else if (stack_a->size == 4)
		sort_stack_4(stack_a);
	else if (stack_a->size == 5)
		sort_stack_5(stack_a);
	else if (stack_a->size >= 6)
		sort_stack(stack_a);
}
