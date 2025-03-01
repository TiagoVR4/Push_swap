/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:19:48 by tiagalex          #+#    #+#             */
/*   Updated: 2025/02/27 15:37:58 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(char *str)
{
	t_node	*node;
	int		n;

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
void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*next_node;
	t_node	*start;

	if (!stack || !*stack)
		return ;

	current = *stack;
	start = *stack;
	next_node = current->next;
	while (current != NULL)
	{
		free(current);
		if (next_node == start)
			current = NULL;
		else
		{
			current = next_node;
			next_node = current->next;
		}
	}
	*stack = NULL;
}

int	stack_size(t_node **stack)
{
	t_node	*current;
	t_node	*start;
	int		count;

	if (!stack || !*stack)
		return ;

	current = *stack;
	start = *stack;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
		if (current == start)
			current = NULL;
	}
	return (count);
}
