/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:42:06 by tiagalex          #+#    #+#             */
/*   Updated: 2025/02/27 18:02:12 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parsing(t_node **stack_a, int argc, char **argv)
{
	int	i;
	char	**array;

	i = 0;
	array = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2 && contains_space(argv[i]))
	{
		array = ft_split(argv[1], ' ');
	}
	else
	{
		array = argv;
		i = 1;
	}
	while (array[i])
	{
		if 
	}
	
}

int	contains_space(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

int	invalid_number(char *str)
{
	int		i;
	long	n;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	n = ft_atol(str);
	if (n > INT_MAX || n < INT_MIN)
		return (1);
	return (0);
}

int	duplicate(t_node **stack)
{
	t_node *current;
	t_node *next_node;
	
	if (!(*stack) || (*stack)->next == *stack)
		return (0);
	current = *stack;
	while (current->next != *stack)
	{
		next_node = current->next;
		while (next_node != *stack)
		{
			if (current->value == next_node->value)
				return (1);
			next_node = next_node->next;
		}
		current = current->next;
	}
	return (0);
}
