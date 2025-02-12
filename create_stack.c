/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:19:48 by tiagalex          #+#    #+#             */
/*   Updated: 2025/02/12 14:13:30 by tiagalex         ###   ########.fr       */
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
		t_node *last = (*stack)->prev;
		last->next = node;
		node->prev = last;
		node->next = *stack;
		(*stack)->prev = node;
	}
}
void	free_stack(t_node **stack)
{
	if (!stack)
		return ;

	t_node	*current = *stack;
	t_node	*next;
	
	while (stack != NULL)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
	

}

// test for add_node
int main()
{
	
	t_node	*stack = NULL;
	t_node	*a = stack;
	
	add_node(&a, "3");
	add_node(&a, "9");
	add_node(&a, "6");
	add_node(&a, "2");
	add_node(&a, NULL);
	
	while (a->next != NULL)
	{
		ft_printf("value: %d\n Index: %d\n Chunk: %d\n", a->value, a->index, a->chunk);
		a = a->next;
	}
	return (0);
}