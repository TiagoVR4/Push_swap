/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:56:53 by tiagalex          #+#    #+#             */
/*   Updated: 2025/03/27 16:44:09 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	finish_sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*current_b;
	int		target;
	int		last_chunk;
	int		rot_a;

	current_b = (*stack_b);
	last_chunk = (*stack_a)->chunk;
	while (current_b && last_chunk == current_b->chunk)
	{
		target = (*stack_b)->index;
		rot_a = calculate_rot_a(stack_a, target);
		execute_rotations(stack_a, NULL, rot_a, 'a');
		call_push(stack_a, stack_b, 'a');
		final_adjust(stack_a);
		current_b = (*stack_b);
	}
	while (*stack_b)
		call_push(stack_a, stack_b, 'a');
}

int	calculate_rot_a(t_node **stack_a, int target)
{
	t_node	*temp;
	int		pos_target;

	temp = *stack_a;
	pos_target = 0;
	if (target < find_min_index(stack_a) || target > find_max_index(stack_a))
		return (0);
	while (pos_target < stack_size(stack_a))
	{
		if (temp->index > target && temp->prev->index < target)
			return (pos_target);
		pos_target++;
		temp = temp->next;
	}
	return (0);
}

void	final_adjust(t_node **stack)
{
	int		index_min;
	int		pos;
	int		rotations;

	index_min = find_min_index(stack);
	pos = find_pos(stack, index_min);
	rotations = index_top(stack, pos);
	execute_rotations(stack, NULL, rotations, 'a');
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