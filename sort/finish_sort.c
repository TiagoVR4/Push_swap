/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagvr <tiagvr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:56:53 by tiagalex          #+#    #+#             */
/*   Updated: 2025/03/25 00:17:01 by tiagvr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	finish_sort(t_node **stack_a, t_node **stack_b)
{
	complete_last_chunk(stack_a, stack_b);
	final_adjust(stack_a);
	while (*stack_b)
		call_push(stack_a, stack_b, 'a');
}

void	complete_last_chunk(t_node **stack_a, t_node **stack_b)
{
	int		last_chunk;
	int		target;
	int		pos;
	t_node	*current_a;
	t_node	*current_b;

	last_chunk = (*stack_a)->prev->chunk;
	current_b = *stack_b;
	while (current_b->chunk == last_chunk)
	{
		target = current_b->index;
		pos = 0;
		current_a = *stack_a;

		if (current_a->index < target && current_a->next->index > target)
		pos++;
		current_a = current_a->next;

		if (pos == stack_size(stack_a))
			pos--;
		execute_rotations(stack_a, stack_b, pos, 'a');
		call_push(stack_a, stack_b, 'a');
		current_b = *stack_b;
	}
}

void	final_adjust(t_node **stack)
{
	int		index_min;
	int		pos;
	int		rotations;

	index_min = find_min_index(stack);
	pos = find_pos(stack, index_min);
	rotations = index_top(stack, pos);
	execute_rotations(NULL, stack, rotations, 'b');
}

int	find_min_index(t_node **stack)
{
	t_node	*current;
	int		min_index;
	int		flag;

	current = *stack;
	min_index = current->index;
	flag = 1;
	while (flag || current != *stack)
	{
		flag = 0;
		if (current->index < min_index)
			min_index = current->index;
		current = current->next;
	}
	return (min_index);
}