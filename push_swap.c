/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:50:37 by tiagalex          #+#    #+#             */
/*   Updated: 2025/03/02 18:26:51 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_node **stack_a, t_node **stack_b)
{
	if (stack_size(stack_a) <= 1)
		return ;
	if (stack_size(stack_a) == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			call_swap(stack_a, stack_b, 'a');
	}
	else if (stack_size(stack_a) == 3)
		mini_sort(stack_a);
	else
		big_sort(stack_a, stack_b);

}

int main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (ft_parsing(&stack_a, argc, argv) || argv[1] == NULL)
	{
		free_stack(&stack_a);
		write(2, "Error!", 6);
		return (1);
	}
	/*
	if (ft_sorted(stack_a))
	{
		free_stack(stack_a);
		return (0);
	}
	*/
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	//free_stack(stack_b);
	return (0);
}