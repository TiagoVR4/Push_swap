/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:50:37 by tiagalex          #+#    #+#             */
/*   Updated: 2025/03/06 15:49:10 by tiagalex         ###   ########.fr       */
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
		medium_sort(stack_a, stack_b);
}

int main(int argc, char **argv)
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
	set_index(&stack_a);
	ft_printf("Antes da ordenacao\n");
	t_node	*first = stack_a;
	while (stack_a)
	{
		ft_printf("Index:%d Value:%d \n", stack_a->index, stack_a->value);
		stack_a = stack_a->next;
		if (stack_a == first)
			break;
	}
	push_swap(&stack_a, &stack_b);
	*first = *stack_a;
	ft_printf("Depois da ordenacao\n");
	while (stack_a)
	{
		ft_printf("Index:%d Value:%d \n", stack_a->index, stack_a->value);
		stack_a = stack_a->next;
		if (stack_a == first)
			break;
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
