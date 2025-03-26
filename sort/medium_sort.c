/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:57:14 by tiagalex          #+#    #+#             */
/*   Updated: 2025/03/26 12:04:02 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	medium_sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*current;
	int		i;
	int		pos;

	current = *stack_a;
	i = 0;
	pos = 0;
	while (stack_size(stack_a) > 3)
	{
		if (current->index == i)
		{
			execute_rotations(stack_a, stack_b, pos, 'a');
			call_push(stack_a, stack_b, 'b');
			i++;
			pos = -1;
			current = (*stack_a)->prev;
		}
		current = current->next;
		pos++;
	}
	mini_sort(stack_a);
	if (stack_size(stack_b) == 2)
		call_push(stack_a, stack_b, 'a');
	call_push(stack_a, stack_b, 'a');
}

void	execute_rotations(t_node **stack_a, t_node **stack_b,
	int pos, char flag)
{
	int	count;

	count = index_top(stack_a, pos);
	if (count > 0)
	{
		while (count > 0)
		{
			call_rotate(stack_a, stack_b, flag);
			count--;
		}
	}
	else
	{
		while (count < 0)
		{
			call_rrotate(stack_a, stack_b, flag);
			count++;
		}
	}
}
