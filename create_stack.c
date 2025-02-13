/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:19:48 by tiagalex          #+#    #+#             */
/*   Updated: 2025/02/13 20:16:33 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(char *str)
{
	int		n;
	t_node	*node;

	if (!str)
		return (NULL);
	n = ft_atoi(str);
	node = (t_node *)malloc(sizeof(t_node));
	if(!node)
		return (NULL);
	node->value = n;
	node->index = -1;
	node->chunk = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_node(t_node **stack, char *new)
{
	t_node	*node;

	node = new_node(new);
	if (!node)
		return ;
	if (!*stack)
	{
		*stack = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		t_node *last;
		
		last = (*stack)->prev;
		last->next = node;
		node->prev = last;
		node->next = *stack;
		(*stack)->prev = node;
	}
}
//double free or corruption! More than 1000 errors 
void	free_stack(t_node **stack)
{
	if (!stack)
		return ;

	t_node	*current = *stack;
	t_node	*next;
	t_node	*first = current;
	current = current->next;
	free(current->prev);
	while (current != first)
	{
		next = (*stack)->next;
		free(stack);
		(*stack) = next;
	}
	free(stack);
	free(current);
	free(next);
	free(first);
}

int main()
{
	
	t_node	*stack = NULL;
	
	add_node(&stack, "3");
	add_node(&stack, "9");
	add_node(&stack, "6");
	add_node(&stack, "2");
	
	t_node	*first = stack;
	ft_printf("value: %d\n Index: %d\n Chunk: %d\n", stack->value, stack->index, stack->chunk);
	stack = stack->next; 
	while (stack != first)
	{
		ft_printf("value: %d\n Index: %d\n Chunk: %d\n", stack->value, stack->index, stack->chunk);
		stack = stack->next;
	}

	//test free_stack
	free_stack(&stack);
	if (!stack)
	{
		ft_printf("Is clean!");
	}
	else
		ft_printf("still dirty ");
	return (0);
}