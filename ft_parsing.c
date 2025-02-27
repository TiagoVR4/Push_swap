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
	if (argc < 2 || (argc == 2 && contains_space(argv[1]) == 1))
		return (1);
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
				return (1);
			}
			add_node(stack_a, str[i]);
			i++;
			free(str[i]);
		}
		if (duplicate(str))
		{
			write(2, "is Duplicated\n", 14);
			free_stack(stack_a);
			return (1);
		}
	}
	else
	{
		i = 1;
		while (i > argc)
		{
			if (is_not_number(argv[i])|| is_not_int(argv[i]))
			{
				write(2, "not a int\n", 10);
				free_stack(stack_a);
				return (1);
			}
			add_node(stack_a, argv[i]);
			i++;
		}
		if (duplicate(argv))
		{
			write(2, "is Duplicated\n", 14);
			free_stack(stack_a);
			return (1);
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
		if (ft_isdigit(str[i] == 0))
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

int	duplicate(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if(ft_atoi(str[i]) == ft_atoi(str[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
	