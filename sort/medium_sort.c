/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:57:14 by tiagalex          #+#    #+#             */
/*   Updated: 2025/03/06 14:18:06 by tiagalex         ###   ########.fr       */
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
			index_top(stack_a, stack_b, pos);
			call_push(stack_a, stack_b, 'b');
			i++;
			pos = -1;
			current = (*stack_a)->prev;
		}
		current = current->next;
		pos++;
	}
	mini_sort(stack_a);
	if(stack_size(*stack_b) == 2)
		call_push(stack_a, stack_b, 'a');
	call_push(stack_a, stack_b, 'a');
}
void	index_top(t_node **stack_a, t_node **stack_b, int pos)
{
	if (pos <= stack_size(*stack_a) / 2)
	{
		while (pos > 0)
		{
			call_rotate(*stack_a, stack_b, 'a');
			pos--;
		}
	}
	else
	{
		pos = stack_size(*stack_a) - pos;
		while (pos > 0)
		{
			call_rrotate(stack_a, stack_b, 'a');
			pos--;
		}
	}
}
