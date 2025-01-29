/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:19:48 by tiagalex          #+#    #+#             */
/*   Updated: 2025/01/29 15:06:54 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*new_node(char *str)
{
	static int	i;
	int			n;
	t_lst		*value;

	n = ft_atoi(str);
	value = (t_lst *)malloc(sizeof(t_lst));
	if(!value)
		return (NULL);
	value->value = n;
	value->next = NULL;
	value->index = i++;
	value->prev = NULL;
	return (value);
}
/* 
void	add_to_stack(t_lst *stack, char *new)
{
	t_lst	*value;

	value = new_node(new);
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

t_lst	create_stack(t_lst **stack, char **argv)
{
	size_t	i;

	i = 0;
	if (!stack)
		stack == new_node(argv[0]);
	while(argv[i] != '\0')
	{

	}
} */

int	main()
{
	char *str = "2";
	t_lst	*algo = new_node(str);

	printf ("%d", algo->value);
	return (0);
}