/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:56:53 by tiagalex          #+#    #+#             */
/*   Updated: 2025/03/19 17:31:35 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	finish_sort(t_node **stack_a, t_node **stack_b)
{
	int	pos;
	int	rot;

	pos = find_pos(stack_b, find_max_index(stack_b));
	rot = index_top(stack_b, pos);
	while (*stack_b)
	{
		if (rot > 0)
		{
			while (rot > 0)
			{
				call_rotate(NULL, stack_b, 'b');
				rot--;
			}
		}
		else
		{
			while (rot < 0)
			{
				call_rrotate(NULL, stack_b, 'b');
				rot++;
			}
		}
		call_push(stack_a, stack_b, 'a');
	}
}
