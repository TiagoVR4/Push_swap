/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:50:37 by tiagalex          #+#    #+#             */
/*   Updated: 2025/03/28 15:06:49 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_node **stack_a, t_node **stack_b)
{
	if (stack_size(stack_a) == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			call_swap(stack_a, stack_b, 'a');
	}
	else if (stack_size(stack_a) == 3)
		mini_sort(stack_a);
	else if (stack_size(stack_a) == 4 || stack_size(stack_a) == 5)
	{
		medium_sort(stack_a, stack_b);
		if (sorted(stack_a) == 0)
			mini_sort(stack_a);
		if (stack_size(stack_b) == 2)
			call_push(stack_a, stack_b, 'a');
		call_push(stack_a, stack_b, 'a');
	}
	else
	{
		turk_sort(stack_a, stack_b);
		if (sorted(stack_a) == 0)
			mini_sort(stack_a);
		adjust_b(stack_b);
		finish_sort(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit (1);
	if (ft_parsing(&stack_a, argc, argv) || argv[1] == NULL)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	if (sorted(&stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	assign_index(&stack_a);
	assign_chunk(&stack_a);
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
