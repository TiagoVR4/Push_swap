/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:19:48 by tiagalex          #+#    #+#             */
/*   Updated: 2025/02/11 13:12:37 by tiagalex         ###   ########.fr       */
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
/* 
t_node	create_stack(t_node **stack, char **argv)
{
	size_t	i;

	i = 0;
	if (!stack)
		stack == new_node(argv[0]);
	while(argv[i] != '\0')
	{

	}
} */
/* 
int	main() // test for new_node
{
	char *str = "2";
	t_node	*something = new_node(str);

	printf ("%d", something->value);
	return (0);
} */

// test for add_node
int main()
{
	char *str = "22";
	t_node	*a = new_node(str);
	add_node(&a, "54");

	printf("value: %d\n", a->value);
	printf("next: %s\n", (char *)a->next);
	printf("prev: %s\n", (char *)a->prev);
	printf("index: %d\n", a->index);
	return (0);
}