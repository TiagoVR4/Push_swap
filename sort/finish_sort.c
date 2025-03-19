/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagvr <tiagvr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:56:53 by tiagalex          #+#    #+#             */
/*   Updated: 2025/03/19 12:01:14 by tiagvr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	finish_sort(t_node **stack_a, t_node **stack_b)
{
	complete_last_chunk(stack_a, stack_b);
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
		while(current_a->index < target && current_a->next != *stack_a)
		{
			pos++;
			current_a = current_a->next;
		}
		if (pos == stack_size(stack_a))
			pos--;
		execute_rotations(stack_a, stack_b, pos);
		call_push(stack_a, stack_b, 'a');
		current_b = *stack_b;
	}
}
