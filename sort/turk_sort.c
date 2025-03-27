/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagvr <tiagvr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:23:57 by tiagalex          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/27 11:06:48 by tiagvr           ###   ########.fr       */
=======
/*   Updated: 2025/03/26 18:58:05 by tiagalex         ###   ########.fr       */
>>>>>>> parent of b423f46 (fix sort_b, still need optimize sorting_a)
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
		// ft_printf("Current chunk: %d\n", current_chunk); // log
		// print_stack(*stack_a, "Stack A"); // log
		// print_stack(*stack_b, "Stack B"); // log

		if (current->chunk == current_chunk)
		{
			target = current->index;
<<<<<<< HEAD
			ft_printf("Sorting: pos = %d, index target = %d\n", pos, target); // log
=======
			// ft_printf("Sorting: pos=%d, target=%d\n", pos, target); // log
>>>>>>> parent of b423f46 (fix sort_b, still need optimize sorting_a)
			sort_b(stack_a, stack_b, pos, target);
			pos = 0;
			current = *stack_a;
		}
		else
		{
			pos++;
			current = current->next;
		}
		update_chunk(stack_a, &current, &current_chunk, &pos);
<<<<<<< HEAD
	  	printf("Updated chunk: %d, pos: %d\n", current_chunk, pos); // log
=======
	  //  printf("Updated chunk: %d, pos: %d\n", current_chunk, pos); // log
>>>>>>> parent of b423f46 (fix sort_b, still need optimize sorting_a)
	}
}

int	count_chunks(t_node **stack, int *current_chunk)
{
	t_node	*current;
	int		count;

	current = *stack;
	count = 0;
	while (1)
	{
		if (current->chunk == *current_chunk)
			count++;
		current = current->next;
		if (current == *stack)
			break ;
	}
	return (count);
}

void	update_chunk(t_node **stack_a, t_node **current,
	int *current_chunk, int *pos)
{
	if (*current == *stack_a)
	{
		if (count_chunks(stack_a, current_chunk) == 0)
		{
			(*current_chunk)++;
			*current = *stack_a;
			*pos = 0;
		}
	}
}
