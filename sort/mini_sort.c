/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:22:00 by tiagalex          #+#    #+#             */
/*   Updated: 2025/03/27 16:45:06 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	mini_sort(t_node **stack)
{
	t_node	*first;

	first = *stack;
	if (first->index < first->next->index)
	{
		if (first->index > first->prev->index)
			call_rrotate(stack, NULL, 'a');
		else
		{
			call_swap(stack, NULL, 'a');
			call_rotate(stack, NULL, 'a');
		}
	}
	else
	{
		if (first->index < first->prev->index)
			call_swap(stack, NULL, 'a');
		else if (first->next->index > first->prev->index)
		{
			call_swap(stack, NULL, 'a');
			call_rrotate(stack, NULL, 'a');
		}
		else
			call_rotate(stack, NULL, 'a');
	}
}