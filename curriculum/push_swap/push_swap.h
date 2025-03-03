/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:00:27 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/26 14:44:44 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_arr
{
	int	length;
	int	*arr;
	int	*sorted_arr;
}	t_arr;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
}	t_stack;

int		generate_chunk(int size);
void	free_arr_struct(t_arr *arr_struct);
void	free_stack(t_stack *stack);
void	find_max_and_push_b(t_node *lst, t_stack *stack_a);
void	find_max_and_push_a(t_node *lst, t_stack *stack_b);
t_stack	*init_stack(void);
void	bubble_sort(t_arr *arr_struct);
void	do_and_print(t_stack *stack_a, void(*op)(t_stack *), char *operation);
void	do_both_and_print(t_stack *stack_a, t_stack *stack_b,
		void(*op)(t_stack *, t_stack *), char *operation);
int		is_sorted(t_arr *arr_struct);
t_stack	*create_stack(t_arr *arr_struct);
t_arr	*create_array(char **splitted);
void	validate_format(int argc, char **argv);
void	validate_duplication(char **splitted_arg);
void	print_error(char *error);
int		is_not_num(char *num);
int		are_same_num(char *num1, char *num2);
char	*get_arg(int argc, char **argv);
void	free_splitted(char **splitted);
void	print(char *operation);
void	sa(t_stack *satck);
void	sb(t_stack *satck);
void	ss(t_stack *satck_a, t_stack *stack_b);
void	pa(t_stack *satck_a, t_stack *stack_b);
void	pb(t_stack *satck_a, t_stack *stack_b);
void	ra(t_stack *satck);
void	rb(t_stack *satck);
void	rr(t_stack *satck_a, t_stack *stack_b);
void	rra(t_stack *satck);
void	rrb(t_stack *satck);
void	rrr(t_stack *satck_a, t_stack *stack_b);
void	sort(t_stack *stack_a);

#endif
