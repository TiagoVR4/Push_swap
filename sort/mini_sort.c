/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:22:00 by tiagalex          #+#    #+#             */
/*   Updated: 2025/03/03 16:44:45 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	mini_sort(t_node **stack)
{
	t_node	*first;

	first = *stack;
	if (first->value < first->next->value)
	{
		if (first->value > first->prev->value)
			call_rrotate(stack, NULL, 'a');
		else
		{
			call_swap(stack, NULL, 'a');
			call_rotate(stack, NULL, 'a');
		}
	}
	else
	{
		if (first->value < first->prev->value)
			call_swap(stack, NULL, 'a');
		else if (first->next->value > first->prev->value)
		{
			call_swap(stack, NULL, 'a');
			call_rrotate(stack, NULL, 'a');
		}
		else
			call_rotate(stack, NULL, 'a');
	}
}
