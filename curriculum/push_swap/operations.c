/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:22:52 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/03/01 17:59:24 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_and_print(t_stack *stack_a, void(*op)(t_stack *), char *operation)
{
	op(stack_a);
	print(operation);
}
void	do_both_and_print(t_stack *stack_a, t_stack *stack_b,
		void(*op)(t_stack *, t_stack *), char *operation)
{
	op(stack_a, stack_b);
	print(operation);
}

static t_node	*pop(t_stack *stack)
{
	t_node	*temp;

	if (!stack || !stack->head)
		return (NULL);
	temp = stack->head;
	if (stack->size == 1)
		stack->head = NULL;
	else
	{
		stack->head->prev->next = stack->head->next;
		stack->head->next->prev = stack->head->prev;
		stack->head = stack->head->next;
	}
	temp->next = NULL;
	temp->prev = NULL;
	stack->size--;
	return (temp);
}

static void push(t_stack *stack, t_node *node)
{
    if (!stack || !node)
        return;
    if (node->next != NULL || node->prev != NULL)
        return;
    if (!stack->head)
    {
        stack->head = node;
        node->next = node;
        node->prev = node;
    }
    else
    {
        node->prev = stack->head->prev;
        node->next = stack->head;
        stack->head->prev->next = node;
        stack->head->prev = node;
        stack->head = node;
    }
    stack->size++;
}

void	sa(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->head;
	second = first->next;

	if (stack->size == 2)
	{
		first->next = second;
		first->prev = second;
		second->next = first;
		second->prev = first;
		stack->head = second;
	}
	else
	{
		t_node	*third = second->next;
		t_node	*prev = first->prev;

		prev->next = second;
		third->prev = first;

		first->next = third;
		first->prev = second;

		second->next = first;
		second->prev = prev;

		stack->head = second;
	}
}

void	sb(t_stack *stack)
{
	sa(stack);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*top_b;

	if (!stack_b || stack_b->size == 0)
		return ;
	top_b = pop(stack_b);
	push(stack_a, top_b);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*top_a;

	if (!stack_a || stack_a->size == 0)
		return ;
	top_a = pop(stack_a);
	push(stack_b, top_a);
}

void	ra(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->next;
}

void	rb(t_stack *stack)
{
	ra(stack);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->prev;
}

void	rrb(t_stack *stack)
{
	rra(stack);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
