/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:53:44 by tiagalex          #+#    #+#             */
/*   Updated: 2025/03/26 13:53:09 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	index_top(t_node **stack, int pos)
{
	int	count;

	count = 0;
	if (pos <= stack_size(stack) / 2)
		count = pos;
	else
		count = -(stack_size(stack) - pos);
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
		if (current->chunk >= num_chunks)
			current->chunk = num_chunks - 1;
		current = current->next;
		if (current == *stack)
			break ;
	}
}

int	find_max_index(t_node **stack)
{
	t_node	*current;
	int		max_index;
	int		flag;

	current = *stack;
	max_index = current->index;
	flag = 1;
	while (flag || current != *stack)
	{
		flag = 0;
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (max_index);
}

int	find_pos(t_node **stack, int target_index)
{
	t_node	*current;
	int		pos;
	int		flag;

	current = *stack;
	pos = 0;
	flag = 1;
	while (flag || current != *stack)
	{
		flag = 0;
		if (current->index == target_index)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

void	adjust_b(t_node **stack)
{
	int		index_max;
	int		pos;
	int		rotations;

	index_max = find_max_index(stack);
	pos = find_pos(stack, index_max);
	rotations = index_top(stack, pos);
	execute_rotations(NULL, stack, rotations, 'b');
}
// delete when is over!!!!
/* void	print_stack(t_node *stack, char *stack_name)
{
	t_node	*current;

	if (!stack)
	{
		ft_printf("Stack %s is empty.\n", stack_name);
		return;
	}
	ft_printf("Stack %s:\n", stack_name);
	current = stack;
	while (1)
	{
		ft_printf("Index: %d, Value: %d, Chunk: %d\n", current->index, current->value, current->chunk);
		current = current->next;
		if (current == stack)
			break;
	}
} */