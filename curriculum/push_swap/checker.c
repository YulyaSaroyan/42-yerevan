/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:15:32 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/03/01 18:04:23 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_instruction(char *instruction, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(instruction, "sa") == 0)
		sa(stack_a);
	else if (ft_strcmp(instruction, "sb") == 0)
		sb(stack_b);
	else if (ft_strcmp(instruction, "ss") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(instruction, "pa") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(instruction, "pb") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(instruction, "ra") == 0)
		ra(stack_a);
	else if (ft_strcmp(instruction, "rb") == 0)
		rb(stack_b);
	else if (ft_strcmp(instruction, "rr") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(instruction, "rra") == 0)
		rra(stack_a);
	else if (ft_strcmp(instruction, "rrb") == 0)
		rrb(stack_b);
	else if (ft_strcmp(instruction, "rrr") == 0)
		rrr(stack_a, stack_b);
	else
		print_error("Error");
}

void	read_and_execute_instructions(t_stack *stack_a, t_stack *stack_b)
{
	char	*instruction;
	char	*trimmed;

	while (1)
	{
		instruction = get_next_line(0);
		if (!instruction)
			break ;
		trimmed = ft_strtrim(instruction, "\n");
		execute_instruction(trimmed, stack_a, stack_b);
		free(instruction);
		free(trimmed);
	}
}

int	is_sorted_and_empty(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	int		size;

	if (stack_b->size != 0)
		return (0);
	if (stack_a->size == 0)
		return (1);
	if (stack_a->size == 1)
		return (1);
	current = stack_a->head;
	size = stack_a->size;
	while (--size)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*arg;
	char	**splitted_arg;
	t_arr	*arr_struct;

	if (argc == 1)
		return (0);
	validate_format(argc, argv);
	arg = get_arg(argc, argv);
	splitted_arg = ft_split(arg, ' ');
	free(arg);
	validate_duplication(splitted_arg);
	arr_struct = create_array(splitted_arg);
	if (!arr_struct)
	{
		free_splitted(splitted_arg);
		return (0);
	}
	stack_a = create_stack(arr_struct);
	if (!stack_a)
	{
		free_arr_struct(arr_struct);
		return (0);
	}
	stack_b = init_stack();
	if (!stack_b)
	{
		free_stack(stack_a);
		return (0);
	}
	read_and_execute_instructions(stack_a, stack_b);
	if (is_sorted_and_empty(stack_a, stack_b))
		print("OK");
	else
		print("KO");
	free_stack(stack_b);
	free_stack(stack_a);
	return (0);
}