/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:23:57 by tiagalex          #+#    #+#             */
/*   Updated: 2025/03/11 17:58:43 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	turk_sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*current;
	int		current_chunk;
	int		num_chunks;
	int		pos;
	
	current = *stack_a;
	current_chunk = 0;
	num_chunks = (stack_size(stack_a) + 49) / 50;
	pos = 0;
	while (stack_size(stack_a) > 3)
	{
		if (current->chunk == current_chunk)
		{
			sort_b(stack_a, stack_b, pos);
			pos = 0;
			current = *stack_a;
		}
		else
		{
			pos++;
			current = current->next;
		}
			if (current == *stack_a)
		{
				if (count_chunks(stack_a, current_chunk) == 0)
				{
					current_chunk++;
					current = *stack_a;
					pos = 0;
				}
		}
	}
	mini_sort(stack_a);
}

void	sort_b(t_node **stack_a, t_node **stack_b, int pos)
{
	t_node	*temp;
	int		rotations;
	int		rb_count;

	temp = *stack_a;
	rotations = index_top(stack_a, pos);
	rb_count = 0;
}

int		count_chunks(t_node **stack, int current_chunk)
{
	t_node	*current;
	int		count;

	current = *stack;
	count = 0;
	while (1)
	{
		if (current->chunk == current_chunk)
			count++;
		current = current->next;
		if (current == *stack)
			break;
	}
	return (count);
}

