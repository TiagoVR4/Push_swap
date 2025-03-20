/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:23:57 by tiagalex          #+#    #+#             */
/*   Updated: 2025/03/20 16:15:59 by tiagalex         ###   ########.fr       */
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
	print_stack(*stack_a, "A after mini_sort"); // log
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
