/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:23:57 by tiagalex          #+#    #+#             */
/*   Updated: 2025/03/19 17:15:53 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	turk_sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*current;
	int		current_chunk;
	int		pos;
	int		target;
	
	current = *stack_a;
	target = 0;
	current_chunk = 0;
	pos = 0;
	while (stack_size(stack_a) > 3)
	{
		ft_printf("Processing chunk %d\n", current_chunk); // log
		print_stack(*stack_a, "A"); // log
		print_stack(*stack_b, "B"); // log
		if (current->chunk == current_chunk)
		{
			target = current->index;
			printf("Pushing element with index %d (pos: %d) to stack_b\n", target, pos); // log
			sort_b(stack_a, stack_b, pos, target);
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
					ft_printf("Finished chunk %d\n", current_chunk); // Log
					current_chunk++;
					current = *stack_a;
					pos = 0;
				}
		}
	}
	print_stack(*stack_a, "A before mini_sort"); // log
	mini_sort(stack_a);
	print_stack(*stack_b, "B before finish_sort"); // log
	finish_sort(stack_a, stack_b);
	print_stack(*stack_a, "A after finish_sort"); // log
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
// delete when is over!!!!
void	print_stack(t_node *stack, char *stack_name)
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
	flag = 0;
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