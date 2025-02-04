/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:19:48 by tiagalex          #+#    #+#             */
/*   Updated: 2025/02/04 13:06:04 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_node(char *str)
{
	static int	i;
	int			n;
	t_list		*value;

	n = ft_atoi(str);
	value = (t_list *)malloc(sizeof(t_list));
	if(!value)
		return (NULL);
	value->value = n;
	value->next = NULL;
	value->index = i++;
	value->prev = NULL;
	return (value);
}

void	add_to_stack(t_list *stack, char *new)
{
	t_list	*val;

	val = new_node(new);
	if (!stack)
	{
		stack = val;
		return ;
	}
	while (stack->next != NULL)
		stack = stack->next;
	val->prev = stack;
	stack->next = val;
}
/* 
t_list	create_stack(t_list **stack, char **argv)
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
	t_list	*something = new_node(str);

	printf ("%d", something->value);
	return (0);
} */

int main() // test for add_to_stack
{
	char *str = "22";
	t_list	*a = new_node(str);
	add_to_stack(a, "54");

	printf("value: %d\n", a->value);
	printf("next: %s\n", (char *)a->next);
	printf("prev: %s\n", (char *)a->prev);
	printf("index: %d\n", a->index);
	return (0);
}