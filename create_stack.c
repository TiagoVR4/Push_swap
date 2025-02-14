/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:19:48 by tiagalex          #+#    #+#             */
/*   Updated: 2025/02/14 18:22:33 by tiagalex         ###   ########.fr       */
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
	t_node	*current;
	t_node	*next_node;
	t_node	*start;
	int		flag;

	if (!stack || !*stack)
		return ;

	current = *stack;
	start = *stack;
	flag = 0;
	while (flag == 0)
	{
		next_node = current->next;
		free(current);
		if (next_node == start)
			flag = 1;
		current = next_node;
	}
	*stack = NULL;
}

int main()
{
	
	t_node	*stack = NULL;
	
	add_node(&stack, "3");
	add_node(&stack, "9");
	add_node(&stack, "6");
	add_node(&stack, "2");
	
	t_node	*first = stack;
	ft_printf("Value: %d\n Index: %d\n Chunk: %d\n", stack->value, stack->index, stack->chunk);
	stack = stack->next; 
	while (stack != first)
	{
		ft_printf("Value: %d\n Index: %d\n Chunk: %d\n", stack->value, stack->index, stack->chunk);
		stack = stack->next;
	}

	//test free_stack
	free_stack(&first);
	return (0);
}