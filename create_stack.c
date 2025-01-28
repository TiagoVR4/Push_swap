/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:19:48 by tiagalex          #+#    #+#             */
/*   Updated: 2025/01/28 14:48:12 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node	*new_node(char *str)
{
	static int	i;
	int			n;
	node		*value;

	n = ft_atoi(str);
	value = (node *)malloc(sizeof(node));
	if(!value)
		return (NULL);
	value->value = n;
	value->next = NULL;
	value->index = i++;
	value->prev = NULL;
	return (value);
}

void	add_to_stack(node *stack, node *new)
{
	node	*value;

	value = new_node(new); //incorrect? maybe i dont need to create a new_node because the var I'm giving is already a node or just change node for "char *new"
	if (!stack)
	{
		stack = new;
		return ;
	}
	while (stack->next != '\0')
		stack = stack->next;
	value->prev = stack;
	stack->next = value;
	
}

node	create_stack(node **stack, char **argv)
{
	size_t	i;

	i = 0;
	if (!stack)
		stack == new_node(argv[0]);
	while(argv[i] != '\0')
	{

	}
}