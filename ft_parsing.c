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
	
	i = 0;
	if (argc < 2)
		return (0);
	else if (argc == 2 && contains_space(argv[1]) == 0)
	{
		char	**str;

		str = ft_split(argv[1], ' ');
		while (str[i])
		{
			if (is_not_number(str[i]) || is_not_int(str[i]))
			{
				write(2, "not a int\n", 10);
				free_stack(stack_a);
				free(str);
				return (1);
			}
			add_node(stack_a, str[i]);
			if (duplicate(stack_a))
			{
				write(2, "is Duplicated\n", 14);
				free_stack(stack_a);
				free(str);
				return (1);
			}
			i++;
		}
		free(str);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (is_not_number(argv[i])|| is_not_int(argv[i]))
			{
				write(2, "not a int\n", 10);
				free_stack(stack_a);
				return (1);
			}
			add_node(stack_a, argv[i]);
			if (duplicate(stack_a))
			{
				write(2, "is Duplicated\n", 14);
				free_stack(stack_a);
				return (1);
			}
			i++;
		}
	}
	return (0);
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

int	is_not_number(char	*str)
{
	int	i;
	
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{	
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_not_int(char *str)
{
	long 	n;

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
