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
