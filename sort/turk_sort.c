/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:23:57 by tiagalex          #+#    #+#             */
/*   Updated: 2025/03/06 18:49:08 by coder            ###   ########.fr       */
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
			index_top(stack_a, stack_b, pos);
			call_push(stack_a, stack_b, 'b');
			sort_b(stack_b);
			pos = -1;
			current = (*stack_a)->prev;
		}
		pos++;
		current = current->next;
		if (count_chunks(stack_a, current_chunk) == 0)
			current_chunk++;
	}
	mini_sort(stack_a);
}
void	sort_b(t_node **stack)
{
	t_node	*current;

	current = *stack;
	if
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
		if (current == *stack)
			break;
		current = current->next;
	}
	return (count);
}

void	assign_chunk(t_node **stack)
{
	int		n;
	int		num_chunks;
	int		chunk_size;
	t_node	*current;

	n = stack_size(stack);
	num_chunks = ((n + 49) / 50);
	if (num_chunks < 2)
		num_chunks = 2;
	chunk_size = n / num_chunks;
	current = *stack;
	while (current)
	{
		current->chunk = current->index / chunk_size;
		if(current->chunk >= num_chunks)
			current->chunk = num_chunks - 1;
		current = current->next;
		if (current == *stack)
			break;
	}
}
