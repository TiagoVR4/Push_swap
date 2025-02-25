/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:44:02 by tiagalex          #+#    #+#             */
/*   Updated: 2025/02/25 11:21:02 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	int		temp_index;

	if (!*stack || !(*stack)->next || (*stack)->next == *stack)
    	return;
	first = *stack;
	second = first->next;
	first->prev->next = second;
	second->next->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	*stack = second;

	temp_index = first->index;
	first->index = second->index;
	second->index = temp_index;
}

/*
int main()
{
    t_node  *stack = NULL;
    
    add_node(&stack, "1");
    add_node(&stack, "2");
    add_node(&stack, "3");
    add_node(&stack, "4");
    
    t_node	*first = stack;
    ft_printf("Before the Swap:\n");
	ft_printf("Value: %d\n Index: %d\n Chunk: %d\n", stack->value, stack->index, stack->chunk);
	stack = stack->next; 
	while (stack != first)
	{
		ft_printf("Value: %d\n Index: %d\n Chunk: %d\n", stack->value, stack->index, stack->chunk);
		stack = stack->next;
	}

    swap(&stack);

    t_node	*new_first = stack;
    ft_printf("After the Swap: \n");
	ft_printf("Value: %d\n Index: %d\n Chunk: %d\n", stack->value, stack->index, stack->chunk);
	stack = stack->next; 
	while (stack != new_first)
	{
		ft_printf("Value: %d\n Index: %d\n Chunk: %d\n", stack->value, stack->index, stack->chunk);
		stack = stack->next;
	}
}*/